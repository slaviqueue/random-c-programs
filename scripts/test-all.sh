#!/bin/bash

programs_to_test=$(find ./programs -name '*.test.c' | sed 's|/[^/]*$||' | sed 's|./programs/||g' | sort | uniq)
success=1

for program in $programs_to_test; do
    source_files=$(ls ./programs/$program/*.c | grep -v main.c)
    gcc -o ./build/$program.test $source_files -lm  -lcriterion -Wall

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
