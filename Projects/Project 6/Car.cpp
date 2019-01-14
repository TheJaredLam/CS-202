#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include <string.h>

using namespace std;

Car::Car()
 : m_throttle(0) {
  cout << "Car: Default-ctor" << endl;
}

Car::Car(float lla[])
 : Vehicle(lla), m_throttle(0) {
  cout << "Car: Parameterized-ctor" << endl;
}

Car::Car(const Car& other)
 : Vehicle(other), m_throttle(other.m_throttle) {
   cout << "Car: Copy-ctor" << endl;
}

Car::~Car() {
   cout << "Car: Dtor" << endl;
}

Car& Car::operator=(const Car& other) {
  Vehicle::operator=(other);
  m_throttle = other.m_throttle;
  cout << "Car: Assignement" << endl;
  return * this;
}

int Car::getm_throttle() const {
  return m_throttle;
}

void Car::setm_throttle(int throttle) {
  m_throttle = throttle;
}

void Car::drive(int throttle) {
  setm_throttle(throttle);
}

void Car::move(const float* action) {
  setm_lla(action);
  cout << "Car: DRIVE to " << m_lla[0] << ',' << m_lla[1] << ',' << m_lla[2]
  << ", with throttle @ 75" << endl;
  drive(75);
}

void Car::serialize(std::ostream& stream) const {
  stream << "Car: Throttle: " << m_throttle << "  @ [" << m_lla[0] << ','
  << m_lla[1] << ',' << m_lla[2] << "]";
}
