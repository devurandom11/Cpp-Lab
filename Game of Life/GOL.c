// Include the necessary libraries
#include <getopt.h>  // For command-line option parsing
#include <math.h>    // For mathematical operations
#include <signal.h>  // For signal handling
#include <stdbool.h> // For boolean type
#include <stdio.h>   // For input/output operations
#include <stdlib.h> // For miscellaneous functions like random number generation
#include <string.h> // For string operations
#include <time.h>   // For time-related functions
#include <unistd.h> // For sleep function and getopt
#ifdef _OPENMP
#include <omp.h> // For OpenMP multithreading
#endif

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define the width and height of the grid
#define MAX_WIDTH 180
#define MAX_HEIGHT 80
#define DEFAULT_WIDTH 80
#define DEFAULT_HEIGHT 40

// Visual representation constants (expanded palette)
#define LEVEL_CHARS " .:;+=oxOX@#"
#define LEVEL_COUNT (sizeof(LEVEL_CHARS) / sizeof(LEVEL_CHARS[0]) - 1)

// Simulation constants - adjusted for more interesting patterns
#define DEFAULT_RADIUS 5.0f
#define ALPHA 0.028f
#define B1 0.278f
#define B2 0.365f
#define D1 0.267f
#define D2 0.445f
#define DT 0.005f // Increased timestep for faster evolution
#define SIGMA_MIDPOINT 0.5f
#define SIGMA_SCALE 4.0f
#define INNER_RADIUS_FACTOR (1.0f / 3.0f)

// Display settings
#define USE_COLOR true
#define DEFAULT_DELAY_MS 10 // Reduced delay between frames
#define DEFAULT_DISPLAY_INTERVAL 1
#define DEFAULT_NUM_THREADS 4 // Default number of threads to use

// Program state flag
static volatile bool running = true;
static unsigned long generation = 0;

// Configuration structure
typedef struct {
  int width;
  int height;
  float radius;
  int delay_ms;
  int display_interval;
  int pattern;
  int num_threads;
} Config;

// Game state structure
typedef struct {
  float **grid;
  float **grid_diff;
  int width;
  int height;
} GameState;

// Function prototypes
float rand_float(void);
void init_game(GameState *state, int pattern_type);
void display_grid(const GameState *state);
int euclidean_mod(int a, int b);
void clamp(float *x, float low, float high);
float sigma1(float x, float a);
float sigma2(float x, float a, float b);
float sigmaM(float x, float y, float m);
float transition(float n, float m);
void compute_grid_diff(GameState *state, float radius);
void signal_handler(int signal);
void init_patterns(GameState *state, int pattern_type);
void display_simulation_info(unsigned long gen, const Config *config);
void display_usage(const char *program_name);
void allocate_game_state(GameState *state, int width, int height);
void free_game_state(GameState *state);
void update_grid(GameState *state);

// Function to generate a random float between 0 and 1
float rand_float(void) { return (float)rand() / (float)RAND_MAX; }

// Signal handler to allow clean exit
void signal_handler(int signal) {
  (void)signal; // Unused parameter
  running = false;
}

// Allocate memory for game state
void allocate_game_state(GameState *state, int width, int height) {
  if (!state)
    return;

  state->width = width;
  state->height = height;

  // Allocate grid
  state->grid = (float **)malloc(height * sizeof(float *));
  state->grid_diff = (float **)malloc(height * sizeof(float *));

  for (int y = 0; y < height; y++) {
    state->grid[y] = (float *)calloc(width, sizeof(float));
    state->grid_diff[y] = (float *)calloc(width, sizeof(float));
  }
}

// Free memory for game state
void free_game_state(GameState *state) {
  if (!state)
    return;

  for (int y = 0; y < state->height; y++) {
    free(state->grid[y]);
    free(state->grid_diff[y]);
  }

  free(state->grid);
  free(state->grid_diff);

  state->grid = NULL;
  state->grid_diff = NULL;
}

// Function to initialize the grid with various patterns
void init_game(GameState *state, int pattern_type) {
  if (!state) {
    fprintf(stderr, "Error: Null state pointer in init_game\n");
    return;
  }

  // Initialize grids to zero
  for (int y = 0; y < state->height; y++) {
    for (int x = 0; x < state->width; x++) {
      state->grid[y][x] = 0.0f;
      state->grid_diff[y][x] = 0.0f;
    }
  }

  init_patterns(state, pattern_type);
}

