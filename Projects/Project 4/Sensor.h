#ifndef Sensor_H
#define Sensor_H
#include <iostream>

using namespace std;
const int MAX_SIZE = 256;

class Sensor {
   public:
     Sensor();
     Sensor& operator =(const Sensor& other);
     Sensor(const char *type);
     Sensor(const Sensor& other);
     const char *getm_type();
     float getm_extracost();
     static int getgps_cnt();
     static int getcamera_cnt();
     static int getlidar_cnt();
     static int getradar_cnt();
     void setm_type(const char *newtype);
     void setm_extracost(float newextracost);
     void resetgps_cnt();
     void resetcamera_cnt();
     void resetlidar_cnt();
     void resetradar_cnt();
     bool operator ==(const Sensor& compare) const;
   private:
     char m_type[MAX_SIZE];
     float m_extracost;
     static int gps_cnt;
     static int camera_cnt;
     static int lidar_cnt;
     static int radar_cnt;
};
#endif
