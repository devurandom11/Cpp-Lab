#!/usr/bin/env bash
status=$1
if [ "$status" = "test" ]; then
    clang++ -Og -g -Wall -Werror -pedantic test.cpp -o test && chmod +x ./test && ./test
fi

if [ "$status" = "main" ]; then
    clang++ -Og -g -Wall -Werror -pedantic main.cpp -o main && chmod +x ./main && ./main
fi
