#!/bin/bash

set -e
program_to_run=$1
input_file=$2

if [ -z "$program_to_run" ] || [ -z "$input_file" ]; then
    echo "Usage: $0 <program_to_run> <input_file>"
    exit 1
fi

mkdir -p build
gcc -o ./build/$program_to_run ./$program_to_run/*.c
cat $input_file | ./build/$program_to_run
