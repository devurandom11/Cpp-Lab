#!/bin/bash

# Build the project C++ project with main.cpp as the only file using clang++ compiler with all debug and print options enabled and check if main exists already. delete it first if it does and run main at the end of this build script
[ -f main ] && rm main
clang++ -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o main main.cpp && ./main
