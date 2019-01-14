#ifndef Car_H
#define Car_H
#include <iostream>
#include "Vehicle.h"
const int MAX_SIZE = 256;

class Car: public Vehicle {
   private:
     int m_throttle;
     virtual void serialize(std::ostream&) const;
   public:
     Car();
     Car(float lla[]);
     Car(const Car& other);
     virtual ~Car();
     Car& operator=(const Car& other);
     int getm_throttle() const;
     void setm_throttle(int);
     void drive(int);
     virtual void move(const float*);
};

#endif
