#include <iostream>
#include "Vehicle.h"
#include <string.h>

using namespace std;

Vehicle::Vehicle() {
  for(int i = 0; i < 3; i++) {
    m_lla[i] = 0.0;
  }
  cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(const float* lla) {
  for(int i = 0; i < 3; i++) {
    m_lla[i] = lla[i];
  }
  cout << "Vehicle: Parametrized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle& other) {
  for(int i = 0; i < 3; i++) {
    m_lla[i] = other.m_lla[i];
  }
  cout << "Vehicle: Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
  cout << "Vehicle: Dtor" << endl;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
  for(int i = 0; i < 3; i++) {
    m_lla[i] = other.m_lla[i];
  }
  cout << "Vehicle: Assignment" << endl;
  return *this;
}

const float *Vehicle::getm_lla() const {
  return m_lla;
}

void Vehicle::setm_lla(const float* value) {
  for(int i = 0; i < 3; i++) {
    m_lla[i] = value[i];
  }
}

std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle) {
  vehicle.serialize(stream);
  return stream;
}

void serialize(std::ostream& stream) const {
  stream << "Vehicle @ [" << m_lla[0] << ',' << m_lla[1] << ',' << m_lla[2] <<
  "]";
}
