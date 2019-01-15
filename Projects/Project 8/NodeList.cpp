#include <iostream>
#include "NodeList.h"

using namespace std;

NodeList::NodeList() {
  m_head = NULL;
}

NodeList::NodeList(size_t count, const DataType & value) {
  if(count <= 0) {
    m_head = NULL;
  }
  else {
    m_head = new Node(value);
    Node * head = m_head;
    while(--count > 0) {
      head -> m_next = new Node(value);
      head = head -> m_next;
    }
    head -> m_next = NULL;
  }
}

NodeList::NodeList(const NodeList & other) {
  *this = other;
}

NodeList::~NodeList() {
  clear();
}

NodeList & NodeList::operator= (const NodeList & rhs) {
  if(this == &rhs) {
    return *this;
  }
  Node * ptr == rhs.m_head;
  if(ptr) {
    m_head = new Node(*rhs.m_head);
    Node * temp = m_head;
    ptr = ptr -> m_next;
    while(ptr) {
      temp -> m_next = new Node(*ptr);
      temp = temp -> m_next;
      ptr = ptr -> m_next;
    }
  }
  return *this;
}

Node * NodeList::front() {
  if(m_head) {
    return m_head;
  }
  else {
    return NULL;
  }
}

Node * NodeList::back() {
  if(m_head) {
    Node * ptr = m_head;
    while(ptr -> m_next) {
      ptr = ptr -> m_next;
    }
    return ptr;
  }
  else {
    return NULL;
  }
}

Node * NodeList::find(const DataType & target,
            Node * & previous, const Node * start) {
   if(empty()) {
     return NULL;
   }
   Node * first;
   if(start) {
     first = (Node*) start;
   }
   else {
     first = m_head;
   }
   while (first && !(first -> data() == target)) {
     previous = first;
     first = first -> m_next;
   }
   return first;
}

Node * NodeList::insertAfter(const DataType & target,
                       const DataType & value) {
    Node * prev;
    Node *ptr = find(target, prev);
    if(ptr == NULL) {  //ptr is empty
      return NULL:
    }
    else {
      prev = new Node(value);
      prev -> m_next = ptr -> m_next;
      ptr -> m_next = prev;

      return prev;
    }
}
Node * NodeList::insertBefore(const DataType & target,
                        const DataType & value) {
    Node * prev;
    Node *ptr = find(target, prev);
    if(!ptr) {  //ptr is empty
      return NULL;
    }
    else if(ptr == m_head) {
      m_head = new Node(value);
      m_head -> m_next = ptr;
      return m_head;
    }
    else {
      prev -> m_next = new Node(value);
      prev->m_next->m_next = ptr;
      return prev -> m_next;
    }
}

Node * NodeList::erase(const DataType & target) {
  Node * prev;
  Node *ptr = find(target, prev);
  if(!ptr) {  //ptr is empty
    return NULL;
  }
  else {
    prev -> m_next = ptr -> m_next;
    ptr -> m_next = NULL;
    delete ptr;
    return prev -> m_next;
  }
}

DataType & NodeList::operator[] (size_t position) {
  Node * ptr = m_head;
  while(position-- && ptr) {
    ptr = ptr -> m_next;
  }
  return ptr -> m_data;
}

const DataType & NodeList::operator[] (size_t position) const {
  Node * ptr = m_head;
  while(position-- && ptr) {
    ptr = ptr -> m_next;
  }
  return ptr -> m_data;
}

size_t NodeList::size() const {
  size_t count = 0;
  Node * ptr = m_head;
  while(ptr) {
    ptr = ptr -> m_next;
    count++;
  }
  return count;
}

bool NodeList::empty() const {
  return !m_head;
}

void NodeList::clear() {
  if(empty()) {
    return;
  }
  Node * ptr = m_head;
  while(ptr) {
    ptr = m_head -> m_next;
    delete m_head;
    m_head = ptr;
  }
}

std::ostream & operator<<(std::ostream & os,
                                 const NodeList & nodeList) {
  int size = nodeList.size();
  for(int i = 0; i < size; i++) {
    os << nodeList[i];
  }
  os << endl;
  return os;
}