// Initialize with different pattern types
void init_patterns(GameState *state, int pattern_type) {
  int width = state->width;
  int height = state->height;

  switch (pattern_type) {
  case 0: { // Random center patch
    size_t w = width / 2;
    size_t h = height / 2;
    size_t start_x = width / 2 - w / 2;
    size_t start_y = height / 2 - h / 2;

    for (size_t dy = 0; dy < h; dy++) {
      for (size_t dx = 0; dx < w; dx++) {
        size_t x = start_x + dx;
        size_t y = start_y + dy;
        if (rand_float() > 0.75f) {
          state->grid[y][x] = rand_float() * 0.8f + 0.2f;
        }
      }
    }
    break;
  }
  case 1: { // Symmetrical pattern
    size_t w = width / 3;
    size_t h = height / 3;
    size_t center_x = width / 2;
    size_t center_y = height / 2;

    // Generate a quarter and mirror it
    for (size_t dy = 0; dy < h / 2; dy++) {
      for (size_t dx = 0; dx < w / 2; dx++) {
        if (rand_float() > 0.6f) {
          float value = rand_float() * 0.6f + 0.4f;

          // Apply to all four quadrants symmetrically
          state->grid[center_y + dy][center_x + dx] = value;
          if (center_x > dx)
            state->grid[center_y + dy][center_x - dx - 1] = value;
          if (center_y > dy) {
            state->grid[center_y - dy - 1][center_x + dx] = value;
            if (center_x > dx)
              state->grid[center_y - dy - 1][center_x - dx - 1] = value;
          }
        }
      }
    }
    break;
  }
  case 2: { // Organic spiral
    size_t center_x = width / 2;
    size_t center_y = height / 2;
    float max_radius = fminf(width, height) / 3.0f;

    for (float angle = 0; angle < 12.0f * M_PI; angle += 0.04f) {
      float radius = (angle / (12.0f * M_PI)) * max_radius;
      int x = center_x + (int)(radius * cosf(angle));
      int y = center_y + (int)(radius * sinf(angle));

      if (x >= 0 && x < width && y >= 0 && y < height) {
        state->grid[y][x] = fmodf(angle, 1.0f) * 0.7f + 0.3f;

        // Add some thickness to the spiral (optimized)
        for (int dy = -1; dy <= 1; dy += 2) {
          for (int dx = -1; dx <= 1; dx += 2) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
              state->grid[ny][nx] =
                  fmaxf(state->grid[ny][nx], state->grid[y][x] * 0.8f);
            }
          }
        }
      }
    }
    break;
  }
  case 3: { // Complex grid pattern
    for (size_t y = 0; y < height; y++) {
      for (size_t x = 0; x < width; x++) {
        if ((x % 8 == 0 || y % 8 == 0) && rand_float() > 0.3f) {
          state->grid[y][x] = 0.9f;
        } else if ((x + y) % 16 == 0) {
          state->grid[y][x] = 0.7f;

          // Add some small clusters (simplified)
          for (int dy = -1; dy <= 1; dy += 2) {
            for (int dx = -1; dx <= 1; dx += 2) {
              int nx = (x + dx + width) % width;
              int ny = (y + dy + height) % height;
              state->grid[ny][nx] = 0.6f;
            }
          }
        }
      }
    }
    break;
  }
  case 4: { // Wave interference pattern
    float scale = 0.2f;
    float quarter_width = width / 4.0f;
    float quarter_height = height / 4.0f;
    float three_quarter_width = 3 * width / 4.0f;
    float three_quarter_height = 3 * height / 4.0f;

    for (size_t y = 0; y < height; y++) {
      for (size_t x = 0; x < width; x++) {
        float center_dist1 =
            sqrtf(powf(x - quarter_width, 2) + powf(y - quarter_height, 2));
        float center_dist2 = sqrtf(powf(x - three_quarter_width, 2) +
                                   powf(y - three_quarter_height, 2));
        float center_dist3 = sqrtf(powf(x - three_quarter_width, 2) +
                                   powf(y - quarter_height, 2));
        float center_dist4 = sqrtf(powf(x - quarter_width, 2) +
                                   powf(y - three_quarter_height, 2));

        float wave = sinf(center_dist1 * scale) + sinf(center_dist2 * scale) +
                     sinf(center_dist3 * scale) + sinf(center_dist4 * scale);

        state->grid[y][x] = (wave + 4.0f) / 8.0f;
      }
    }
    break;
  }
  default: { // Sparse random distribution across the entire grid
    for (size_t y = 0; y < height; y++) {
      for (size_t x = 0; x < width; x++) {
        if (rand_float() > 0.92f) {
          state->grid[y][x] = rand_float();
        }
      }
    }
  }
  }
}

