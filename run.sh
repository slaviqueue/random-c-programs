#!/bin/bash

set -e
program_to_run=$1

if [ -z "$program_to_run" ]; then
    echo "Usage: $0 <program_to_run>"
    exit 1
fi

mkdir -p build
gcc -o ./build/$program_to_run ./$program_to_run/*.c
./build/$program_to_run
