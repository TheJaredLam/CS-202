#include <iostream>
#include "NodeQueue.h"

using namespace std;

NodeQueue::NodeQueue() {
  m_front = NULL;
  m_back = NULL;
}

NodeQueue::NodeQueue(size_t count, const DataType & value) {
  m_front = new Node(value);
  m_back = m_front;
  for(size_t i = 1; i < count; i++) {
    m_back -> m_next = new Node(value);
    m_back = m_back -> m_next;
  }
}

NodeQueue::NodeQueue(const NodeQueue & other) {
  Node * copy = other.m_front;
  if(!other.empty()) {
    m_front = new Node(other.m_front -> m_data);
    m_back = m_front;
    copy = copy -> m_next;
    while(copy) {
      m_back -> m_next = new Node(copy -> m_data);
      m_back = m_back -> m_next;
      copy = copy -> m_next;
    }
  }
}

NodeQueue::~NodeQueue() {
  clear();
}

NodeQueue & NodeQueue::operator= (const NodeQueue & rhs) {
  if(!empty()) {
    clear();
  }
  Node * copy == rhs.m_front;
  if(!rhs.empty()) {
    m_front = new Node(rhs.m_front -> m_data);
    m_back = m_front;
    copy = copy -> m_next;
    while(copy) {
      m_back -> m_next = new Node(copy -> m_data);
      m_back = m_back -> m_next;
      copy = copy -> m_next;
    }
  }
  return *this;
}

DataType& NodeQueue::front() {
  return m_front -> m_data;
}

const DataType& NodeQueue::front() const {
  return m_front -> m_data;
}

DataType& NodeQueue::back() {
  return m_back -> m_data;
}

const DataType& NodeQueue::back() const {
  return m_back -> m_data;
}

void NodeQueue::push(const DataType& value) {
  m_back -> m_next = new Node (value);
  m_back = m_back -> m_next;
}

void NodeQueue::pop() {
  if(!empty()) {
    Node * fast = m_front;
    m_front = m_front -> m_next;
    fast -> m_next = NULL;
    delete fast;
  }
}

size_t NodeQueue::size() const {
  size_t s = 0;
  Node * length = m_front;
  while(length) {
    length = length -> m_next;
    ++s;
  }
  return s;
}

bool NodeQueue::empty() const {
  if(m_front) {
    return false;
  }
  else {
    return true;
  }
}

bool NodeQueue::full() const {
  return false;
}

void NodeQueue::clear() {
  while(!empty()) {
    pop();
  }
}

void NodeQueue:: serialize(std::ostream& os) const {
  Node * reverse = m_front;
  while(reverse) {
    os << reverse -> m_data;
    reverse = reverse -> m_next;
  }
}

std::ostream & operator<<(std::ostream & os,
                                 const NodeQueue & NodeQueue) {
  nodeQueue.serialize(os);
  return os;
}
