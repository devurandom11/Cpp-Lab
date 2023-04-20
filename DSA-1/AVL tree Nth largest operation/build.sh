#!/usr/bin/env bash
echo "Building main.cpp..."
clang++ -Wall -Werror -pedantic -Og -g main.cpp -o main
echo "Running now..."
sleep 1
chmod +x ./main && ./main
