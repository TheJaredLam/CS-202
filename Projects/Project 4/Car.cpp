#include <iostream>
#include <iomanip>
#include "Car.h"
#include "mystring.h"

using namespace std;

Car::Car() {
  *m_make = '\0';
  *m_model = '\0';
  m_year = 0;
  m_baseprice = 0;
  m_finalprice = 0;
  m_available = false;
  *m_owner = '\0';
  sensorinformation = 0;
}

Car::Car(char *make, char *model, int year, float baseprice, float finalprice
, Sensor *sensors, int count) {
  myStringCopy(m_make, make);
  myStringCopy(m_model, model);
  m_year = year;
  Sensor *machine = m_sensors;
  Sensor *motion = sensors;
  sensorinformation = count;
  for(int m = 0; m < count; m++) {
    *machine++ = *motion++;
  }
  m_baseprice = baseprice;
  m_finalprice = finalprice;
  m_available = true;
}

Car::Car(Car &vehicle) {
  myStringCopy(m_make, vehicle.m_make);
  myStringCopy(m_model, vehicle.m_model);
  m_year = vehicle.m_year;
  Sensor *machine = vehicle.m_sensors;
  Sensor *motion = vehicle.m_sensors;
  sensorinformation = vehicle.sensorinformation;
  for(int m = 0; m < count; m++) {
    *machine++ = *motion++;
  }
  m_baseprice = vehicle.m_baseprice;
  m_finalprice = vehicle.m_finalprice;
  m_available = vehicle.m_available;
  myStringCopy(m_owner, vehicle.m_owner);
}

char *Car::getm_make() {
  return m_make;
}

char *Car::getm_model() {
  return m_model;
}

int Car::getm_year() {
  return m_year;
}

Sensor *Car::getm_sensors() {
  return m_sensors;
}

float Car::getm_baseprice() {
  return m_baseprice;
}

float Car::getm_finalprice() {
  return m_finalprice;
}

bool Car::getm_available() {
  return m_available;
}

char *Car::getm_owner() {
  return m_owner;
}

void Car::setm_make(char *newmake) {
  myStringCopy(m_make, newmake);
}

void Car::setm_model(char *newmodel) {
  myStringCopy(m_model, newmodel);
}

void Car::setm_year(int newyear) {
  m_year = newyear;
}

void Car::setm_baseprice(float newbaseprice) {
  m_baseprice = newbaseprice;
}

void Car::setm_available(bool newavailable) {
  m_available = newavailable;
}

void Car::setm_owner(char *newowner) {
  myStringCopy(m_owner, newowner);
}

void Car::updatePrice(float price) {
  m_finalprice = price;
}

void Car::print() {
  cout << m_year << ' ' << m_make << ' ' << m_model << ", $"
  << setprecision(2) << fixed << m_baseprice << " per day, {";
  Sensor *location = m_sensors;
  for(int j = 0; j < sensorinformation; j++) {
    if(myStringCompare(location->getm_type(), "none") != 0) {
      if(j != 3 && j > 0) {
        cout << ' ';
      }
      cout << location->getm_type();
    }
    location++;
  }
  cout << "} Available: " << boolalpha << m_available;
  if(m_available == 0) {
    cout << ' ' << m_owner;
  }
  cout << endl;
}

void Car::estimateCost(int days) {
  cout << "Total cost: " << "$" << m_finalprice * days << endl;
}

Car& Car::operator+(const Sensor &track) {
  if(sensorinformation > 2) {
    return *this;
  }
  Sensor * sound = m_sensors;
  for(int o = 0; o < sensorinformation; o++) {
    sound++;
  }
  sensorinformation++;
  *sound = track;
  return *this;
}

Car& Car::operator+(char *person) {
  setm_owner(person);
  return *this;
}
