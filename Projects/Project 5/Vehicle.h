#include <ostream>
#ifndef Vehicle_H
#define Vehicle_H

class Vehicle {
   protected:
     float *m_lla;
     const int m_vin;
   private:
     static int s_idegen;
   public:
     Vehicle();
     Vehicle(int vin, float lla[]);
     Vehicle(const Vehicle& other);
     virtual ~Vehicle();
     Vehicle& operator=(const Vehicle& other);
     int getm_vin() const;
     float *getm_lla() const;
     void setm_lla(float, int);
     void move(float*);
     static int getIdgen();
     friend std::osteam& operator<<(std::ostream& stream,
       const Vehicle& vehicle);
};
#endif
