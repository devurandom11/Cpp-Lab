// Include the necessary libraries
#include <math.h>    // For mathematical operations
#include <stdio.h>   // For input/output operations
#include <stdlib.h>  // For miscellaneous functions like random number generation
#include <time.h>    // For time-related functions

// Define the width and height of the grid
#define WIDTH 50
#define HEIGHT 50

// Define the characters to be used for displaying the grid
char level[] = ".-=coaA#@ ";

// Calculate the number of different characters
#define LEVEL_COUNT (sizeof(level) / sizeof(level[0]) - 1)

// Initialize the grid and the grid difference arrays
float grid[HEIGHT][WIDTH] = {0};
float grid_diff[HEIGHT][WIDTH] = {0};

// Define some constants
float ra = 5.0f;
float alpha = 0.028f;
float b1 = 0.278f, b2 = 0.365f;
float d1 = .267f, d2 = .445f;
float dt = 0.0061f;

// Function to generate a random float between 0 and 1
float rand_float(void) { return (float)rand() / (float)RAND_MAX; }

// Function to initialize the grid with random values
void make_grid(void) {
  srand(time(0));  // Seed the random number generator with the current time
  size_t w = WIDTH / 3;   // Calculate the width of the area to be filled
  size_t h = HEIGHT / 3;  // Calculate the height of the area to be filled
  for (size_t dy = 0; dy < h; dy++) {
    for (size_t dx = 0; dx < w; dx++) {
      size_t x =
          dx + WIDTH / 2 - w / 2;  // Calculate the x-coordinate of the cell
      size_t y =
          dy + HEIGHT / 2 - h / 2;  // Calculate the y-coordinate of the cell
      grid[y][x] = rand_float();    // Fill the cell with a random value
    }
  }
}

// Function to display the grid
void display_grid(float grid[HEIGHT][WIDTH]) {
  printf("\033[2J\033[H");  // Clear the console
  for (size_t y = 0; y < HEIGHT; y++) {
    for (size_t x = 0; x < WIDTH; x++) {
      char shade =
          level[(int)(grid[y][x] *
                      (LEVEL_COUNT - 1))];  // Calculate the character to be
                                            // displayed based on the cell value
      printf("%c%c", shade, shade);         // Print the character
    }
    printf("\n");  // Print a newline at the end of each row
  }
}

// Function to calculate the Euclidean modulo of two numbers
int euclidean_mod(int a, int b) { return (a % b + b) % b; }

// Function to clamp a value between a low and a high value
void clamp(float *x, float low, float high) {
  *x = fminf(fmaxf(*x, low), high);
}

// Function to calculate sigma1
float sigma1(float x, float a) {
  return 1.0f / (1 + expf(-(x - a) * 4.0 / alpha));
}

// Function to calculate sigma2
float sigma2(float x, float a, float b) {
  return sigma1(x, a) * (1 - sigma1(x, b));
}

// Function to calculate sigmaM
float sigmaM(float x, float y, float m) {
  return x * (1 - sigma1(m, 0.5)) + y * sigma1(m, 0.5);
}

// Function to calculate the transition
float transition(float n, float m) {
  return sigma2(n, sigmaM(b1, d1, m), sigmaM(b2, d2, m));
}

// Function to compute the difference of the grid
void compute_grid_diff(void) {
  float ri = ra / 3;  // Calculate the radius of the inner circle
  for (int cy = 0; cy < HEIGHT; ++cy) {
    for (int cx = 0; cx < WIDTH; ++cx) {
      float n = 0.0f,
            N = 0.0f;  // Initialize the sum and count of the outer circle
      float m = 0.0f,
            M = 0.0f;  // Initialize the sum and count of the inner circle
      for (int dy = -(ra - 1); dy <= (ra - 1); ++dy) {
        for (int dx = -(ra - 1); dx <= (ra - 1); ++dx) {
          int x = euclidean_mod(
              cx + dx, WIDTH);  // Calculate the x-coordinate of the cell
          int y = euclidean_mod(
              cy + dy, HEIGHT);  // Calculate the y-coordinate of the cell
          float dist =
              dx * dx +
              dy * dy;  // Calculate the distance from the center of the circle
          if (dist <= ri * ri) {  // If the cell is in the inner circle
            m += grid[y]
                     [x];  // Add the cell value to the sum of the inner circle
            M += 1;        // Increment the count of the inner circle
          } else if (dist <= ra * ra) {  // If the cell is in the outer circle
            n += grid[y]
                     [x];  // Add the cell value to the sum of the outer circle
            N += 1;        // Increment the count of the outer circle
          }
        }
      }
      m /= M;  // Calculate the average of the inner circle
      n /= N;  // Calculate the average of the outer circle
      float temp = transition(n, m);  // Calculate the transition
      grid_diff[cy][cx] =
          (2 * temp) - 1;  // Calculate the difference of the grid
    }
  }
}

// Main function
int main(void) {
  make_grid();           // Initialize the grid
  for (;;) {             // Infinite loop
    display_grid(grid);  // Display the grid

    compute_grid_diff();  // Compute the difference of the grid
    for (size_t y = 0; y < HEIGHT; ++y) {
      for (size_t x = 0; x < WIDTH; ++x) {
        grid[y][x] +=
            dt * grid_diff[y][x];  // Update the grid based on the difference
        clamp(&grid[y][x], 0.0f, 1.0f);  // Clamp the grid value between 0 and 1
      }
    }
  }
  return 0;  
}
