#!/bin/bash

programs_to_test=$(find ./programs -name '*.test.c' | sed 's|/[^/]*$||' | sed 's|./programs/||g' | sort | uniq)

for program in $programs_to_test; do
    source_files=$(ls ./programs/$program/*.c | grep -v main.c)
    gcc -lcriterion -o ./build/$program.test $source_files
    ./build/$program.test
done
