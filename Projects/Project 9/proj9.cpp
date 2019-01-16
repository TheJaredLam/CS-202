//This is Jared Lam test driver creation for project
//Please don't copy this one you can get a lot of trouble for you and me.
//I don't want you guys fail, so this is an example on how to create based on previous project which by the way is Project 8
#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main() {
  //Testing default constructor of DataType
  DataType testing;
  cout << "DataType Default c-tor is successful!!!" << endl;
  cout << "The value of testing is: " << testing << endl;

  //DataType Parameterized C-tor
  DataType testing2(4, 12.0);
  cout << "DataType Parameterized Construction is running!" << endl;
  //Making sure the overload operator is working
  cout << "Value of testing2 is: " << testing2 << endl;

  //Copy constructor of DataType
  DataType cpyData(testing2);
  cout << "DataType Copy Construction is running!" << endl;
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
  cpyData.SetIntVal(28);
  cout << "The cpyData.SetIntVal() is ready!" << endl;
  cout << "The int value of cpyData is: " << cpyData.GetIntVal() << endl;

  //DataType GetDoubleVal()
  cout << "Is the function of DataType GetDoubleVal() working?" << endl;
  cout << "The cpyData.GetDoubleVal() is: " << cpyData.GetDoubleVal() << endl;

  //DataType SetDoubleVal()
  cout << "Is the function of DataType SetDoubleVal() working?" << endl;
  cpyData.SetDoubleVal(4.5);
  cout << "The cpy.Data.SetDoubleVal() is ready!" << endl;
  cout << "The double value of cpyData is: " << cpyData.GetDoubleVal() << endl;

  cout << "-----------------------------" << endl;

  //Node Constructors
  cout << "I wonder if the Node class and creation of Nodes are working?" << endl;

  Node node;
  cout << "Default node constructor is running!" << endl;
  cout << "The node's value is: " << node.GetData() << endl;

  cout << "Is Node Parameterized Constructor working?" << endl;
  Node node2(cpyData);
  cout << "The Parameterized Constructor of Node is running smoothly." << endl;
  cout << "The node2's value is: " << node2.GetData() << endl;

  cout << "Is Node Copy Constructor working?" << endl;
  Node cpyNode(node2);
  cout << "This is Node Copy Constructor..." << endl;
  cout << "The cpyNode's value for Node is: " << cpyNode.GetData() << endl;

  //This is operator<< function has m_data of const and non const
  cout << "Is the function GetData() working?" << endl;
  cout << "The cpyNode.GetData() is: " << cpyNode.GetData() << endl;

  cout << "--------------------------------" << endl;

  cout << "Now onto the NodeQueue class to see if it works or not." << endl;

  cout << "Is the default Constructor of NodeQueue working?" << endl;
  NodeQueue quest;
  cout << "The quest value for NodeQueue is: " << quest << endl;

  //Making all the list not equal to 0 because core dumped
  cout << "Is NodeQueue Parameterized Constructor working?" << endl;
  NodeQueue quest2(2, cpyData);
  cout << "The Parameterized Constructor of NodeQueue is running smoothly." << endl;
  cout << "The quest2 value of NodeQueue is: " << quest2 << endl;

  cout << "Is the function of NodeQueue Copy Constructor working?" << endl;
  NodeQueue cpyQuest(quest2);
  cout << "The Copy Constructor of NodeQueue is running smoothly." << endl;
  cout << "The quest2 of the value is: " << cpyQuest << endl;

  cout << "Is the function of NodeQueue Assignment Operator working?" << endl;
  NodeQueue request(4, cpyData);
  request = quest2;
  cout << "The Assignment Operator of NodeQueue is running smoothly." << endl;
  cout << "The request's value for NodeQueue is: " << request << endl;

  cout << "Is the function of NodeQueue's First() is working?" << endl;
  DataType first = request.front();
  cout << "The 1st Node data for NodeQueue is: " << first << endl;

  cout << "Is the function of NodeQueue's Last() is working?" << endl;
  DataType bronze = request.back();
  cout << "The bronze's data is: " << bronze << endl;

  //Need to make sure the value is either pair or not a pair
  DataType points(32, 25.0);
  cout << "Is the function of NodeQueue's push() working?" << endl;
  request.push(points);
  cout << "The new points value: " << request << endl;

  cout << "Is the function of NodeQueue's pop() working?" << endl;
  request.pop();
  cout << "The new points value: " << request << endl;

  cout << "Is the function of NodeQueue's size() working?"<< endl;
  cout << "The list of the size for NodeQueue is: " << request.size() << endl;

  cout << "Is the function of NodeQueue's empty() working?" << endl;
  cout << "There is the code below this statement make sure if it is works or not."<< endl;
  //NodeQueue tempSupplies;
  NodeQueue tempSupplies(2, cpyData);
  if(tempSupplies.empty()) {
    cout << "The list is nowhere to be found." << endl;
  }
  else {
    cout << "There's a thing inside of the list." << endl;
  }

  cout << "Is the function of NodeQueue's full() working?" << endl;
  request.full();
  cout << "The full function is working. Awesome!" << endl;

  cout << "Is the function of NodeQueue's clear() working?" << endl;
  tempSupplies.clear();
  quest2.clear();
  cout << tempSupplies << endl;
  cout << quest2 << endl;

  cout << "----------------------------" << endl;

  cout << "Finally, we have landed to our last stop please enter ArrayQueue class and implementation!!" << endl;

  cout << "Is the function of ArrayQueue's Default Constructor working?" << endl;
  ArrayQueue ptr2;
  cout << "The ptr2's value for ArrayQueue is: " << endl;
  cout << ptr2 << endl;
  if(ptr2.empty()) {
    cout << "Warning nothing in the ArrayQueue and the list can't be shown." << endl;
  }
  else {
    cout << ptr2.front() << endl;
  }

  cout << "Is the function of ArrayQueue's Parameterized Constructor working?" << endl;
  ArrayQueue patrol(2, cpyData);
  cout << "The patrol value of ArrayQueue is: " << endl;
  cout << patrol << endl;

  cout << "Is the function of ArrayQueue's Copy Constructor working?" << endl;
  ArrayQueue cpyPatrol(patrol);
  cout << "The cpyPatrol's value of ArrayQueue is: " << endl;
  cout << cpyPatrol << endl;

  cout << "Is the function of ArrayQueue's Assignment Operator working?" << endl;
  const ArrayQueue requestPatrol = patrol;
  cout << "The patrol's value of ArrayQueue is: " << patrol << endl;

  DataType readyTable;
  cout << "Is the function of ArrayQueue's front() working(non const)?" << endl;
  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    readyTable = patrol.front();
    cout << "The front data (non const) of ArrayQueue value is: " << readyTable << endl;
  }

  cout << "Is the function of ArrayQueue's front() working(const)?" << endl;
  if(requestPatrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    cout << "The front data (const) of ArrayQueue value is: " << endl;
    const DataType repeatPatrol = requestPatrol.front();
    cout << repeatPatrol << endl;
  }
  //back() turns
  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    cout << "Is the function of ArrayQueue's back() working(non-const)?" << readyTable << endl;
    readyTable = patrol.back();
    cout << "The back data(non const) of ArrayQueue value is: " << readyTable << endl;
  }

  if(requestPatrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    cout << "Is the function of ArrayQueue's back() working(const)?" << readyTable << endl;
    const DataType repeatPatrol2 = requestPatrol.back();
    cout << "The back data(const) of ArrayQueue value is: " << repeatPatrol2 << endl;
  }

  cout << "Is the function of ArrayQueue's push() working?" << endl;
  cout << "Enter the items that you want to have in your list." << endl;
  size_t items;
  cin >> items;
  for(size_t p = 0; p < items; p++) {
    DataType temporary((int)p, (double)p * 3.0);
    patrol.push(temporary);
  }
  cout << "The newest list for ArrayQueue after push is: " << endl;
  cout << patrol << endl;

  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    cout << "The back element of ArrayQueue is: " << patrol.back() << endl;
  }

  cout << "Is the function of ArrayQueue's pop() working?" << endl;
  patrol.pop();
  cout << "The newest list after pop() for the ArrayQueue is: " << patrol << endl;

  cout << "Is the function of ArrayQueue's size()" << endl;
  cout << "The list's size for ArrayQueue is: " << patrol.size() << endl;
  cout << "The back element of the list in ArrayQueue is: " << endl;
  if(patrol.empty()) {
    cout << "There is nothing here in the ArrayQueue and can't show anything." << endl;
  }
  else {
    cout << patrol.back() << endl;
  }

  cout << "------------------------" << endl;
  cout << "Yeah you have finish you requirement for this projects!!!" << endl;
  return 0;

}
