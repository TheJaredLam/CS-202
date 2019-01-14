#include <iostream>
#include "Sensor.h"
#include "mystring.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

using namespace std;

Sensor::Sensor() {
  myStringCopy(m_type, "none");
  m_extracost = 0.0;
}

Sensor& Sensor::operator =(const Sensor& other) {
  if(this != &other) {
    myStringCopy(m_type, other.m_type);
    m_extracost = other.m_extracost;
  }
  return *this;
}

Sensor::Sensor(const char *type) {
  if(myStringCompare(type, "gps") == 0) {
    myStringCopy(m_type, type);
    gps_cnt++;
    m_extracost = 5.0;
  }
  else if(myStringCompare(type, "camera") == 0) {
    myStringCopy(m_type, type);
    camera_cnt++;
    m_extracost = 10.0;
  }
  else if(myStringCompare(type, "lidar") == 0) {
    myStringCopy(m_type, type);
    lidar_cnt++;
    m_extracost = 15.0;
  }
  else if(myStringCompare(type, "radar") == 0) {
    myStringCopy(m_type, type);
    radar_cnt++;
    m_extracost = 20.0;
  }
  else if(myStringCompare(type, "none") == 0) {
    myStringCopy(m_type, type);
    m_extracost = 0.0;
  }
  else {
    cout << "Not valid input" << endl;
  }
}

Sensor::Sensor(const Sensor& other) {
  myStringCopy(m_type, other.m_type);
  m_extracost = other.m_extracost;
}

const char *Sensor::getm_type() {
  return m_type;
}

float Sensor::getm_extracost() {
  return m_extracost;
}

int Sensor::getgps_cnt() {
  return gps_cnt;
}

int Sensor::getcamera_cnt() {
  return camera_cnt;
}

int Sensor::getlidar_cnt() {
  return lidar_cnt;
}

int Sensor::getradar_cnt() {
  return radar_cnt;
}

void Sensor::setm_type(const char *newtype) {
  myStringCopy(m_type, newtype);
}

void Sensor::setm_extracost(float newextracost) {
  m_extracost = newextracost;
}

void Sensor::resetgps_cnt() {
  gps_cnt = 0;
}

void Sensor::resetcamera_cnt() {
  camera_cnt = 0;
}

void Sensor::resetlidar_cnt() {
  lidar_cnt = 0;
}

void Sensor::resetradar_cnt() {
  radar_cnt = 0;
}

bool Sensor::operator ==(const Sensor& compare) const {
  return((myStringCompare(compare.m_type, m_type) == 0) &&
  (compare.m_extracost == m_extracost));
}
