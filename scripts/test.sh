#!/bin/bash

program_to_test=$1
gcc_flags=$2

if [ -z "$program_to_test" ]; then
    echo "Usage: $0 <program_to_test>"
    exit 1
fi

mkdir -p ./build/programs/

source_files=$(ls $program_to_test/*.c | grep -v main.c)
gcc -lcriterion -o ./build/$program_to_test.test $source_files -Wall $gcc_flags

./build/$program_to_test.test
