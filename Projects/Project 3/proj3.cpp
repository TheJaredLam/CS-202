//Jared Lam CS 202 proj3.h
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_CARS = 5;
const int MAX_SIZE = 256;
const int NUMBER_OF_AGENCY = 3;
const int ZIP_CODE = 5;
char * myStringCopy(char * destination, const char * source);
size_t myStringLength(const char * str);
int myStringCompare(const char *str1, const char *str2);
char * myStringCat(char * destination, const char * source);

class RentalCar
{
   public:

     RentalCar() {
       m_year = 0;
       price = 0;
       m_available = false;
     }
     RentalCar(int carm_year, char *carm_make,char *carm_model, float carprice,
     bool carm_available) {
       m_year = carm_year;
       myStringCopy(m_make, carm_make);
       myStringCopy(m_model, carm_model);
       price = carprice;
       m_available = carm_available;
     }
     int getm_year() {
       return m_year;
     }
     char *getm_make() {
       return m_make;
     }
     char *getm_model() {
       return m_model;
     }
     float getprice() {
       return price;
     }
     bool getm_available() {
       return m_available;
     }
     void setm_year(int newYear) {
       m_year = newYear;
     }
     void setm_make(char *new_make) {
       myStringCopy(m_make, new_make);
     }
     void setm_model(char *new_model) {
       myStringCopy(m_model, new_model);
     }
     void setprice(float newprice) {
       price = newprice;
     }
     void setm_available(bool new_available) {
       m_available = new_available;
     }
     void stream(ostream &os) {
       os << m_year << ' ' << m_make << ' ' << m_model << ", $"
          << setprecision(2) << fixed << price << "per day, Available: "
          << boolalpha << m_available << endl;
     }
     void print() {
       stream(cout);
     }
     void estimateCost();
   private:
     int m_year;
     char m_make[MAX_SIZE];
     char m_model[MAX_SIZE];
     float price;
     bool m_available;
};

struct RentalAgency_ADT
{
  char name[MAX_SIZE];
  int zipcode[ZIP_CODE];
  RentalCar inventory[NUMBER_OF_CARS];
};

void readf(char filename[], RentalAgency_ADT *agency);
void rentACar(RentalAgency_ADT *agency, int aindex, int days, int car_index);
void writeToCarFile(const char *filename, RentalAgency_ADT *agency);
void carsToStream(ostream &os, RentalAgency_ADT *agency, bool available_only);
void expensiveCar(RentalAgency_ADT *agency);
void printn(RentalAgency_ADT *agency);

int main()
{
  char inputf[MAX_SIZE];
  char outputf1[MAX_SIZE];
  RentalAgency_ADT agency[NUMBER_OF_AGENCY];
  RentalCar vehicle[NUMBER_OF_CARS];
  int appointment, days, car_index, type = 1, rental_agency;
  while(1) {
    cout << "Options: "<< endl;
    cout << "1- input file name"<< endl;
    cout << "2- print terminal"<< endl;
    cout << "3- Estimate car rental cost"<< endl;
    cout << "4- find expensive car"<< endl;
    cout << "5- output file name"<< endl;
    cout << "6- exit program"<< endl;
    cout << "Please enter your option: "<< endl;
    cin >> appointment;
    switch(appointment) {
      case 1:
         cout << "Enter input file name: "<< endl;
         cin >> inputf;
         readf(inputf, agency);
         break;
      case 2:
         printn(agency);
         break;
      case 3:
        cout << "Enter the agency (number from 0 to 2): "<< endl;
        cin >> rental_agency;
        cout << "Enter which cars to rent (number from to 0 to 4): "<< endl;
        cin >> car_index;
        cout << "Enter how many days to rent: "<< endl;
        cin >> days;
        rentACar(agency, rental_agency, days, car_index);
        break;
      case 4:
        expensiveCar(agency);
        break;
      case 5:
        //different names than the input file
        cout << "Enter output file name: "<< endl;
        cin >> outputf1;
        remove(outputf1);
        writeToCarFile(outputf1, agency);
        break;
      case 6:
        return 0;
        break;
      default:
        cout << "Invalid option"<< endl;
        break;
    }
  }
  return 0;
}

void readf(char filename[], RentalAgency_ADT *agency)
{
  fstream file;
  int year;
  char make[MAX_SIZE];
  char model[MAX_SIZE];
  float price;
  bool available;
  int zipcode;
  file.open(filename, fstream::in);
  if(file.is_open()) {
    for(int n = 0; n < NUMBER_OF_AGENCY && !file.eof(); n++) {
      file >> agency->name;
      file >> zipcode;
      int *a = agency->zipcode;
      for(int c = ZIP_CODE - 1; c >= 0; c--) {
        *(a + c) = zipcode % 10;
        zipcode /= 10;
      }
      RentalCar *vehicle = agency->inventory;
      for(int i = 0; i < NUMBER_OF_CARS && !file.eof(); i++) {
        file >> year;
        vehicle->setm_year(year);
        file >> make;
        vehicle->setm_make(make);
        file >> model;
        vehicle->setm_model(model);
        file >> price;
        vehicle->setprice(price);
        file >> available;
        vehicle->setm_available(available);
        vehicle++;
      }
      agency++;
    }
    file.close();
  }
}

void carsToStream(ostream &os, RentalAgency_ADT *agency, bool available_only)
{
  for(int a = 0; a < NUMBER_OF_AGENCY; a++) {
    os << agency->name << ' ';
    int *zipcode = agency->zipcode;
    for(int c = 0; c < ZIP_CODE; c++) {
      os << *(zipcode + c);
    }
    os << endl;
    RentalCar * vehicle = agency-> inventory;
    for(int n = 0; n < NUMBER_OF_CARS; n++) {
      if(!available_only || vehicle->getm_available()) {
        vehicle->stream(os);
      }
      vehicle++;
    }
    agency++;
  }
}

void printn(RentalAgency_ADT *agency)
{
  carsToStream(cout, agency, true && false);
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

void rentACar(RentalAgency_ADT *agency, int aindex, int days, int car_index)
{
  if(aindex < NUMBER_OF_AGENCY && aindex >= 0) {
    RentalCar *vehicle = (agency + aindex)->inventory;
    if(index > NUMBER_OF_CARS || index < 0) {
      cout << "Invalid car index" << endl;
      return;
    }
    cout << "Total cost: " << "$" << (vehicle + index)->getprice * days
    << endl;
  }
  else {
    cout << "Choose another option please." << endl;
  }
}

void expensiveCar(RentalAgency_ADT *agency)
{
  RentalCar *vehicle = NULL;
  RentalAgency_ADT *input = agency;
  for(int index = 0; index < NUMBER_OF_AGENCY; index++) {
    RentalCar *cur_car = input->inventory;
    for(int car_index = 0; car_index < NUMBER_OF_CARS; car_index++) {
      if(vehicle == NULL || cur_car->getprice() > vehicle->getprice()) {
        vehicle = cur_car;
      }
      cur_car++;
    }
    input++;
  }
  cout << "The most expensive car is: " << vehicle->getm_year() << ' ' <<
  vehicle->getm_make() << ' ' << vehicle->getm_model() << ' ' <<
  vehicle->getprice() << ' ' << boolalpha << vehicle->getm_available() << endl;
}

void writeToCarFile(const char *filename, RentalAgency_ADT *agency)
{
  ofstream file;
  file.open(filename, fstream::out);
  carsToStream(file, agency, true);
  file.close();
}
