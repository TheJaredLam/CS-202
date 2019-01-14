#include <ostream>
#include "Vehicle.h"
#ifndef Car_H
#define Car_H
const int MAX_SIZE = 256;

class Car: public Vehicle {
   private:
     char *m_plates;
     int m_throttle;
   public:
     Car();
     Car(const char* plates, int vin, float lla[]);
     Car(const Car& other);
     ~Car();
     Car& operator=(const Car& other);
     char* getm_plates() const;
     int getm_throttle() const;
     void setm_plates(const char*);
     void setm_throttle(int);
     void drive(int);
     void move(float*);
     friend std::ostream& operator<<(std::ostream& stream,
       const Car& car);
}

#endif
