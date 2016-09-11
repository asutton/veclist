// Copyright (C) 2016 Andrew Sutton
// All rights reserved.

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <algorithm>

// Returns an iterator pointing to the first element in the range [first, last) 
// that is not less than (i.e., greater than or equal to) value.
//
// This is a linear search version of std::lower_bound.
template<typename I, typename T>
I linear_search(I first, I limit, T const& value)
{
  while (first != limit) {
    if (!(*first < value))
      return first;
    ++first;
  }
  return limit;
}


// Returns an iterator pointing to the first element in the range [first, last) 
// that is not less than (i.e., greater than or equal to) value.
//
// This is convenience function that lets use use find_lower without 
// directly using iterators. 
template<typename C, typename T>
typename C::const_iterator
linear_search(C const& container, T const& value)
{
  return linear_search(container.begin(), container.end(), value);
}


// Returns an iterator pointing to the first element in the range [first, last) 
// that is not less than (i.e., greater than or equal to) value.
//
// This is convenience function that lets use use std::lower_bound without 
// directly using iterators. 
template<typename C, typename T>
typename C::const_iterator
lower_bound(C const& container, T const& value)
{
  return std::lower_bound(container.begin(), container.end(), value);
}


// Sorts a container of elements.
//
// This is convenience function that lets use use std::sort without 
// directly using iterators. 
template<typename C>
void
sort(C& container)
{
  return std::sort(container.begin(), container.end());
}


#endif
