#include <iostream>
#include "ArrayList.h"

using namespace std;

std::ostream & operator<<(std::ostream & os,           //(i)
                const ArrayList & arrayList)
{
  size_t list = arrayList.m_size;
  size_t s = 0;
  while(list--) {
    os << arrayList.m_array[s++] << " ";
  }
  return os;
}

ArrayList::ArrayList() {
  m_size = 0;
  m_array = NULL:
  m_maxsize = 0;
}

ArrayList::ArrayList(size_t count, const DataType & value) {
  m_maxsize = count;
  m_size = count;
  m_array =  new DataType[m_size];
  for(size_t s = 0; s < m_size; s++) {
    m_array[s] = value;
  }
}

ArrayList::ArrayList(const ArrayList & other) {
  m_size = other.m_size;
  m_maxsize = other.m_maxsize;
  m_array = new DataType[m_maxsize];

  for(size_t s = 0; s < m_size; s++) {
    m_array[s] = (other.m_array[s]);
  }
}

ArrayList::~ArrayList() {
  clear();
}
ArrayList & ArrayList::operator= (const ArrayList & rhs) {
  if(this != &rhs) {
    m_maxsize = rhs.m_maxsize;
    if(m_array) {
      delete [] m_array;
    }
    m_array = new DataType[m_maxsize];
    m_size = rhs.m_size;
    int assign = (int)rhs.m_size;
    size_t s = 0;
    while(assign--) {
      m_array[s] = rhs.m_array[s];
      ++s;
    }
  }
  return *this;
}

DataType * ArrayList::front() {
  if(m_size > 0) {
    return &m_array[0];
  }
  return NULL;
}

DataType * ArrayList::back() {
  if(m_size > 0) {
    return &m_array[m_size - 1];
  }
  return NULL;
}

DataType * ArrayList::find(const DataType & target,
DataType * & previous, const DataType * start = NULL) {
  DataType * ptr;
  if(start) {
    ptr = (DataType*) start;
  }
  else {
    ptr = m_array;
  }
  for(int s = 0; s < m_size; s++) {
    if(ptr[s] == target) {
      if(s > 0) {
        previous = &ptr[s - 1];
        return &ptr[s];
      }
      else {
        previous = NULL;
        return &ptr[s];
      }
    }
  }
  previous = NULL;
  return NULL;
}

DataType * ArrayList::insertAfter(const DataType & target, const DataType &
    value) {
    for(int s = 0; s < m_size; s++) {
      if(m_array[s] == target) {
        if(m_size == m_maxsize) {
          resize(m_maxsize + 1);
        }
        if(s == m_size - 1) {
          m_array[m_size] = target;
          ++m_size;
          return &m_array[m_size - 1];
        }
        else {
          ++s;
          DataType temp1;
          DataType temp2;
          temp1 = m_array[s];
          ++m_size;
          for(int i = s; i < m_size; i++) {
            temp2 = temp1;
            temp1 = m_array[i];
            m_array[i] = temp2;
          }
          m_array[s] = value;
          return &m_array[s];
        }
      }
    }
    return NULL;
}

DataType * ArrayList::insertBefore(const DataType & target, const DataType &
    value) {
    for(int s = 0; s < m_size; s++) {
      if(m_array[s] == target) {
        if(m_size == m_maxsize) {
          resize(m_maxsize + 1);
        }
        DataType temp1;
        DataType temp2;
        temp1 = m_array[s];
        for(int i = s; i < m_size; i++) {
          temp2 = temp1;
          temp1 = m_array[i];
          m_array[i] = temp2;
        }
        m_array[s] = value;
        return &m_array[s];
      }
    }
    return NULL;
}

DataType * ArrayList::erase(const DataType & target) {
  m_size--;
  for(int s = 0; s < m_size; s++) {
    if(m_array[s] == target) {
      if(s == m_size - 1) {
        return NULL;
      }
      for(int i = s; i < m_size; i++) {
        m_array[i] = m_array[i + 1];
      }
      return &m_array[s];
    }
  }
  return NULL;
}

DataType & ArrayList::operator[] (size_t position) {
  return m_array[position];
}

/* const DataType & ArrayList::operator[] (size_t position) const {
  return m_array[position];
}
*/
size_t ArrayList::size() const {
  return m_size;
}

bool ArrayList::empty() const {
  if(!this -> m_array) {
    return true;
  }
  return false;
}

void ArrayList::clear() {
  delete [] m_array;
  m_array = NULL;
}

void ArrayList::resize(size_t count) {
  size_t originalsize = m_maxsize;
  m_maxsize = count;
  DataType * original = m_array;
  m_array = new DataType[count];
  size_t s = 0;
  DataType location;
  for(; s < count; s++) {
    if(s >= originalsize) {
      m_array[s] = location;
    }
    else {
      m_array[s] = original[s];
    }
  }
  delete [] original;
}
