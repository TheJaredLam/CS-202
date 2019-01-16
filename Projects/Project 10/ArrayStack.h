#ifndef ArrayStack_H_
#define ArrayStack_H_

#include <iostream>
#include "DataType.h"

const size_t MAX_STACKSIZE = 1000;

using namespace std;

template <typename T>
class ArrayStack {
  template <typename U>
  friend std::ostream& operator<<(std::ostream & os,      //(i)
                  const ArrayStack<U> & arrayStack);
  public:
    ArrayStack();   //(1)
    ArrayStack(size_t count, const T & value);      //(2)
    ArrayStack(cosnt ArrayStack<T> & other);        //(3)
    ~ArrayStack();                                  //(4)
    ArrayStack<T> &operator= (const ArrayStack<T> & rhs);      //(5)
    T &top();        //(6a)
    const T & top() const;      //(6b)
    void push(const T & value);        //(7)
    void pop();         //(8)
    size_t size();     //(9)
    bool empty() const;   //(10)
    bool full() const;    //(11)
    void clear();         //(12)
    void serialize(std::ostream & os) const;      //(13)

  private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
};
#endif

template <typename U>
std::ostream& operator<<(std::ostream & os, const ArrayStack<U> & arrayStack) {
  arrayStack.serialize(os);
  return os;
}
template <typename T>
ArrayStack<T>::ArrayStack() {
  m_top = 0;
}
template <typename T>
ArrayStack<T>::ArrayStack(size_t count, const T & value) {
  m_top = 0;
  for(size_t i = 0; i < count; i++) {
    m_container[i] = value;
  }
}
template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other) {
  m_top = other.m_top;
  for(size_t m = 0; m < m_top; m++) {
    m_container[m] = other.m_container[m];
  }
}
template <typename T>
ArrayStack<T>::~ArrayStack() {
  clear();
}
template <typename T>
ArrayStack<T> & ArrayStack<T>::operator= (const ArrayStack<T> & rhs) {
  m_top = rhs.m_top;
  for(size_t e = 0; e < m_top; e++) {
    m_container[e] = rhs.m_container[e];
  }
  return *this;
}
template <typename T>
T & ArrayStack<T>::top() {
  return m_container[m_top - 1];
}
template <typename T>
const T & ArrayStack<T>::top() const {
  return m_container[m_top - 1];
}
template <typename T>
void ArrayStack<T>::push(const T & value) {
  if(full()) {
    cout << "we can't get to the list because it's full." << endl;
    return;
  }
  m_container[m_top++] = value;
}
template <typename T>
void ArrayStack<T>::pop() {
  if(empty()) {
    return;
  }
  else {
    --m_top;
  }
}
template <typename T>
size_t ArrayStack<T>::size() const {
  return m_top;
}
template <typename T>
bool ArrayStack<T>::empty() const {
  if(m_top == 0) {
    return true;
  }
  else {
    return false;
  }
}
template <typename T>
bool ArrayStack<T>::full() const {
  if(m_top >= MAX_STACKSIZE) {
    return true;
  }
  else {
    return false;
  }
}
template <typename T>
void ArrayStack<T>::clear() {
  m_top = 0;
}
template <typename T>
void ArrayStack<T>::serialize(std::ostream & os) const {
  for(size_t t = 0; t < m_top; t++) {
    os << m_container[t] << endl;
  }
}
