#include <iostream>
#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main() {
  //Testing DataType Default Constructor
  DataType data;
  cout << endl << "DataType Default c-tor is successful!!!" << endl;
  cout << "Data's value is: " << data << endl;

  //Testing DataType Parameterized Constructor
  DataType secondData(3, 5.0);
  cout << endl << "DataType Parameterized c-tor is successful!!!" << endl;
  //Testing overload operation <<
  cout << "Value of secondData: " << secondData << endl;

  //Testing DataType Copy Constructor
  DataType cpyData(secondData);
  cout << endl << "DataType Copy c-tor is successful!!!" << endl;
  cout << "Value of cpyData: " << cpyData << endl;

  //Testing DataType operator==
  if(cpyData == secondData) {
    cout << endl << "Overload operator is success and they are equal to each other." << endl;
  }
  else {
      cout << endl << "Overload operator is success, but they don't equal to each other at all." << endl;
  }

  //Testing DataType getIntVal()
  cout << endl << "Test the DataType of getIntVal()" << endl;
  cout << "cpyData.getIntVal(): " << cpyData.getIntVal() << endl;

  //Testing DataType setIntVal()
  cout << endl << "Test the DataType of setIntVal()" << endl;
  cpyData.setIntVal(2);
  cout << endl << "cpyData.setIntVal() is ready to do the action!!!" << endl;
  cout << "cpyData value of int is: " << cpyData.getIntVal() << endl;

  //Testing DataType getDoubleVal()
  cout << endl << "Test the DataType of getDoubleVal()" << endl;
  cout << "cpyData.getDoubleVal(): " << cpyData.getDoubleVal() << endl;

  //Testing DataType setDoubleVal()
  cout << endl << "Test the DataType of setDoubleVal()" << endl;
  cout << endl << "cpyData.setDoubleVal() is ready to do the action" << endl;
  cpyData.setDoubleVal(35.0);
  cout << "cpyData value of double is: " << cpyData.getDoubleVal() << endl;

  cout << "---------------------------------------------" << endl;
  //Test Node Constructor
  cout << endl << "Test Node Class and implementation of Nodes are working!" << endl;

  Node node;
  cout << endl << "Default node Constructor successful!!!" << endl;
  cout << "Node's value is: " << node << endl;

  cout << endl << "Testing Parameterized node c-tor" << endl;
  Node secondNode(cpyData);
  cout << "Node Parameterized is successful!!!" << endl;
  cout << "Node's secondNode value are: " << secondNode << endl;

  cout << endl << "Testing Copy c-tor works?" << endl;
  Node cpyNode(secondNode);
  cout << "Node Copy c-tor is successful!!!" << endl;
  cout << "Node's cpyNode value are: " << cpyNode << endl;

  //Evoke the operator<< for the data of const and non-Constructor
  cout << endl << "Test data(): " << endl;
  cout << "cpyNode.data(): " << cpyNode.data() << endl;

  cout << "---------------------------------------" << endl;

  cout << endl << "Test NodeList class now" << endl;

  cout << endl << "Test NodeList Default Constructor" << endl;
  NodeList newAgenda;
  cout << "newAgenda value are: " << newAgenda << endl;

  //Parameterized Constructor
  cout << endl << "Test NodeList Parameterized c-tor" << endl;
  NodeList otherAgenda(40, cpyData);
  cout << "NodeList Parameterized c-tor is successful!!!" << endl;
  cout << "NodeList's otherAgenda value are: " << otherAgenda << endl;

  cout << endl << "Test NodeList Copy Constructor" << endl;
  NodeList cpyAgenda(otherAgenda);
  cout << "NodeList Copy c-tor is successful!!!" << endl;
  cout << "NodeList's cpyAgenda value are: " << cpyAgenda << endl;

  //Assignment operator
  cout << endl << "Test NodeList Assignement operator" << endl;
  NodeList assignAgenda(4, cpyData);
  assignAgenda = otherAgenda;
  cout << "NodeList Assignment operator is successful!!!" << endl;
  cout << "NodeList's assignAgenda value are: " << assignAgenda << endl;

  cout << endl << "Front Node test" << endl;
  Node * front = assignAgenda.front();
  cout << "Front Node's address: " << assignAgenda.front() << endl;
  cout << "Front Node's data: " << front -> data() << endl;
  cout << "Front Node's new data values are: " << front -> data() << endl;
  cout << "New List(Agenda): " << assignAgenda << endl;

  cout << endl << "Back Node test" << endl;
  Node * back = assignAgenda.back();
  cout << "Back Node's address: " << assignAgenda.back() << endl;
  cout << "Back Node's data: " << back -> data() << endl;
  cout << "New List(Agenda): " << assignAgenda << endl;

  //Making sure it verifies match no match state
  DataType iSpy(35, 25.0);
  cout << endl << "Test for NodeList find()" << endl;
  DataType search(2, 20.0);
  NodeList * list = new NodeList(10, search);
  Node* found = list -> insertAfter(search, iSpy);
  if(found) {
    cout << endl << "Match found!!!" << endl;
    cout << "Address where it's found: " << found << endl;
    cout << "Find's Data: " << found -> data() << endl;
  }
  else {
    cout << endl << "Match hasn't been found at all!!!" << endl;
  }

  cout << *list << std::endl;

    cout << endl << "Testing NodeList's insertAfter()" << endl;
    DataType uses(25, 17.0);
    Node * after = list -> insertAfter(iSpy, uses);
    cout << "Insertion works!!!"<< endl;
    cout << "Address where it's found in insertion: " << after << endl;
    cout << "The value of insertion is: " << after -> data() << endl;
    cout << "New List(Agenda): " << assignAgenda << endl;

    cout << endl << "Testing NodeList's insertBefore()" << endl;
    DataType user2(10, 5.0);
    Node * before = list -> insertBefore(iSpy, user2);
    cout << "Insertion works!!!"<< endl;
    cout << "Address where it's found in insertion: " << before << endl;
    cout << "The value of insertion is: " << before -> data() << endl;
    cout << "New List(Agenda): " << assignAgenda << endl;

    cout << endl << "Testing NodeList's erase()" << endl;
    Node * ptr_next = list -> erase(uses);
    cout << "erase works!!!"<< endl;
    cout << "Address of next node after erasing Node" << ptr_next << endl;
    cout << "Value of next node after erasing Node " << *ptr_next << endl;
    cout << "New List(Agenda): " << assignAgenda << endl;

    cout << endl << "Test for NodeList's operator[]()" << endl;
    cout << "Value in the index array: " << endl << assignAgenda[18] << endl;
    cout << "Operator [] is a success!!!" << endl;

    cout << endl << "Test for NodeList's size()" << endl;
    int length = list -> size();
    cout << " assignAgenda's length is: " << length << endl;

    cout << endl << "Test for NodeList's empty()" << endl;
    cout << "Making sure the list is empty to get true value"<< endl;
    NodeList important;
    if(important.empty()) {
      cout << "Empty List Detected" << endl;
    }
    else {
      cout << "List detected" << endl;
    }
    cout  << endl << "Test for clear()" << endl;
    NodeList originalAgenda(assignAgenda);
    cout << "Clear is running" << endl;
    if(originalAgenda.size() > 0)
    {
      originalAgenda.clear();
      if(originalAgenda.empty()) {
        cout << "It is successful and the list is empty." << endl;
      }
      else {
        cout << "Not working, there is a list look very extra careful" << endl;
      }
    }
    else {
      cout << "originalAgenda hasn't been created at all" << endl;
    }

    cout << "-------------------" << endl;
    cout << endl << "Test ArrayList Class" << endl;
    cout << "Warning if assign a value to 0 it would become seg fault" << endl;

    cout << endl << "Test ArrayList Default Constructor" << endl;
    ArrayList List;
    cout << "The Default constructor is a success!!!" << endl;
    cout << "In order for output we need to dereference NULL" << endl;

    cout << endl << "Test ArrayList Parameterized c-tor" << endl;
    ArrayList watchList(10, uses);
    cout << "Parameterized constructor is success!!!" << endl;
    cout << "The default value is: " << watchList << endl;

    cout << endl << "Test for ArrayList Copy Constructor" << endl;
    ArrayList cpyAgendaArray(watchList);
    cout << "Copy Constructor is successful!!!" << endl;
    cout << "A value of cpyAgendaArray: " << cpyAgendaArray << endl;

    cout << endl << "Test for ArrayList Assignement" << endl;
    cpyAgendaArray = watchList;
    cout << "Assignment operator is a success" << endl;
    cout << "The new cpyAgendaArray of its value: " << cpyAgendaArray << endl;

    cout << endl << "Test for ArrayList front()" << endl;
    ArrayList secondAgenda(watchList);
    cout << "Value of secondAgenda(): " << secondAgenda << endl;
    cout << "The front value is: " << *secondAgenda.front() << endl;

    cout << endl << "Testing the ArrayList back()" << endl;
    cout << "The value of secondAgenda is: " << secondAgenda << endl;
    cout << "The back of the value is: " << *secondAgenda.back() << endl;

    cout << endl << "Testing the ArrayList Find()" << endl;


    Node* found2 = list -> insertAfter(search, iSpy);
    if(found2) {
      cout << endl << "Match found!!!" << endl;
      cout << "Address where it's found: " << found << endl;
      cout << "Find's Data: " << found -> data() << endl;
    }
    else {
      cout << endl << "Match hasn't been found at all!!!" << endl;
    }
    DataType weirdType(960, 480);
    DataType mark(5, 2.0);
    ArrayList * supplies = new ArrayList(5, mark);
    DataType * location = supplies -> insertAfter(mark, weirdType);

    cout << "The value of location is: " << *location << endl;
    cout << "The most before of value is: " << endl;
    if(!before) {
      cout << "NULL" << endl;
    }
    else {
      cout << *before << endl;
    }

    cout << endl << "Test for ArrayList Size()" << endl;
    cout << "secondAgenda's size of ArrayList is: " << secondAgenda.size() << endl;

    cout << endl << "Test for ArrayList insertBefore()" << endl;
    DataType FrontTest(0, 0.0);
    secondAgenda.insertBefore(FrontTest, weirdType);
    cout << "The secondAgenda is: " << secondAgenda << endl;
    cout << "The insertion before is a successful" << endl;
    return 0;
}
