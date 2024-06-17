#!/bin/bash

set -e
program_to_run=$1

if [ -z "$program_to_run" ]; then
    echo "Usage: $0 <program_to_run>"
    exit 1
fi

mkdir -p ./build/programs/

source_files=$(ls $program_to_run/*.c | grep -v test.c)
echo "source_files: $source_files"
gcc -o ./build/$program_to_run $source_files

./build/$program_to_run
