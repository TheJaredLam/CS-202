#include <iostream>
#include "ArrayQueue.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const ArrayQueue& ArrayQueue) {
  ArrayQueue.serialize(os);
  return os;
}

ArrayQueue::ArrayQueue() {
  m_front = 0;
  m_back = 0;
  m_size = 0;
}

ArrayQueue::ArrayQueue(size_t count, const DataType& value) {
  m_front = 0;
  m_back = count;
  m_size = count;
  for(size_t i = 0; i < count; i++) {
    m_array[i] = value;
  }
}

ArrayQueue::ArrayQueue(const ArrayQueue& other) {
  m_front = other.m_front;
  m_back = other.m_back;
  m_size = other.m_size;
  for(size_t s = m_front, t = 0; t < m_size; s = (s + 1) % ARRAY_MAX, t++) {
    m_array[s] = other.m_array[s];
  }
}

ArrayQueue::~ArrayQueue() {
  clear();
}

ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs) {
  m_front = rhs.m_front;
  m_back = rhs.m_back;
  m_size = rhs.m_size;
  for(size_t s = m_front, t = 0; t < m_size; s = (s + 1) % ARRAY_MAX, t++) {
    m_array[s] = rhs.m_array[s];
  }
  return *this;
}

DataType& ArrayQueue::front() {
  return m_array[m_front];
}

const DataType& ArrayQueue::front() const {
  return m_array[m_front];
}

DataType& ArrayQueue::back() {
  return m_array[m_back];
}

const DataType& ArrayQueue::back() const {
  return m_array[m_back];
}

void ArrayQueue::push(const DataType& value) {
  m_array[m_back] = value;
  ++m_size;
  m_back = (m_back + 1) % ARRAY_MAX;
}

void ArrayQueue::pop() {
  --m_size;
  m_front = (m_front + 1) % ARRAY_MAX;
}

size_t ArrayQueue::size() const {
  return m_size;
}

bool ArrayQueue::empty() const {
  if(m_size == 0) {
    return false;
  }
  else {
    return true;
  }
}

bool ArrayQueue::full() const {
  if(m_size >= ARRAY_MAX) {
    return true;
  }
  else {
    return false;
  }
}
void ArrayQueue::clear() {
  m_back = 0;
  m_size = 0;
  m_front = 0;
}

void ArrayQueue::serialize(std::ostream& os) const {
  for(size_t s = m_front, t = 0; t < m_size; s =(s + 1) % ARRAY_MAX, t++) {
    os << m_array[s];
  }
}
