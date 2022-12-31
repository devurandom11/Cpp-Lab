#include <iostream>
#include <cstring>
#include <fstream>

const int MAX_LINE_LENGTH = 256; // Maximum line length in the input file

int main()
{
    // Open the file and read the lines
    std::ifstream file("ParkPhotos.txt");
    char line[MAX_LINE_LENGTH];

    // Iterate through the lines and modify the file name
    while (file.getline(line, MAX_LINE_LENGTH))
    {
        char new_name[MAX_LINE_LENGTH];
        strcpy(new_name, line);
        char *pos = strstr(new_name, "_photo.jpg");
        if (pos != NULL)
        {
            strcpy(pos, "_info.txt");
        }
        std::cout << new_name << std::endl;
    }

    return 0;
}
