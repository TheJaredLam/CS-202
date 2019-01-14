CS 202 - Computer Science II
Project 8
Due date (FIXED): Wednesday, 11/14/2018, 11:59 pm
Objectives: The main objectives of this project are to test your ability to create and use list-based
dynamic data structures. A review of your knowledge to manipulate dynamic memory, classes,
pointers and iostream to all extents, is also included. You may from now on freely use square
bracket-indexing, pointers, references, all operators, the <cstring> library, and the
std::string type as you deem proper.
Description:
For this project you will create List classes. There will have to be two separate List-based
implementations, one Array-based, and the other Node-based.
Array-based List:
The following header file extract is used to explain the required specifications for the class (the
actual header ArrayList.h file is provided and accompanies the Project description):
…
class ArrayList{
friend std::ostream & operator<<(std::ostream & os, //(i)
const ArrayList & arrayList);
public:
ArrayList(); //(1)
ArrayList(size_t count, const DataType & value); //(2)
ArrayList(const ArrayList & other); //(3)
~ArrayList(); //(4)
ArrayList & operator= (const ArrayList & rhs); //(5)
DataType * front(); //(6)
DataType * back(); //(7)
DataType * find(const DataType & target, //(8)
DataType * & previous,
const DataType * start = NULL);
DataType * insertAfter(const DataType & target, //(9)
const DataType & value);
DataType * insertBefore(const DataType & target, //(10)
const DataType & value);
DataType * erase(const DataType & target); //(11)
DataType & operator[] (size_t position); //(12a)
const DataType & operator[] (size_t position) const; //(12b)
size_t size() const; //(13)
bool empty() const; //(14)
void clear(); //(15)
private:
void resize(size_t count); //(16)
DataType * m_array;
size_t m_size;
size_t m_maxsize;
};
…
The ArrayList Class will contain the following private data members:
 m_array, a DataType class type Pointer, pointing to the Dynamically Allocated Array data.
It is the container for the ArrayList data, and will have to be resized (reallocated) whenever it
needs to grow to accommodate more data than it can fit, and possibly whenever it should
trim down when it takes up too much space.
 m_size, a size_t, keeps track of how many DataType elements are currently stored &
considered valid inside m_array. Note: this has to be properly initialized and updated each
time the dynamically allocated memory is changed.
 m_maxsize, a size_t, denoting how many DataType type objects can fit in total in the
currently allocated memory of the m_array. Note: this has to be properly initialized and
updated each time the dynamically allocated memory is changed, and that generally m_size
≤ m_maxsize.
, will have the following private helper methods:
(16) resize – will deallocate the dynamic memory pointed to by m_array and then allocate
enough total memory to fit the size_t count number of elements. Also, the original
m_array data should be carried (copied) over to the newly allocated one.
Note A: When enlarging the m_array container, only the valid ArrayList elements (m_size in
total) should be copied over, and the rest (m_maxsize-m_size in total) should have the
DataType Default ctor value.
Note B: When shrinking down the m_array container, in case the new m_maxsize cannot fit
all the m_size elements of the ArrayList, then the last ones are just discarded. If it can, then
it copies over only the valid ArrayList elements (m_size in total), and the rest (m_maxsizem_
size n total) should have the DataType Default ctor value.
, and will have the following public member functions:
 (1) Default Constructor – will instantiate a new list object with no valid data. Note: What
needs to be initialized in this case?
 (2) Parametrized Constructor – will instantiate a new list object, which will hold size_t
count number of elements in total, all of them initialized to have the same value as the
DataType value parameter. Note: Has to properly handle allocation.
 (3) Copy Constructor – will instantiate a new ArrayList object which will be a separate copy
of the data of the other ArrayList object which is getting copied. Note: Remember Deep and
Shallow object copies.
 (4) Destructor – will destroy the instance of the ArrayList object. Note: Any allocated
memory pointed-to by m_array has to be deallocated in here.
 (5) operator= will assign a new value to the calling ArrayList object, which will be an exact
copy of the rhs ArrayList object. Returns a reference to the calling object to be used for
cascading operator= as per standard practice. Note: Think what needs to happen before
allocating new memory for the new data to be held by the calling object.
 (6) front returns a pointer to the first (valid) element of m_array, or NULL if it fails. Note: A
reason for failing can be that the list is empty.
 (7) back returns a pointer to the last (valid) element of m_array, or NULL if it fails. Note: A
reason for failing can be that the list is empty.
 (8) find returns a pointer to the first (valid) element of m_array, which is found to have the
