source_files=$(ls programs/**/*.c)

clang-tidy --config-file=.clang-tidy $source_files --fix-errors
