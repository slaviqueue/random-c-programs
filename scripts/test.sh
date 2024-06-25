#!/bin/bash

program_to_test=$1
gcc_flags="-Iprograms -g $2"

if [ -z "$program_to_test" ]; then
    echo "Usage: $0 <program_to_test>"
    exit 1
fi

mkdir -p ./build/programs/

source_files=$(ls $program_to_test/*.c | grep -v main.c)
gcc $gcc_flags -lcriterion -O0 -o ./build/$program_to_test.test $source_files

./build/$program_to_test.test
