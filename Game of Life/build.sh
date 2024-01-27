#!/bin/sh
set -xe

if [ -f GoL ]; then
    rm GoL
fi

clang -O3 -Wall -Werror -Wpedantic -o GoL GOL.c -lm
