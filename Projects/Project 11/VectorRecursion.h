#ifndef VectorRecursion_H_
#define VectorRecursion_H_
#include <iostream>
#include <vector>

using namespace std;

//This function will have to perform Recursive Sorting of the vector elements
//Also sorting is used for quicksort algorithm
template <typename T>
void swap(vector<T> &v, T m, T n) {
  T temp = v[m];
  v[m] = v[n];
  v[n] = temp;
}

template <typename T>
T divide(vector<T> &v, T l, T h) {
  T p = v[h];
  T r = l - 1;
  T s = l;
  while(s <= h - 1) {
    if(v[s] <= p) {
      ++r;
      swap(v, r, s);
    }
    ++s;
  }
  swap(v, r + 1, h);
  return (r + 1);
}

template <typename T>
void vector_resort(vector<T> &v, T l, T h) {
  if(l < h) {
    T p = divide(v, l, h);
    vector_resort(v, l, p - 1);
    vector_resort(v, p + 1, h);
  }
}

//We do the same thing with reference binary search to make a number from vector work or not
template <typename T>
T vector_research(vector<T> &v, T l, T h, const T theory) {
  if(l > h) {
    return -1;
  }
  T m = (l + h) / 2;
  if(v[m] == theory) {
    return m;
  }
  if(v[m] > theory) {
    return vector_research(v, l, m - 1, theory);
  }
  return vector_research(v, m + 1, h, theory);
}
#endif