same value as the passed parameter DataType target (the equality operator== as overloaded
in class DataType should be used to check that). If it fails (it does not find the value it
searched for), it returns NULL. Also, it takes in By-Reference a DataType Pointer
parameter, and sets it to the Address of the target’s predecessor element. If the search fails,
or if the target element is found to be the first and has no predecessor, previous should be
set to NULL.
(Extra Functionality (not required for 100pt grade): The method also takes in a
DataType Pointer named start, which indicates where it should start searching in the list. If
this is passed as NULL, it denotes to start searching from the first element. Otherwise, this
can be used to start a recursive search in case an element exists twice (otherwise Find will
always return the first element’s address).
 (9) insertAfter first finds the DataType element target, and then inserts after it in the list a
new element of the value DataType value. Returns DataType Pointer to the element it just
inserted (or NULL if it failed). Note: Try to think through what you are doing, and sketch out
how it’s going to work. Think of all possible cases, e.g. inserting in the middle, at the end, in
the start, what happens if m_array already has a size that fits the element, or if it should be
resized to fit the new element, etc.
 (10) insertBefore first finds the DataType element target, and then inserts before it in the
list a new element of the value DataType value. Returns DataType Pointer to the element it
inserted (or NULL if it failed). Note: Try to think through what you are doing, and sketch out
how it’s going to work. Think of all possible cases, e.g. inserting in the middle, at the end, in
the start, what happens if m_array already has a size that fits the element, or if it should be
resized to fit the new element, etc.
 (11) erase first finds the DataType element target, and then removes it from the list. Returns
a DataType Pointer to the element right after the one it just removed (if the last it removed
was the last in the list, it should return NULL). Note: Try to think through what you are
doing, and sketch out how it’s going to work. Think of all possible cases, e.g. removing in
the middle, the first element, the last element.
 (12) operator[] will allow by-reference accessing of a specific DataType object at index int
position within the allocated m_array. Note: Should not care if the position requested is more
than the m_array size.
 (15) size will return the size of the current list. Note: This is the m_size of m_array and not
its m_maxsize, i.e. it is the number of valid DataType entries inside it.
 (16) empty will return a bool, true if the list is empty, and false otherwise.
 (17) clear will clear the contents of the list, so after its call it will be an empty list object.
Note: Does this need to perform memory deallocation?
as well as a friend function:
 (i) operator<< will output (to terminal or file depending on the type of ostream& os object
passed as a parameter to it) the content of the calling ArrayList object. Note: it will do so by
traversing the list and calling the insertion operator<< on the valid DataType elements
contained within it.
Node-based List:
The following header file extract is used to explain the required specifications for the class (the
actual header NodeList.h file is provided and accompanies the Project description):
…
class NodeList{
friend std::ostream & operator<<(std::ostream & os, //(i)
const NodeList & nodeList);
public:
NodeList(); //(1)
NodeList(size_t count, const DataType & value); //(2)
NodeList(const NodeList & other); //(3)
~NodeList(); //(4)
NodeList & operator= (const NodeList & rhs); //(5)
Node * front(); //(6)
Node * back(); //(7)
Node* find(const DataType & target, //(8)
Node * & previous,
const Node * start = NULL);
Node * insertAfter(const DataType & target, //(9)
const DataType & value);
Node * insertBefore(const DataType & target, //(10)
const DataType & value);
Node * erase(const DataType & target); //(11)
DataType & operator[] (size_t position); //(12a)
const DataType & operator[] (size_t position) const; //(12b)
size_t size() const; //(13)
bool empty() const; //(14)
void clear(); //(15)
private:
Node * m_head;
};
…
The NodeList Class will contain the following private data members:
 m_head, a Node class type Pointer, pointing to the Dynamically Allocated Node object
considered as the first element of the list. Note: If the list is empty m_head should be NULL.
,and will have the following public member functions:
 (1) Default Constructor – will instantiate a new list object with no data (no Nodes). Note:
What needs to be initialized in this case?
 (2) Parametrized Constructor – will instantiate a new list object, which will hold size_t
count number of elements (Nodes) in total, all of them initialized to hold the same value as
the DataType value parameter. Note: Has to properly handle allocation.
 (3) Copy Constructor – will instantiate a new list object which will be a separate copy of
the data of the other NodeList object which is getting copied. Note: Remember Deep and
Shallow object copies.
 (4) Destructor – will destroy the instance of the NodeList object. Note: Any allocated
memory taken up by elements (Nodes) belonging to the list has to be deallocated in here.
 (5) operator= will assign a new value to the calling NodeList object, which will be an exact
copy of the rhs NodeList object. Returns a reference to the calling object to be used for
cascading operator= as per standard practice. Note: Think what needs to happen before
allocating new memory for the new data to be held by the calling object.
 (6) front returns a pointer to the first element (Node) of the list, or NULL if the list is
empty.
 (7) back returns a Pointer to the last element (Node) of the list, or NULL if the list is
empty.
 (8) find returns a pointer to the first element (Node) of the list, that holds the same value as
passed parameter DataType target (the equality operator== as overloaded in class DataType
should be used to check that). If it fails (it does not find the value it searched for inside a
Node), it returns NULL. Also, it takes in By-Reference a Node Pointer parameter named
previous, and sets it to the Address of the target Node’s predecessor element (also a Node).
If the search fails, or if the target element is found within the first Node of the list and has
no predecessor, previous should be set to NULL.
(Extra Functionality (not required for 100pt grade): The method also takes in a Node
Pointer named start, which indicates where it should start searching in the list. If this is
passed as NULL, it denotes to start searching from the first element (Node). Otherwise, this
can be used to start a recursive search in case an element exists twice (otherwise Find will
always return the first element’s address).
 (9) insertAfter first finds the element (a Node) that contains DataType target, and then
inserts after it a new element (a Node) that holds the value DataType value. Returns a Node
Pointer to the element (a Node) it inserted (or NULL if it failed). Note: Try to think through
what you are doing, and sketch out how it’s going to work. Think of all possible cases, e.g.
inserting in the middle, at the end, in the start, etc.
 (10) insertBefore first finds the element (a Node) that contains DataType target, and then
inserts before it a new element (a Node) that holds the value DataType value. Returns a
Node Pointer to the element (a Node) it inserted (or NULL if it failed). Note: Try to think
through what you are doing, and sketch out how it’s going to work. Think of all possible
cases, e.g. inserting in the middle, at the end, in the start, etc.
 (11) erase first finds the element (a Node) that contains DataType target, and then removes
it from the list. Returns a Node Pointer to the element (a Node) right after the one it just
removed (if the last it removed was the last Node in the list, it should return NULL). Note:
Try to think through what you are doing, and sketch out how it’s going to work. Think of all
possible cases, e.g. removing in the middle, the first element, the last element.
 (12a,12b) operator[] (const and non-const qualified) will allow by-Reference accessing of a
specific DataType object within a Node at an index size_t position within the list. Note: Since
this is not an Array-based implementation, the size_t position index is a “fake index”, just an
incremental value such that position=0 corresponds to the first element (a Node) in the list
and each subsequent element corresponds to ++position.
 (15) size will return the size of the current list. Note: Since this is not an Array-based
implementation, the function has to traverse the list to find how many elements (Nodes) are
contained within it.
 (16) empty will return a bool, true if the list is empty, and false otherwise.
 (17) clear will clear the contents of the list, so after its call it will be an empty list object.
Note: Does this need to perform memory deallocation?
as well as a friend function:
 (i) operator<< will output (to terminal or file depending on the type of ostream& os object
passed as a parameter to it) the content of the calling NodeList object. Note: it will do so by
traversing the list and calling the insertion operator<< on the valid DataType elements
contained within the list’s elements (Nodes).
The DataType.h and DataType.cpp files are provided fully implemented. Also, the ArrayList.h and
NodeList.h header files are provided, and NodeList.h provides a class Node implementation in it as
well. You will create the necessary ArrayList.cpp and NodeList.cpp source files to implement the
range of required functionalities You should also create a source file proj8.cpp which will be a test
driver for your classes.
Do not forget to initialize pointers and/or set them to NULL appropriately where needed.
Do not forget to perform allocation, dellocation, dellocation-&-reallocation of dynamic
memory when needed! Memory accesssing without proper allocation will cause
Segmentation Faults. Forgetting to deallocate memory will cause Memory Leaks!
The completed project should have the following properties:
 Written, compiled and tested using Linux.
 It must compile successfully on the department machines using Makefile(s), which will be
invoking the g++ compiler. Instructions how to remotely connect to department machines
are included in the Projects folder in WebCampus.
 The code must be commented and indented properly.
Header comments are required on all files and recommended for the rest of the program.
Descriptions of functions commented properly.
 A one page (minimum) typed sheet documenting your code. This should include the overall
purpose of the program, your design, problems (if any), and any changes you would make
given more time.
Turn in: Compressed Header & Source files, Makefile(s), and project documentation.
Submission Instructions:
 You will submit your work via WebCampus
 Name your code file proj8.cpp
 If you have header file, name it proj8.h
 If you have class header and source files, name them as the respective class (ArrayList.h
ArrayList.cpp NodeList.h NodeList.cpp) This source code structure is not mandatory, but
advised.
 Compress your:
1. Source code
2. Makefile(s)
3. Documentation
Do not include executable
 Name the compressed folder:
PA#_Lastname_Firstname.zip
Ex: PA8_Smith_John.zip
Verify: After you upload your .zip file, re-download it from WebCampus. Extract it, compile it and
verify that it compiles and runs on the NoMachine virtual machines or directly on the ECC systems.
 Code that does not compile will be heavily penalized –may even cost you your entire grade–.
Executables that do not work 100% will receive partial grade points.
 It is better to hand in code that compiles and performs partial functionality, rather than
broken code. You may use your Documentation file to mention what you could not get to
work exactly as you wanted in the given timeframe of the Project.
Late Submission:
A project submission is "late" if any of the submitted files are time-stamped after the due date and
time. Projects will be accepted up to 24 hours late, with 20% penalty
