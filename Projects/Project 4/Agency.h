#ifndef Agency_h
#define Agency_h
#include "Car.h"

cosnt int SIZE = 256;

class Agency {
  public:
    Agency();
    char *getm_name();
    int getm_zipcode();
    Car *getm_inventory();
    void setm_name(char *newname);
    Car* operator[](int);
    void readAllData(char filename[]);
    void printAllData();
    void printAvailableCars();
    Car& biggestcost();
  private:
    char m_name[SIZE];
    int m_zipcode;
    Car m_inventory[5];
};
#endif
