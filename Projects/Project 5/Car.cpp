#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include <string.h>

using namespace std;

Car::Car() {
  m_throttle = 0;
  m_plates = new char [MAX_SIZE];
  m_plates[0] = '\0';
  cout << "Car #" << m_vin << ": Default-ctor" << endl;
}

Car::Car(const char* plates, int vin, float lla[])
:Vehicle(vin, lla)
{
  m_throttle = 0;
  m_plates = new char [MAX_SIZE];
  strcpy(m_plates, plates);
  cout << "Car #" << m_vin << ": Parameterized-ctor" << endl;
}

Car::Car(const Car& other):Vehicle(other) {
  m_plates = new char[MAX_SIZE];
  strcpy(m_plates, other.m_plates);
  cout << "Car #" << m_vin << ": Copy-ctor" << endl;
}

Car::~Car() {
  cout << "Car #" << m_vin << ": Dtor" << endl;
  delete [] m_plates;
  m_plates = NULL;
}

Car& Car::operator=(const Car& other) {
  Vehicle::operator=(other);
  strcpy(m_plates, other.m_plates);
  m_throttle = other.m_throttle;
  cout << "Car #" << m_vin << ": Assignment" << endl;
  return *this;
}

char* Car::getm_plates() const {
  return m_plates;
}

int Car::getm_throttle() const {
  return m_throttle;
}

void Car::setm_plates(const char* plates) {
  strcpy(m_plates, plates);
}

void Car::setm_throttle(int throttle) {
  m_throttle = throttle;
}

void Car::drive(int throttle) {
  setm_throttle(throttle);
}

void Car::move(float* action) {
  m_lla[0] = action[0];
  m_lla[1] = action[1];
  m_lla[2] = action[2];
  cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75"
  << endl;
  drive(75);
}

std::ostream& operator<<(std::ostream& stream, const Car& car) {
  float* location = car.getm_lla();
  stream << "Car #" << car.getm_vin() << "Plates: " << car.getm_plates() <<
   ", Throttle: " << car.getm_throttle() << " @ [" << location[0] << ","
  << location[1] << "," << location[2] << "]";
  return stream;
}
