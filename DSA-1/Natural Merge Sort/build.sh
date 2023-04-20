#!/usr/bin/env bash
program=$1

case "${program}" in
    "main")
        echo "item = main"
        clang++ -Og -g -Wall -Werror -pedantic main.cpp -o main && chmod +x ./main && ./main
    ;;
    "test")
        echo "program = test"
        clang++ -Og -g -Wall -Werror -pedantic test.cpp -o test && chmod +x ./test && ./test
    ;;
    "selectionSort")
        echo "program = selectionSort"
        clang++ -Og -g -Wall -Werror -pedantic selectionSort.cpp -o selectionSort && chmod +x ./selectionSort && ./selectionSort
    ;;
    "insertionSort")
        echo "program = insertionSort"
        clang++ -Og -g -Wall -Werror -pedantic insertionSort.cpp -o insertionSort && chmod +x ./insertionSort && ./insertionSort
    ;;
    "clean")
        echo "program = clean"
        rm -rf *.o *.out *.exe *.stackdump *.dSYM *.exe.stackdump main test selectionSort insertionSort
    ;;
    "all")
        echo "program = all"
        clang++ -Og -g -Wall -Werror -pedantic main.cpp -o main && chmod +x ./main
        clang++ -Og -g -Wall -Werror -pedantic test.cpp -o test && chmod +x ./test
        clang++ -Og -g -Wall -Werror -pedantic selectionSort.cpp -o selectionSort && chmod +x ./selectionSort
        clang++ -Og -g -Wall -Werror -pedantic insertionSort.cpp -o insertionSort && chmod +x ./insertionSort
        executables=(test selectionSort insertionSort main)
        for executable in "${executables[@]}"
        do
            ./"$executable"
            echo ""
        done
    ;;
    *)
        echo "Incorrect Usage:"
        echo "Usage: ./build.sh [all|main|test|selectionSort|insertionSort|clean]"
    ;;
esac


