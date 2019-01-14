#include <iostream>
#include <fstream>
#include "Car.h"
#include "Agency.h"
#include "mystring.h"

using namespace std;
const int MAX = 256;
const int ZIP_CODE = 5;
const int NUMBER_OF_CARS = 5;

Agency::Agency() {};
char *Agency::getm_name() {
  return m_name;
}

int Agency::getm_zipcode() {
  return m_zipcode;
}

Car *Agency::getm_inventory() {
  return m_inventory;
}

void Agency::setm_name(char *newname) {
  myStringCopy(m_name, newname);
}

Car* Agency::operator[](int appoint) {
  if(appoint < 5) {
    Car *order - m_inventory;
    for(int m = 0; m < appoint; m++) {
      order++;
    }
    return order;
  }
  else {
    return nullptr;
  }
}
void Agency::readAllData(char filename[]) {
  ifstream file;
  int year;
  char make[MAX];
  char model[MAX];
  float price;
  bool available;
  char person[MAX];
  char sensor[MAX];
  file.open(filename, ios::in);
  if(file.is_open()) {
    file >> m_name;
    file >> m_zipcode;
    Car *vehicle = m_inventory;
    for(int i = 0; i < NUMBER_OF_CARS && !file.eof(); i++) {
      file >> year;
      vehicle->setm_year(year);
      file >> make;
      vehicle->setm_make(make);
      file >> model;
      vehicle->setm_model(model);
      file >> price;
      vehicle->setm_baseprice(price);
      file >> sensor;
      char *type = sensor + 1;
      while(1) {
        char *p = type;
        while(*p != '}' && *p != '\0') {
          p++;
        }
        if(*p == '}') {
          if(p == type) {
            break;
          }
          *p = '\0';
          Sensor s(type);
          *vehicle = *vehicle + s;
          break;
        }
        else {
          Sensor s(type);
          *vehicle = *vehicle + s;
          file >> sensor;
          type = sensor;
        }
      }
      file >> available;
      if(!available) {
        file >> person;
        vehicle->setm_owner(person);
      }
      vehicle->setm_available(available);
      vehicle++;
    }
    file.close();
  }
}

void Agency::printAllData() {
  cout << m_name << ' ' << m_zipcode << endl;
  Car * vehicle = m_inventory;
  for(int p = 0; p < 5; p++) {
    vehicle->print();
    vehicle++;
  }
}

void Agency::printAvailableCars() {
  cout << m_name << endl;
  Car * vehicle = m_inventory;
  for(int p = 0; p < 5; p++) {
    if(vehicle->getm_available()) {
      vehicle->print();
    }
    vehicle++;
  }
}

Car& Agency::biggestcost() {
  Car *order = m_inventory;
  Car *money = m_inventory;
  for(int m = 0; m < NUMBER_OF_CARS; m++) {
    if(order->getm_available()) {
      if(order->getm_finalprice() > money->getm_finalprice()) {
        money = order;
      }
    }
    order++;
  }
  return *money;
}