// Function to display the grid with color support
void display_grid(const GameState *state) {
  if (!state) {
    fprintf(stderr, "Error: Null state pointer in display_grid\n");
    return;
  }

  // Clear the console
  printf("\033[2J\033[H");

  int width = state->width;
  int height = state->height;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate index safely with bounds checking
      int index = (int)(state->grid[y][x] * (LEVEL_COUNT - 1));
      if (index < 0)
        index = 0;
      if (index >= (int)LEVEL_COUNT)
        index = (int)LEVEL_COUNT - 1;

      char shade = LEVEL_CHARS[index];

      if (USE_COLOR) {
        // Map the cell value to a color (ANSI color codes)
        int color = 31 + (index % 7); // Red(31) to White(37)
        printf("\033[%dm%c\033[0m", color, shade);
      } else {
        printf("%c", shade);
      }
    }
    printf("\n");
  }
}

// Display simulation information
void display_simulation_info(unsigned long gen, const Config *config) {
  printf("Generation: %lu | Size: %dx%d | Pattern: %d | Speed: %d ms | Press "
         "Ctrl+C to exit\n",
         gen, config->width, config->height, config->pattern, config->delay_ms);
}

// Display program usage information
void display_usage(const char *program_name) {
  printf("Usage: %s [OPTION]\n\n", program_name);
  printf("Game of Life Simulation with various starting patterns\n\n");
  printf("Options:\n");
  printf("  -p <number>   Select pattern (0-5, default: 2)\n");
  printf("      0: Random center patch\n");
  printf("      1: Symmetrical pattern\n");
  printf("      2: Organic spiral (default)\n");
  printf("      3: Complex grid pattern\n");
  printf("      4: Wave interference pattern\n");
  printf("      5: Sparse random distribution\n");
  printf("  -w <number>   Set grid width (default: %d, max: %d)\n",
         DEFAULT_WIDTH, MAX_WIDTH);
  printf("  -h <number>   Set grid height (default: %d, max: %d)\n",
         DEFAULT_HEIGHT, MAX_HEIGHT);
  printf("  -r <number>   Set neighborhood radius (default: %.1f)\n",
         DEFAULT_RADIUS);
  printf("  -s <number>   Set simulation speed in ms (default: %d)\n",
         DEFAULT_DELAY_MS);
  printf("  -d <number>   Set display update interval (default: %d)\n",
         DEFAULT_DISPLAY_INTERVAL);
  printf("  -t <number>   Set number of threads (default: %d)\n",
         DEFAULT_NUM_THREADS);
  printf("  -?            Display this help message\n\n");
  printf("Controls:\n");
  printf("  Ctrl+C        Exit the simulation\n");
}

// Function to calculate the Euclidean modulo of two numbers
int euclidean_mod(int a, int b) {
  if (b == 0) {
    fprintf(stderr, "Error: Division by zero in euclidean_mod\n");
    return 0;
  }
  return (a % b + b) % b;
}

// Function to clamp a value between a low and a high value
void clamp(float *x, float low, float high) {
  if (!x) {
    fprintf(stderr, "Error: Null pointer in clamp\n");
    return;
  }
  *x = fminf(fmaxf(*x, low), high);
}

// Function to calculate sigma1
float sigma1(float x, float a) {
  return 1.0f / (1.0f + expf(-(x - a) * SIGMA_SCALE / ALPHA));
}

// Function to calculate sigma2
float sigma2(float x, float a, float b) {
  return sigma1(x, a) * (1.0f - sigma1(x, b));
}

