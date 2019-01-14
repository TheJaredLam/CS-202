#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

MyString::MyString() {
  m_size = 0;
  m_buffer = NULL;
}

MyString::MyString(const char * str) {
  m_size = strlen(str);
  m_buffer = new char[m_size + 1];
  strcpy(m_buffer, str);
}

MyString::MyString(const MyString & other_myStr) {
  m_size = other_myStr.m_size;
  m_buffer = new char[m_size + 1];
  strcpy(m_buffer, other_myStr.m_buffer);
}

MyString::~MyString() {
  if(m_buffer != NULL) {
    delete [] m_buffer;
    m_buffer = NULL;
  }
}

size_t MyString::size() const {
  return m_size;
}

size_t MyString::length() const {
  return m_size - 1;
}

const char * MyString::c_str() const {
  return m_buffer;
}

bool MyString::operator== (const MyString & other_myStr) const {
  return strcmp(m_buffer, other_myStr.m_buffer) == 0;
}

MyString & MyString::operator= (const MyString & other_myStr) {
  if(m_buffer != NULL) {
    delete [] m_buffer;
    m_buffer = NULL;
  }
  m_size = other_myStr.m_size;
  m_buffer = new char[m_size + 1];
  strcpy(m_buffer, other_myStr.m_buffer);
}

MyString MyString::operator+ (const MyString & other_myStr) const {
  MyString re;
  re.m_size = m_size + other_myStr.m_size - 2;
  char * temp_buffer = new char[re.m_size + 1];
  strcpy(temp_buffer, m_buffer);
  re.m_buffer = temp_buffer;
  strcat(re.m_buffer, other_myStr.m_buffer);
  return re;
}

char & MyString::operator[] (size_t index) {
  return m_buffer[index];
}

const char & MyString::operator[] (size_t index) const {
  return m_buffer[index];
}

std::ostream& operator<<(ostream& os, const MyString& myStr) {
  os << myStr.m_buffer;
  return os;
}

void MyString::buffer_deallocate() {
  if(m_buffer != NULL) {
    delete [] m_buffer;
    m_buffer = NULL;
  }
}

void MyString::buffer_allocate(size_t size) {
  m_buffer = new char[m_size + 1];
}
