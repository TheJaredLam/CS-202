//This is project 2 by Jared Lam for CS-202
#include <iostream>
#include <fstream>

using namespace std;

struct Car {
  int year;
  char make[10];
  char model[10];
  float price;
  bool available;
};
const int NUMBER_OF_CARS = 5;
const int MAX_SIZE = 255;
char * myStringCopy(char * destination, const char * source);
size_t myStringLength(const char * str);
int myStringCompare(const char *str1, const char *str2);
char * myStringCat(char * destination, const char * source);
void swap(Car * car1, Car * car2);
void readf(char filename[], Car cars[]);
void printn(Car cars[]);
void writeToCarFile(const char filename[], Car cars[]);
void sortPrice(Car cars[]);
void priceDay(Car cars[], int days);
void rentACar(Car cars[], int days, int index);
void myCarCopy(Car * dest, const Car * source);
void carsToStream(ostream &os, Car cars[]);

int main()
{
  char inputf[24];
  char outputf1[24];
  Car cars[5];
  int appointment, type = 1, days, carindex;
  while(1) {
    cout << "Options: "<< endl;
    cout << "1- input file name"<< endl;
    cout << "2- print terminal"<< endl;
    cout << "3- output file name"<< endl;
    cout << "4- sort"<< endl;
    cout << "5- days to rent"<< endl;
    cout << "6- car rent"<< endl;
    cout << "7- exit program"<< endl;
    cout << "Please enter your option: "<< endl;
    cin >> appointment;
    switch(appointment) {
      case 1:
         cout << "Enter input file name: "<< endl;
         cin >> inputf;
         readf(inputf, cars);
         break;
      case 2:
         printn(cars);
         break;
      case 3:
        //different names than the input file
        cout << "Enter output file name: "<< endl;
        cin >> outputf1;
        remove(outputf1);
        writeToCarFile(outputf1, cars);
        break;
      case 4:
        sortPrice(cars);
        break;
      case 5:
        cout << "Enter how many days to rent a car: "<< endl;
        cin >> days;
        priceDay(cars, days);
        break;
      case 6:
        cout << "Enter which cars to rent (number from 1 to 5): "<< endl;
        cin >> carindex;
        cout << "Enter how many days to rent: "<< endl;
        cin >> days;
        rentACar(cars, days, carindex);
        break;
      case 7:
        return 0;
        break;
      default:
        cout << "Invalid option"<< endl;
        break;
    }
  }
  return 0;
}

char * myStringCopy(char * destination, const char * source)
{
  for(; *source != '\0'; source++, destination++) {
    * destination = *source;
  }
  * destination = '\0';
  return destination;
}

size_t myStringLength(const char * str)
{
  int size = 0;
  for(; *str != '\0'; str++) {
    size++;
  }
  return size;
}

int myStringCompare(const char *str1, const char *str2)
{
  while(* str1 != '\0' && * str2 != '\0') {
    if(* str1 < * str2) return -1;
    if(* str2 < * str1) return 1;
  }
  if(str1 == NULL && str2 != NULL) return -1;
  if(str2 == NULL && str1 != NULL) return 1;
  return 0;
}

char * myStringCat(char * destination, const char * source)
{
  unsigned int dest_len = myStringLength(destination);
  unsigned int src_len = myStringLength(source);
  unsigned int j;
  for(j = 0; j < src_len; j++) {
    *(destination + dest_len + j) = *(source + j);
  }
  *(destination + dest_len + src_len) = '\0';
  return destination;
}

void swap(Car * car1, Car * car2)
{
  Car temp;
  myCarCopy(&temp, car1);
  myCarCopy(car1, car2);
  myCarCopy(car2, &temp);
}

void readf(char filename[], Car cars[])
{
  fstream file;
  file.open(filename, fstream::in);
  if(file.is_open()) {
    for(int n = 0; n < NUMBER_OF_CARS && !file.eof(); n++) {
      file >> cars[n].year;
      file >> cars[n].make;
      file >> cars[n].model;
      file >> cars[n].price;
      file >> cars[n].available;
    }
    file.close();
  }
}

void printn(Car cars[])
{
  carsToStream(cout, cars);
}

void writeToCarFile(const char filename[], Car cars[])
{
  ofstream file;
  file.open(filename, fstream::out);
  carsToStream(file, cars);
  file.close();
}

void sortPrice(Car cars[])
{
  bool swapped = false;
  do {
    swapped = false;
    for(int n = 0; n < NUMBER_OF_CARS - 1; n++) {
      if(cars[n].price > cars[n + 1].price) {
        swap(cars[n], cars[n + 1]);
        swapped = true;
      }
    }
  } while(swapped);
}

void priceDay(Car cars[], int days)
{
  sortPrice(cars);
  for(int c = 0; c < NUMBER_OF_CARS; c++) {
    if(cars[c].available == true) {
      cout << cars[c].year << ' ' << cars[c].make << ' ' << cars[c].model << ','
      << ' ' << "Total cost: " << "$" << cars[c].price * days << endl;
    }
  }
}

void rentACar(Car cars[], int days, int index)
{
  if(index > NUMBER_OF_CARS || index < 1) {
    cout MM "Invalid car index" << endl;
    return;
  }
  if(cars[index - 1].available == true) {
    cout << "This is available" << endl;
    cout << "Total cost: " << "$" << cars[index].price * days << endl;
  }
  else {
    cout << "Not available" << endl;
    cout << "Choose another option please." << endl;
  }
}

void myCarCopy(Car * dest, const Car * source)
{
  dest->year = source->year;
  myStringCopy(dest->make, source->make);
  myStringCopy(dest->model, source->model);
  dest->price = source->price;
  dest->available = source->available;
}

void carsToStream(ostream &os, Car cars[])
{
  for(int n = 0; n < NUMBER_OF_CARS; n++) {
    os << cars[n].year << ' ';
    os << cars[n].make << ' ';
    os << cars[n].model << ' ';
    os << "$" cars[n].price << ' ' << "per day" << ',' << ' ';
    os << boolalpha << "Available: " << cars[n].available << endl;
  }
}
