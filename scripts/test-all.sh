#!/bin/bash

gcc_flags="-Iprograms -Wall -g $2"
gcc_libs="-lcriterion -lm"

programs_to_test=$(find ./programs -name '*.test.c' | sed 's|/[^/]*$||' | sed 's|./programs/||g' | sort | uniq)
success=1

for program in $programs_to_test; do
    source_files=$(ls ./programs/$program/*.c | grep -v main.c)
    gcc $gcc_flags -o ./build/$program.test $source_files $gcc_libs

    ./build/$program.test

    if [ $? -ne 0 ]; then
        success=0
    fi
done

if [ $success -eq 1 ]; then
    echo "All tests passed"
    exit 0
fi

echo "Some tests failed"
exit 1
