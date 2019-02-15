//This is project 4 by Jared Lam for CS 202
#include <iostream>
#include "Car.h"
#include "Sensor.h"
#include "Agency.h"

using namespace std;
#define MAX_SIZE 256

int main() {
  char inputf[MAX_SIZE];
  Agency agency;
  char name[MAX_SIZE];
  int appointment, days, car_index, type = 1, rental_car;
  while(1) {
    cout << "Options: "<< endl;
    cout << "1- input file name"<< endl;
    cout << "2- print terminal"<< endl;
    cout << "3- total sensors"<< endl;
    cout << "4- find expensive car"<< endl;
    cout << "5- exit program"<< endl;
    cout << "Please enter your option: "<< endl;
    cin >> appointment;
    switch(appointment) {
      case 1:
         cout << "Enter input file name: "<< endl;
         cin >> inputf;
         agency.readAllData(inputf);
         break;
      case 2:
         agency.printAlllData();
         break;
      case 3:
      {
        cout << "Number of gps sensors: " << Sensor::getgps_cnt()<< endl;
        cout << "Number of camera sensors: " << Sensor::getcamera_cnt()<< endl;
        cout << "Number of lidar sensors: " << Sensor::getlidar_cnt()<< endl;
        cout << "Number of radar sensors: " << Sensor::getradar_cnt()<< endl;
      }
        break;
      case 4:
      {
        Car& find = agency.biggestcost();
        find.print();
        cout << "1 - yes and 2 - no" << endl;
        cout << "Do you want to rent this car: " << endl;
        cin >> rental_car;
        if(rental_car == 1) {
          find.setm_available(false);
          cout << "Print your name please" << endl;
          cin >> name;
          find.setm_owner(name);
          find.print();
        }
      }
        break;
      case 5:
        return 0;
        break;
      default:
        cout << "Invalid option"<< endl;
        break;
    }
  }
  return 0;
}
