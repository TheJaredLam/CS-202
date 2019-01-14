#ifndef Car_H
#define Car_H
#include "Sensor.h"

const int MAXIUMUM = 256;

class Car {
   public:
     Car();
     Car(char *make, char *model, int year, float baseprice, float finalprice
     , Sensor *sensors, int count);
     Car(Car &vehicle);
     char *getm_make();
     char *getm_model();
     int getm_year();
     Sensor *getm_sensors();
     float getm_baseprice();
     float getm_finalprice();
     bool getm_available();
     char *getm_owner();
     void setm_make(char *newmake);
     void setm_model(char *newmodel);
     void setm_year(int newyear);
     void setm_baseprice(float newbaseprice);
     void setm_available(bool newavailable);
     void setm_owner(char *newowner);
     void updatePrice(float);
     void print();
     void estimateCost(int days);
     Car& operator+(const Sensor &track);
     Car& operator+(char *person);
   private:
     char m_make[MAXIUMUM];
     char m_model[MAXIUMUM];
     int m_year;
     Sensor m_sensors[3];
     float m_baseprice;
     float m_finalprice;
     bool m_available;
     char m_owner[MAXIUMUM];
     int sensorinformation;
};
#endif
