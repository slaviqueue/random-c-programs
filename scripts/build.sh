#!/bin/bash

set -e
program_to_build=$1

if [ -z "$program_to_build" ]; then
    echo "Usage: $0 <program_to_build>"
    exit 1
fi

mkdir -p ./build/programs/
gcc -o ./build/$program_to_build $program_to_build/*.c