// Function to calculate sigmaM
float sigmaM(float x, float y, float m) {
  return x * (1.0f - sigma1(m, SIGMA_MIDPOINT)) + y * sigma1(m, SIGMA_MIDPOINT);
}

// Function to calculate the transition
float transition(float n, float m) {
  return sigma2(n, sigmaM(B1, D1, m), sigmaM(B2, D2, m));
}

// Function to compute the difference of the grid
void compute_grid_diff(GameState *state, float radius) {
  if (!state) {
    fprintf(stderr, "Error: Null state pointer in compute_grid_diff\n");
    return;
  }

  int width = state->width;
  int height = state->height;
  const float ri = radius * INNER_RADIUS_FACTOR;

  // Pre-calculate squared distances to avoid computation in inner loops
  float radius_squared = radius * radius;
  float ri_squared = ri * ri;

// Set the number of threads
#ifdef _OPENMP
#pragma omp parallel
  {
#pragma omp single
    {
      if (omp_get_thread_num() == 0) {
        // Only print this once at the beginning
        static int first_time = 1;
        if (first_time) {
          printf("Using %d threads for computation\n", omp_get_num_threads());
          first_time = 0;
        }
      }
    }
  }
#endif

  // For large radius values, use a tiled approach to improve cache efficiency
  int tile_size = 16; // Typical L1 cache line size

// Parallelize the outer loops for better performance with large grids
#pragma omp parallel for collapse(2) schedule(dynamic)
  for (int ty = 0; ty < height; ty += tile_size) {
    for (int tx = 0; tx < width; tx += tile_size) {
      // Process each tile
      for (int cy = ty; cy < ty + tile_size && cy < height; cy++) {
        for (int cx = tx; cx < tx + tile_size && cx < width; cx++) {
          float n = 0.0f, N = 0.0f; // Outer circle sum and count
          float m = 0.0f, M = 0.0f; // Inner circle sum and count

          const int radius_int = (int)radius;
          // For large radius values, use a spatial optimization
          if (radius_int > 20) {
            // Sample points instead of checking every point
            int step = radius_int / 20 + 1;
            for (int dy = -radius_int; dy <= radius_int; dy += step) {
              int y = euclidean_mod(cy + dy, height);

              for (int dx = -radius_int; dx <= radius_int; dx += step) {
                float dist = dx * dx + dy * dy;

                if (dist > radius_squared)
                  continue;

                int x = euclidean_mod(cx + dx, width);
                float value = state->grid[y][x];

                // Apply a weight based on step size to account for sampling
                float weight = step * step;

                if (dist <= ri_squared) {
                  m += value * weight;
                  M += weight;
                } else {
                  n += value * weight;
                  N += weight;
                }
              }
            }
          } else {
            // Original approach for smaller radius values
            for (int dy = -radius_int; dy <= radius_int; ++dy) {
              int y = euclidean_mod(cy + dy, height);

              for (int dx = -radius_int; dx <= radius_int; ++dx) {
                float dist = dx * dx + dy * dy;

                if (dist > radius_squared)
                  continue;

                int x = euclidean_mod(cx + dx, width);

                if (dist <= ri_squared) {
                  m += state->grid[y][x];
                  M += 1.0f;
                } else {
                  n += state->grid[y][x];
                  N += 1.0f;
                }
              }
            }
          }

          // Avoid division by zero
          if (M > 0.0f && N > 0.0f) {
            m /= M;
            n /= N;
            float temp = transition(n, m);
            state->grid_diff[cy][cx] = (2.0f * temp) - 1.0f;
          } else {
            state->grid_diff[cy][cx] = 0.0f;
          }
        }
      }
    }
  }
}

