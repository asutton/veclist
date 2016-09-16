// Copyright (C) 2016 Andrew Sutton
// All rights reserved.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
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

    // Pre-generate all the numbers we're going to pick and put them in
    // a random order.
    std::vector<int> rand(n);
    std::iota(rand.begin(), rand.end(), 0);
    std::shuffle(rand.begin(), rand.end(), prbg);

    // Get the starting time point. The type is deduced because it's hard
    // to spell (it is std::chrono::system_clock::time_point).
    auto start = std::chrono::system_clock::now();

    // The actual test.
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
      int num = rand.back();                    // Get the next random number
      rand.pop_back();
      auto iter = linear_lower_bound(seq, num); // Find the insertion point
      seq.insert(iter, num);                    // Insert the element
    }

    // Get the current system time in nanoseconds.
    auto stop = std::chrono::system_clock::now();

    // Print the number of nanoseconds each test takes.
    std::cout << n << ' ' << (stop - start).count() << std::endl;
  }

}
