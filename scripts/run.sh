#!/bin/bash

set -e
program_to_run=$1
gcc_flags="-Iprograms -Wall -g $2"
gcc_libs="-lm"

if [ -z "$program_to_run" ]; then
    echo "usage: $0 <program_to_run>"
    exit 1
fi

mkdir -p ./build/programs/

source_files=$(ls $program_to_run/*.c | grep -v test.c)
gcc $gcc_flags -o ./build/$program_to_run $source_files $gcc_libs

./build/$program_to_run