// New function to update the grid in parallel
void update_grid(GameState *state) {
  int width = state->width;
  int height = state->height;

#pragma omp parallel for collapse(2)
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      state->grid[y][x] += DT * state->grid_diff[y][x];
      clamp(&state->grid[y][x], 0.0f, 1.0f);
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Set up signal handling for clean exit with Ctrl+C
  signal(SIGINT, signal_handler);

  // Seed random number generator once at program start
  srand((unsigned int)time(NULL));

  // Default configuration
  Config config = {.width = DEFAULT_WIDTH,
                   .height = DEFAULT_HEIGHT,
                   .radius = DEFAULT_RADIUS,
                   .delay_ms = DEFAULT_DELAY_MS,
                   .display_interval = DEFAULT_DISPLAY_INTERVAL,
                   .pattern = 2,
                   .num_threads = DEFAULT_NUM_THREADS};

  // Parse command line arguments
  int opt;
  while ((opt = getopt(argc, argv, "p:w:h:r:s:d:t:?")) != -1) {
    switch (opt) {
    case 'p':
      config.pattern = atoi(optarg);
      if (config.pattern < 0 || config.pattern > 5) {
        fprintf(stderr, "Error: Pattern selection must be between 0 and 5.\n");
        display_usage(argv[0]);
        return EXIT_FAILURE;
      }
      break;
    case 'w':
      config.width = atoi(optarg);
      if (config.width <= 0 || config.width > MAX_WIDTH) {
        fprintf(stderr, "Error: Width must be between 1 and %d.\n", MAX_WIDTH);
        return EXIT_FAILURE;
      }
      break;
    case 'h':
      config.height = atoi(optarg);
      if (config.height <= 0 || config.height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Height must be between 1 and %d.\n",
                MAX_HEIGHT);
        return EXIT_FAILURE;
      }
      break;
    case 'r':
      config.radius = atof(optarg);
      if (config.radius <= 0.0f) {
        fprintf(stderr, "Error: Radius must be positive.\n");
        return EXIT_FAILURE;
      }
      break;
    case 's':
      config.delay_ms = atoi(optarg);
      if (config.delay_ms < 0) {
        fprintf(stderr, "Error: Speed must be non-negative.\n");
        return EXIT_FAILURE;
      }
      break;
    case 'd':
      config.display_interval = atoi(optarg);
      if (config.display_interval <= 0) {
        fprintf(stderr, "Error: Display interval must be positive.\n");
        return EXIT_FAILURE;
      }
      break;
    case 't':
      config.num_threads = atoi(optarg);
      if (config.num_threads <= 0) {
        fprintf(stderr, "Error: Number of threads must be positive.\n");
        return EXIT_FAILURE;
      }
      break;
    case '?':
      display_usage(argv[0]);
      return EXIT_SUCCESS;
    default:
      display_usage(argv[0]);
      return EXIT_FAILURE;
    }
  }

// Set number of OpenMP threads
#ifdef _OPENMP
  omp_set_num_threads(config.num_threads);
  printf("OpenMP enabled with %d threads\n", config.num_threads);
#else
  if (config.num_threads != DEFAULT_NUM_THREADS) {
    printf("Warning: OpenMP not available. Ignoring thread count setting.\n");
  }
#endif

  // Initialize game state with selected pattern
  GameState state;
  allocate_game_state(&state, config.width, config.height);
  init_game(&state, config.pattern);

  printf("Starting Game of Life simulation with pattern %d...\n",
         config.pattern);
  printf("Grid size: %d x %d, Radius: %.1f\n", config.width, config.height,
         config.radius);

  if (config.radius > 20) {
    printf("Large radius detected. Using optimized sampling algorithm.\n");
  }

  sleep(1); // Brief pause to read the message

  // Main game loop
  while (running) {
    // Update generation counter
    generation++;

    // Display grid every N generations to improve performance
    if (generation % config.display_interval == 0) {
      display_grid(&state);
      display_simulation_info(generation, &config);
    }

    // Time the computation for large radius values
    clock_t start_time = 0;
    if (config.radius > 50) {
      start_time = clock();
    }

    compute_grid_diff(&state, config.radius);

    // For large radius, display the computation time
    if (config.radius > 50 && generation % config.display_interval == 0) {
      clock_t end_time = clock();
      double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
      printf("Computation time: %.2f seconds\n", cpu_time_used);
    }

    // Update the grid based on the calculated differences
    update_grid(&state);

    // Add a delay to control simulation speed
    if (config.delay_ms > 0) {
      usleep(config.delay_ms * 1000);
    }
  }

  printf("\nExiting Game of Life simulation after %lu generations.\n",
         generation);

  // Free allocated memory
  free_game_state(&state);

  return EXIT_SUCCESS;
}
