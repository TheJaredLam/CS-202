#ifndef Vehicle_H
#define Vehicle_H
#include <ostream>

class Vehicle {
   protected:
     float m_lla[3];
   private:
     virtual void serialize(std::ostream&) const;
   public:
     Vehicle();
     Vehicle(const float* lla);
     Vehicle(const Vehicle& other);
     virtual ~Vehicle();
     Vehicle& operator=(const Vehicle& other);
     const float *getm_lla() const;
     void setm_lla(const float*);
     virtual void move(const float*) = 0;
     friend std::ostream& operator<<(std::ostream& stream,
       const Vehicle& vehicle);
};
#endif
