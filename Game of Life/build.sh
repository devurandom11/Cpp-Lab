#!/bin/sh
set -xe

if [ -f GoL ]; then
	rm GoL
fi

cc -O3 -Wall -Werror -Wpedantic -o GoL GOL.c -lm
