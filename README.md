# random-c-programs

![test workflow](https://github.com/slaviqueue/random-c-programs/actions/workflows/test.yaml/badge.svg)

A set of random c programs that I write to practice my c skills.

(actually some directories don't contain programs, but an implementation of a
function with a bunch of tests, but I don want to rename the repo)

## Building and running programs

To build and run a program (a directory with a main.c file inside), use the
`./scripts/run.sh`.

```
$ ./scripts/run.sh ./programs/htoi
Enter your hex number: beef
Ten-based value is: 48879
```

To make things more handy, while working on a particular program, one can bind
running `run.sh` to some key in vim, like so:

```
:map <leader>r :! .scripts/run.sh hello-world<cr>
```

## Tests

For unit tests I've used the
[criterion](https://github.com/Snaipe/Criterion/tree/bleeding) testing
framework.

To run all tests, use the following script:
```
$ ./scripts/test-all.sh
```

To run tests for a particular program, use:
```
$ ./scripts/test.sh ./programs/htoi
```
