#include <iostream>
#include "DataType.h"

DataType::DataType() {
  m_intVal = 0;
  m_doubleVal = 0.0;
}

DataType::DataType(int intVal, double doubleVal) {
  m_intVal = intVal;
  m_doubleVal = doubleVal;
}

DataType::DataType(const DataType& srcData) {
  m_intVal = srcData.m_intVal;
  m_doubleVal = srcData.m_doubleVal;
}

bool DataType::operator==(const DataType& other_dataType) const {
  if(m_intVal == other_dataType.m_intVal && m_doubleVal == other_dataType.m_doubleVal) {
    return true;
  }
  else {
    return false;
  }
}

DataType& DataType::operator= (const DataType& other_dataType) {
  m_intVal = other_dataType.m_intVal;
  m_doubleVal = other_dataType.m_doubleVal;
  return *this;
}

DataType& DataType::operator* (int multiple) {
  m_intVal *= multiple;
  m_doubleVal *= multiple;
  return *this;
}

int DataType::GetIntVal() const {
  return m_intVal;
}

void DataType::SetIntVal(int i) {
  m_intVal = i;
}

double DataType::GetDoubleVal() const {
  return m_doubleVal;
}

void DataType::SetDoubleVal(double d) {
  m_doubleVal = d;
}

std::ostream & operator<<(std::ostream & os, const DataType & dataType) {
  os << "{" << dataType.m_intVal << "," << dataType.m_doubleVal << "}";
  return os;
}

std::ostream & operator>>(std::ostream & is, DataType & dataType) {
  is >> dataType.m_intVal >> dataType.m_doubleVal;
  return is;
}
