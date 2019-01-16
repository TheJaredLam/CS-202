//This is Jared Lam test driver creation for project
//Please don't copy this one you can get a lot of trouble for you and me.
//I don't want you guys fail, so this is an example on how to create based on previous project which by the way is Project 9
#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

int main() {
  //Testing default constructor of DataType
  DataType testing;
  cout << "DataType Default Constructor is working!! Yeah!!" << endl;
  cout << "The value for testing is: " << testing << endl;

  //DataType Parameterized C-tor
  DataType testing2(5, 2.5);
  cout << "DataType Parameterized Construction is running!" << endl;
  //Making sure the overload operator is working
  cout << "Value of testing2 is: " << testing2 << endl;

  //Copy constructor of DataType
  DataType cpyData(testing2);
  cout << endl << "DataType Copy Construction is running!" << endl;
  cout << "The cpyData's value is: " << cpyData << endl;

  //DataType operator=
  if(cpyData == testing2) {
    cout << "The overload operator is running and they're equal to each other." << endl;
  }
  else {
      cout << "The overload operator is running, but they have different to each other." << endl;
  }

  //DataType GetIntVal()
  cout << "Is the function of DataType GetIntVal() working?" << endl;
  cout << "The cpyData.GetIntVal(): " << cpyData.GetIntVal() << endl;

  //DataType SetIntVal()
  cout << "Is the function of DataType SetIntVal() working?" << endl;
  cpyData.SetIntVal(21);
  cout << "The cpyData.SetIntVal() is ready!" << endl;
  cout << "The int value of cpyData is: " << cpyData.GetIntVal() << endl;

  //DataType GetDoubleVal()
  cout << "Is the function of DataType GetDoubleVal() working?" << endl;
  cout << "The cpyData.GetDoubleVal() is: " << cpyData.GetDoubleVal() << endl;

  //DataType SetDoubleVal()
  cout << "Is the function of DataType SetDoubleVal() working?" << endl;
  cpyData.SetDoubleVal(3.2);
  cout << "The cpy.Data.SetDoubleVal() is ready!" << endl;
  cout << "The double value of cpyData is: " << cpyData.GetDoubleVal() << endl;

  cout << "-----------------------------" << endl;

  //Node Constructors
  cout << "I wonder if the Node class and creation of Nodes are working?" << endl;

  Node<DataType> node;
  cout << "Default node constructor is running!" << endl;
  cout << "The node's value is: " << node.GetData() << endl;

  cout << "Is Node Parameterized Constructor working?" << endl;
  Node<DataType> node2(cpyData);
  cout << "The Parameterized Constructor of Node is running smoothly." << endl;
  cout << "The node2's value is: " << node2.GetData() << endl;

  cout << "Is Node Copy Constructor working?" << endl;
  Node<DataType> cpyNode(node2);
  cout << "This is Node Copy Constructor..." << endl;
  cout << "The cpyNode's value for Node is: " << cpyNode.GetData() << endl;

  //This is operator<< function has m_data of const and non const
  cout << "Is the function GetData() working?" << endl;
  cout << "The cpyNode.GetData() is: " << cpyNode.GetData() << endl;

  cout << "--------------------------------" << endl;

  cout << "Now onto the NodeStack class to see if it works or not." << endl;

  cout << "Is the default Constructor of NodeStack working?" << endl;
  NodeStack<DataType> stack;
  cout << "The stack value for NodeStack is: " << stack << endl;

  //Making all the list not equal to 0 because core dumped
  cout << "Is NodeStack Parameterized Constructor working?" << endl;
  NodeStack<DataType> stack2(2, cpyData);
  cout << "The Parameterized Constructor of NodeStack is running smoothly." << endl;
  cout << "The stack2 value of NodeStack is: " << stack2 << endl;

  cout << "Is the function of NodeStack Copy Constructor working?" << endl;
  NodeStack<DataType> cpyStack(stack2);
  cout << "The Copy Constructor of NodeStack is running smoothly." << endl;
  cout << "The stack2 of the value is: " << cpyStack << endl;

  cout << "Is the function of NodeStack Assignment Operator working?" << endl;
  NodeStack<DataType> request(4, cpyData);
  request = stack2;
  cout << "The Assignment Operator of NodeStack is running smoothly." << endl;
  cout << "The request's value for NodeStack is: " << request << endl;

  cout << "Is the function of NodeStack's top() is working?" << endl;
  DataType first = request.top();
  cout << "The 1st Node data for NodeStack is: " << first << endl;

  //Need to make sure the value is either pair or not a pair
  DataType points(23, 3.0);
  cout << "Is the function of NodeStack's push() working?" << endl;
  request.push(points);
  cout << "The new points value: " << request << endl;

  cout << "Is the function of NodeStack's pop() working?" << endl;
  request.pop();
  cout << "The new points value: " << request << endl;

  cout << "Is the function of NodeStack's size() working?"<< endl;
  cout << "The list of the size for NodeStack is: " << request.size() << endl;

  cout << "Is the function of NodeStack's empty() working?" << endl;
  cout << "There is the code below this statement make sure if it is works or not."<< endl;
  //Node tempSupplies;
  NodeStack<DataType> tempSupplies(2, cpyData);
  if(tempSupplies.empty()) {
    cout << "The list is nowhere to be found." << endl;
  }
  else {
    cout << "There's a thing inside of the list." << endl;
  }

  cout << "Is the function of NodeStack's full() working?" << endl;
  request.full();
  cout << "The full function is working. Awesome!" << endl;

  cout << "Is the function of NodeStack's clear() working?" << endl;
  tempSupplies.clear();
  stack2.clear();
  cout << "This is the tempSupplies when it's finish by the clear(). Hooray!!!" << tempSupplies << endl;
  cout << "This is the stack2 when it's finish by the clear(). Hooray!!!" << stack2 << endl;

  cout << "----------------------------" << endl;

  cout << "Finally, we have landed to our last stop please enter ArrayStack class and implementation!!" << endl;

  cout << "Is the function of ArrayStack's Default Constructor working?" << endl;
  ArrayStack<DataType> ptr2;
  cout << "The ptr2's value for ArrayStack is: " << endl;
  cout << ptr2 << endl;
  if(ptr2.empty()) {
    cout << "Warning nothing in the ArrayStack and the list can't be shown." << endl;
  }
  else {
    cout << ptr2.front() << endl;
  }

  cout << "Is the function of ArrayStack's Parameterized Constructor working?" << endl;
  ArrayStack<DataType> patrol(2, cpyData);
  cout << "The patrol value of ArrayStack is: " << endl;
  cout << patrol << endl;

  cout << "Is the function of ArrayStack's Copy Constructor working?" << endl;
  ArrayStack<DataType> cpyPatrol(patrol);
  cout << "The cpyPatrol's value of ArrayStack is: " << endl;
  cout << cpyPatrol << endl;

  cout << "Is the function of ArrayStack's Assignment Operator working?" << endl;
  const ArrayStack <DataType> requestPatrol = patrol;
  cout << "The patrol's value of ArrayStack is: " << patrol << endl;

  DataType readyTable;
  cout << "Is the function of ArrayStack's top() working(non const)?" << endl;
  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayStack and can't show anything." << endl;
  }
  else {
    readyTable = patrol.front();
    cout << "The top data (non const) of ArrayStack value is: " << readyTable << endl;
  }

  cout << "Is the function of ArrayStack's top() working(const)?" << endl;
  if(requestPatrol.empty()) {
    cout << "There is nothing here in the ArrayStack and can't show anything." << endl;
  }
  else {
    cout << "The top data (const) of ArrayStack value is: " << endl;
    const DataType repeatPatrol = requestPatrol.front();
    cout << repeatPatrol << endl;
  }

  cout << "Is the function of ArrayStack's push() working?" << endl;
  cout << "Enter the items that you want to have in your list." << endl;
  size_t items;
  cin >> items;
  for(size_t p = 0; p < items; p++) {
    DataType temporary((int)p, (double)p * 3.0);
    patrol.push(temporary);
  }
  cout << "The newest list for ArrayStack after push is: " << endl;
  cout << patrol << endl;

  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayStack and can't show anything." << endl;
  }
  else {
    cout << "The top element of ArrayStack is: " << patrol.top() << endl;
  }

  cout << "Is the function of ArrayStack's pop() working?" << endl;
  patrol.pop();
  cout << "The newest list after pop() for the ArrayStack is: " << patrol << endl;

  cout << "Is the function of ArrayStack's size()" << endl;
  cout << "The list's size for ArrayStack is: " << patrol.size() << endl;
  cout << "The top element of the list in ArrayStack is: " << endl;
  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayStack and can't show anything." << endl;
  }
  else {
    cout << patrol.top() << endl;
  }

  cout << "------------------------" << endl;
  cout << "Yeah you have finish you requirement for this projects!!!" << endl;
  return 0;

}
