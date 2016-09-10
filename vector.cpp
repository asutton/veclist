// Copyright (C) 2016 Andrew Sutton
// All rights reserved.

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "algorithm.hpp"
#include "test.hpp"


int main()
{
  // Declare a pseudo-random bit generator, which we'll use to create random 
  // numbers below. 
  std::mt19937 prbg;

  // Uncomment this (and comment out the lines above) to create a generator 
  // seeded from the system's random device.
  // std::random_device rd;
  // std::mt19937 prbg(rd());

  // Run the test a number of times.
  for (int n = S; n <= N; n += S) {

    // Get the starting time point. The type is deduced because it's hard
    // to spell (it is std::chrono::system_clock::time_point).
    auto start = std::chrono::system_clock::now();

    // The actual test.
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
      // Create a random number generator whose values will be in the the
      // range [0, i). Note that the range of random numbers depends on the 
      // size of the sequence. This guarantees an equal probability of choosing
      // all insertion points.
      std::uniform_int_distribution<int> rand(0, i - 1);

      int num = rand(prbg);             // Generate a random number
      auto iter = find_lower(seq, num); // Find the insertion point
      seq.insert(iter, num);            // Insert the element.
    }

    // Get the current system time in nanoseconds.
    auto stop = std::chrono::system_clock::now();

    // Print the number of nanoseconds each test takes.
    std::cout << n << ' ' << (stop - start).count() << std::endl;
  }

}
