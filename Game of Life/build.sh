#!/bin/sh
set -xe

if [ -f GoL ]; then
	rm GoL
fi

cc -O3 -o GoL GOL.c -lm -fopenmp

