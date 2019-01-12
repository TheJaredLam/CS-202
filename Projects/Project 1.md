CS 202 - Computer Science II Project 1
Due date (FIXED): Wednesday, 9/6/2017, 11:59 pm
Objectives: The two main objectives of this project is to test your ability to: a) use C++ I/O (console and file), and b) design, implement and test a solution to a given problem. In addition, a review of your knowledge of C-style strings and multi-dimensional arrays will be necessary. This project will also test your ability to create, compile and run a program in a Linux environment and establish your ability to upload your program and supporting documentation to WebCampus.
Description:
For this project you will write a program to: a) read-in the 10 first names from a file (the file is a priori known to have exactly 10 entries, of a maximum length of 8 letters each) into a two- dimensional character array, b) output the names to the terminal with each one preceded by a number indicating its original order in the list, c) sort the list of names, and then d) output the sorted names both to the terminal and to a file, again with each one preceded by its corresponding original order in the list. Although an example input file (Names.txt) is provided, for grading purposes your project will be tested against a file that we will supply but will not be provided to you beforehand. Our test file will be in the same format as the example input file.
The following minimum functionality and structure is required:
 Ask the user for the input and output file names.
 Read in the list of names from the desired input file.
 Store the names list in a two-dimensional character array
(Use character arrays (i.e., C-style) to hold your strings)
 Print out the unsorted list of names to the terminal, preceded by their original order in
the input file.
 Sort the list of names alphabetically.
 Print the list of sorted names to the terminal, preceded by their original order in the input
file.
 Write the list of sorted names to a different output file (e.g. SortedNames.txt), preceded by
their original order in the input file.
 Write multiple functions.
 Write your own C-string copy, C-string compare (or other) functions as needed.
The following are a list of restrictions:
 No usage of external libraries for C-string manipulation is allowed (e.g. <cstring> <string.h>), or any std::string libraries and data types.
 No libraries except <iostream> and <fstream> are allowed.
 No global variables or constants except: a) the fixed number of names, and b) the maximum
C-string size.
 No usage of pointers or dynamic memory.

Example Input File (Names.txt) Contents: Victor
Eve
Juliet
Hector Danielle Romeo Oscar June Ares Dannae
Example Output (to Terminal and/or File): Unsorted Data (Original Input Order and Name)
=============================
0 Victor
1 Eve
2 Juliet
3 Hector 4 Danielle 5 Romeo 6 Oscar
7 June
8 Ares
9 Dannae
Sorted Data (Original Input Order and Name)
===========================
8 Ares
4 Danielle
9 Dannae
1 Eve
3 Hector
2 Juliet
7 June
6 Oscar
5 Romeo
0 Victor

The completed project should have the following properties:
 Written, compiled and tested using Linux.
 It must compile successfully using the g++ compiler on department machines. Instructions how to remotely connect to department machines are included in the Projects folder in WebCampus.
 The code must be commented and indented properly.
Header comments are required on all files and recommended for the rest of the program. Descriptions of functions commented properly.
 A one page (minimum) typed sheet documenting your code. This should include the overall purpose of the program, your design, problems (if any), and any changes you would make given more time.
Turn in: Compressed .cpp file and project documentation.

Submission Instructions:
 You will submit your work via WebCampus
 Name your code file proj1.cpp
 If you have header file, name it proj1.h
 Compress your: 1. Source code
2. Documentation
Do not include executable
 Name the compressed folder:
PA#_Lastname_Firstname.zip
([PA] stands for [ProjectAssignment], [#] is the Project number) Example: PA1_Smith_John.zip
Late Submission:
A project submission is "late" if any of the submitted files are time-stamped after the due date and time. Projects will be accepted up to 24 hours late, with 20% penalty
