#include <iostream>
#include "Vehicle.h"
#include <string.h>

using namespace std;
int Vehicle::s_idegen = 0;
Vehicle::Vehicle():m_vin(s_idegen) {
  m_lla = new float[3];
  m_lla[0] = 0; m_lla[1] = 0; m_lla[2] = 0;
  s_idegen++;
  cout << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

Vehicle::Vehicle(int vin, float lla[])
:m_vin(vin > s_idegen ? vin : s_idegen) {
  m_lla = new float[3];
  m_lla[0] = lla[0]; m_lla[1] = lla[1]; m_lla[2] = lla[2];
  s_idegen = vin + 1;
  cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle& other):m_vin(s_idegen) {
  m_lla = new float[3];
  m_lla[0] = other.m_lla[0]; m_lla[1] = other.m_lla[1];
  m_lla[2] = other.m_lla[2];
  s_idegen++;
  cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
  cout << "Vehicle #" << m_vin << ": Dtor" << endl;
  delete [] m_lla;
  m_lla = NULL;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
  delete [] m_lla;
  m_lla = new float[3];
  m_lla[0] = other.m_lla[0]; m_lla[1] = other.m_lla[1];
  m_lla[2] = other.m_lla[2];

  cout << "Vehicle #" << m_vin << ": Assignment" << endl;
  return *this;
}

int Vehicle::getm_vin() const {
  return m_vin;
}

float *Vehicle::getm_lla() const {
  return m_lla;
}

void Vehicle::setm_lla(float value, int lla) {
  m_lla[lla] = value;
}

void Vehicle::move(float* action) {
  cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}

int Vehicle::getIdgen() {
  return Vehicle::s_idegen;
}

std::osteam& operator<<(std::ostream& stream, const Vehicle& vehicle) {
  float* location = vehicle.getm_lla();
  stream << "Vehicle #" << vehicle.getm_vin() << " @ [" << location[0] << ","
  << location[1] << "," << location[2] << "]";
  return stream;
}
