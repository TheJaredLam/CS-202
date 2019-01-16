#include <iostream>
#include "SmartPtr.h"
#include <cstdlib>

using namespace std;

SmartPtr::SmartPtr() {
  m_ptr = new DataType;
  m_refcount = new size_t (1);
  cout << "SmartPtr Default Constructor for new allocation, RefCount="
  << *m_refcount << endl;
}

SmartPtr::SmartPtr(DataType * data) {
  m_ptr = data;
  m_refcount = new size_t (0);
  if(m_ptr != NULL) {
    *m_refcount = 1;
  }
  else {
    *m_refcount = 0;
  }
  cout << "SmartPtr Parameterized-ctor from data pointer, RefCount="
  << *m_refcount << endl;
}

SmartPtr::SmartPtr(const SmartPtr & other) {
  if(other.m_ptr == NULL) {
    m_ptr = other.m_ptr;
    m_refcount = new size_t (0);
  }
  else {
    m_ptr = other.m_ptr;
    m_refcount = other.m_refcount;
    (*m_refcount)++;
  }
  cout << "SmartPtr Copy-ctor, RefCount=" << *m_refcount << endl;
}

SmartPtr::~SmartPtr() {
  (*m_refcount)--;
  if(m_refcount == 0){
    cout << "SmartPtr D-tor, RefCount=" << *m_refcount << endl;
    delete [] m_refcount;
    m_refcount = NULL:
    delete [] m_ptr;
    m_ptr = NULL;
  }
}

SmartPtr & SmartPtr::operator=( const SmartPtr & rhs) {
  if(this == &rhs) {
    return *this;
  }
  if(rhs.m_ptr == NULL) {
    m_ptr = rhs.m_ptr;
    m_refcount = new size_t (0);
    return *this;
  }
  (*m_refcount)--;
  if(m_refcount == 0) {
    delete [] m_refcount;
    m_refcount = NULL:
    delete [] m_ptr;
    m_ptr = NULL;
  }
  m_ptr = rhs.m_ptr;
  m_refcount = rhs.m_refcount;
  (*m_refcount)++;
  cout << "SmartPtr Assignment, RefCount=" << *m_refcount << endl;
  return *this;
}

DataType & SmartPtr::operator*() {
  return *m_ptr;
}

DataType * SmartPtr::operator->() {
  return m_ptr;
}
