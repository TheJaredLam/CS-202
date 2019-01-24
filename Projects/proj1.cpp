// Project 1 by Jared Lam for CS 202
#include <iostream>
#include <fstream>

using namespace std;

const int NUMBER_OF_NAMES = 10;
const int SIZE_NAME = 20;
void myStringCopy(char destination [], const char source []);
int myStringLength(const char str []);
int myStringCompare(const char str1 [], const char str2 []);
void swap(char str1[SIZE_NAME], char str2[SIZE_NAME]);
void readf(char filename[], char names[NUMBER_OF_NAMES][SIZE_NAME]);
void printn(char names[NUMBER_OF_NAMES][SIZE_NAME]);
void sortletters(char names[NUMBER_OF_NAMES][SIZE_NAME]);
void writef(char filename[], char names[NUMBER_OF_NAMES][SIZE_NAME]);
void sortsize(char names[NUMBER_OF_NAMES][SIZE_NAME]);

int main()
{
  char inputf[24];
  char outputf1[24];
  char outputf2[24];
  ofstream sortfile1;
  ofstream sortfile2;
  char namesa[NUMBER_OF_NAMES][SIZE_NAME];

  cout << "Enter input file name: "<< endl;
  cin >> inputf;
  readf(inputf, namesa);

  cout << "Enter output length file name: "<< endl; //different names than the input file
  cin >> outputf1;
  sortfile1.open(outputf1, fstream::out);

  cout << "Enter output alphabet file name: "<< endl;
  cin >> outputf2;
  sortfile2.open(outputf2, fstream::out);

  cout << "Unsorted Data (Original Input Order and Name)"<< endl;
  cout << "==========================="<< endl;
  printn(namesa);

  cout << "Sorted-by-Length Data (Original Input Order and Name)"<< endl;
  cout << "=========================="<< endl;
  sortsize(namesa);
  printn(namesa);
  writef(outputf1, namesa);

  cout << "Alphabetcially Sorted Data (Original Input Order and Name)"<< endl;
  cout << "=========================="<< endl;
  sortletters(namesa);
  printn(namesa);
  writef(outputf2, namesa);

  return 0;
}

void myStringCopy(char destination [], const char source [])
{
  int name = 0;
  while(source[name] != '\0')
  {
    destination[name] = source[name];
    name++;
  }
  destination[name] = '\0';
}

int myStringLength(const char str [])
{
  int size = 0;
  for(; str[size] != '\0'; size++);
  return size;
}

int myStringCompare(const char str1 [], const char str2 [])
{
  int size = max(myStringLength(str1), myStringLength(str2));
  for(int index = 0; index < size; index++) {
    if(str1[index] < str2[index]) return -1;
    if(str2[index] < str1[index]) return 1;
  }
  return 0;
}

void swap(char str1[SIZE_NAME], char str2[SIZE_NAME])
{
  char temp[SIZE_NAME];
  myStringCopy(temp, str1);
  myStringCopy(str1, str2);
  myStringCopy(str2, temp);
}

void readf(char filename[], char names[NUMBER_OF_NAMES][SIZE_NAME])
{
  fstream file;
  file.open(filename, fstream::in);
  if(file.is_open()) {
    for(int n = 0; n < NUMBER_OF_NAMES && !file.eof(); n++) {
      names[n][0] = '0' + n;
      names[n][1] = ' ';
      file.getline(&names[n][2], SIZE_NAME - 3);
    }
    file.close();
  }
}

void printn(char names[NUMBER_OF_NAMES][SIZE_NAME])
{
  for(int people = 0; people < NUMBER_OF_NAMES; people++) {
    cout << names[people] << endl;
  }
}

void sortletters(char names[NUMBER_OF_NAMES][SIZE_NAME])
{
  bool swapped = false;
  do {
    swapped = false;
    for(int n = 0; n < NUMBER_OF_NAMES - 1; n++) {
      if(myStringCompare(&names[n][2], &names[n + 1][2]) > 0) {
        swap(names[n], names[n + 1]);
        swapped = true;
      }
    }
  } while(swapped);
}

void writef(char filename[], char names[NUMBER_OF_NAMES][SIZE_NAME])
{
  ofstream file;
  file.open(filename);
  for(int people = 0; people < NUMBER_OF_NAMES; people++) {
    file << names[people] << endl;
  }
  file.close();
}

void sortsize(char names[NUMBER_OF_NAMES][SIZE_NAME])
{
  bool swapped = false;
  do {
    swapped = false;
    for(int n = 0; n < NUMBER_OF_NAMES - 1; n++) {
      if(myStringLength(names[n]) > myStringLength(names[n + 1])) {
        swap(names[n], names[n + 1]);
        swapped = true;
      }
    }
  } while(swapped);
}
