
This repository contains a set of programs that can be used to measure
the relative performance of a simple algorithm that builds sorted sequences
of randomly generated integer values. In psuedocode, that algorithm is:

```
let s = empty_sequence()
for i in 0..n:
  let n = random(0, n - 1)
  let p = linear_search(s, n)
  s.insert(p, n)
```

The algorithm works by generating a random value, determining where they 
should be inserted (so that the sequence stays sorted), and then actually 
inserting the generated value.

The `random` function generates random values in the range [0, n), which 
corresponds to the number of positions in the sequence. We choose from this
range so that each insertion position is equally probable. We don't want to
generate values whose insertions tend toward the front or back; that would
bias the experiment.

The `linear_search` algorithm returns the first position in `s` where
`n` can be inserted such that the sequence remains sorted after insertion.
In general, this is done by iterating through the sequence to find the
first position whose value is not less than `n`.

The algorithm is neither particularly useful nor optimal. The purpose of this
algorithm is to observe its behavior with different kinds of sequences,
in particular C++'s `vector`s and `list`s.


## Building

The program is configured using CMake and requires a C++11 compliant compiler.
The build produces 4 different programs. These are:

*`test-list`* (defined in `list.cpp`). This program uses a `std::list` for
sequence above.

*`test-vector`* (defined in `vector.cpp`). This program uses a `std::vector` 
for the sequence in the algorithm above.

*`test-vector-binary`* (defined in `vector-binary.cpp`). This program uses a 
`std::vector` for the sequence in the algorithm above and replaces
`linear_search` with `lower_bound` (a binary search).

*`test-vector-sort`* (defined in `vector-sort.cpp`). This program uses a 
different algorithm for generating a sorted `vector` of random numbers. In
particular, it a) generates an unsorted sequence of random numbers, and
b) sorts the vector.


## Running

Each program runs the algorithm multiple times, with each iteration producing
larger and larger sorted sequences. Each iteration is timed. After each 
iteration, the program prints (to standard output) the number of elements in 
the sorted sequence followed by the number of microseconds required.

Running programs is straightforward. Simply execute the command. For example:

```bash
$ ./test-vector
1000 1975
2000 7588
3000 21090
4000 28987
5000 47640
6000 66532
7000 88035
8000 112471
9000 138670
10000 167799
```

Since the output is written to standard output, this can easily be redirected
and saved to a file.

```bash
$ ./test-vector > vector.txt
```

These files can be loaded into spreadsheets or used with, say, gnuplot.

## Design

Each program is implemented in its own source file as described above. There
are two header files containing common algorithms and other information. These
are:

    - `algorithm.hpp` -- Defines `linear_search` and handful of other 
    functions (overloads of standard algorithms).

    - `test.hpp` -- Defines the parameters for the test: the maximum sequence
    size and the increment. These default to 50,000 and 1,000 respectively.

Each implementation is clearly documented and intended to be read.
