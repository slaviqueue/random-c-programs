#!/bin/bash

set -e
program_to_build=$1
gcc_flags="-Iprograms -Wall -g $2"

if [ -z "$program_to_build" ]; then
    echo "Usage: $0 <program_to_build>"
    exit 1
fi

source_files=$(ls $program_to_build/*.c | grep -v test.c)
mkdir -p ./build/programs/
gcc $gcc_flags -o ./build/$program_to_build $source_files
