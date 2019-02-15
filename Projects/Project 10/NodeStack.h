#ifndef NodeStack_H_
#define NodeStack_H_
#include <iostream>
#include "DataType.h"

using namespace std;

template <typename T>
class NodeStack;
template <typename T>
class Node {
  template <typename U>
  friend class NodeStack;
  template <typename U>
  friend std::ostream& operator<<(std::ostream & os, const Node<U> & srcNode)
  {
    os << "Data value is: " << srcNode.m_data << std::endl;
    return os;
  }

  public:

    Node() : m_next( NULL ){}
    Node(const T& data, Node<T>* next = NULL) :
       m_next( next ),
       m_data( data )
    {
    }
    Node(cosnt Node<T>& other) :
      m_next( other.m_next ),
      m_data( other.m_data )
    {
    }

    T& GetData() {   //gets non-const reference, can be used to modify value of underlying data
        //return const_cast<DataType&>(static_cast<const Node&>(*this).GetData());  //an alternative implementation, just for studying reference
        return m_data;
    }

    T& SetData(int intVal, double doubleVal) {
      m_data.SetIntVal(intVal);
      m_data.SetDoubleVal(doubleVal);
      return m_data;
    }

    Node<T>* GetNext() const {
      return m_next;
    }

  private:
    Node<T>* m_next;
    T m_data;
};
template <typename T>
class NodeStack {
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os,
                           const NodeStack<U>& NodeStack);
  public:
    NodeStack();
    NodeStack(size_t count, const T& value);
    NodeStack(cosnt NodeStack<T>& other);
    ~NodeStack();
    NodeStack<T> &operator= (const NodeStack<T>& rhs);
    T &top();
    const T& top() const;
    void push(const T& value);
    void pop();
    size_t size();
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream& os) const;

  private:
    Node<T>* m_top;
};
#endif

template <typename T>
std::ostream& operator<<(std::ostream & os, const NodeStack<T>& NodeStack) {
  NodeStack.serialize(os);
  return os;
}
template <typename T>
NodeStack<T>::NodeStack() {
  m_top = NULL;
}
template <typename T>
NodeStack<T>::NodeStack(size_t count, const T& value) {
  m_top = new Node<T>(value);
  Node<T> * right = m_top;
  for(size_t i = 1; i < count; i++) {
    right -> m_next = new Node<T>(value);
    right = right -> m_next;
  }
}
template <typename T>
NodeStack<T>::NodeStack(const NodeStack<T>& other) {
  Node<T> * copy = other.m_top;
  if(!other.empty()) {
    m_top = new Node<T>(other.m_top -> m_data);
    Node<T> * decoy = m_top;
    copy = copy -> m_next;
    while(copy) {
      decoy -> m_next = new Node<T>(copy -> m_data);
      decoy = decoy -> m_next;
      copy = copy -> m_next;
    }
  }
}
template <typename T>
NodeStack<T>::~NodeStack() {
  clear();
}
template <typename T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T>& rhs) {
  if(!empty()) {
    clear();
  }
  Node<T> * copy = rhs.m_top;
  if(!rhs.empty()) {
    m_top = new Node<T>(rhs.m_top -> m_data);
    Node<T> * decoy = m_top;
    copy = copy -> m_next;
    while(copy) {
      decoy -> m_next = new Node<T>(copy -> m_data);
      decoy = decoy -> m_next;
      copy = copy -> m_next;
    }
  }
  return *this;
}
template <typename T>
T & NodeStack<T>::top() {
  return m_top -> m_data;
}
template <typename T>
const T & NodeStack<T>::top() const {
  return m_top -> m_data;
}
template <typename T>
void NodeStack<T>::push(const T & value) {
  Node<T> * fast = m_top;
  m_top = new Node<T>(value);
  m_top -> m_next = fast;
}
template <typename T>
void NodeStack<T>::pop() {
  if(!empty()) {
    Node<T> * fast = m_top -> m_next;
    delete m_top;
    m_top = fast;
  }
}
template <typename T>
size_t NodeStack<T>::size() const {
  size_t s = 0;
  Node<T> * length = m_top;
  while(length) {
    length = length -> m_next;
    ++s;
  }
  return s;
}
template <typename T>
bool NodeStack<T>::empty() const {
  if(m_top) {
    return false;
  }
  return true;
}
template <typename T>
bool NodeStack<T>::full() const {
  return false;
}
template <typename T>
void NodeStack<T>::clear() {
  while(!empty()) {
    pop();
  }
}
template <typename T>
void NodeStack<T>::serialize(std::ostream& os) const {
  Node<T> * reverse = m_top;
  while(reverse) {
    os << reverse -> m_data;
    reverse = reverse -> m_next;
  }
}
