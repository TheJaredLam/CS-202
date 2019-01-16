#include <iostream>
#include "SmartPtr.h"

using namespace std;

int main() {

  cout << endl << "Testing SmartPtr Default ctor" << endl;

  SmartPtr sp1;

  sp1->setIntVal(1);
  sp1->setDoubleVal(0.25);

  cout << "Deference Smart Pointer 1: " << *sp1 << endl;
  cout << endl << "Testing SmartPtr Copy ctor" << endl;

  SmartPtr sp2 = sp1;

  sp2->setIntVal(2);
  sp2->setDoubleVal(0.5);
  cout << "Deference Smart Pointer 1: " << *sp1 << endl;
  cout << "Deference Smart Pointer 2: " << *sp2 << endl;
  cout << endl << "Testing SmartPtr Assignment operator" << endl;

  SmartPtr sp3;

      sp3 = sp1;

  sp3->setIntVal(4);
  sp3->setDoubleVal(0.0);

  cout << "Deference Smart Pointer 1: " << *sp1 << endl;
  cout << "Deference Smart Pointer 2: " << *sp2 << endl;
  cout << "Deference Smart Pointer 3: " << *sp3 << endl;

  cout << endl << "Testing SmartPtr Parameterized ctor with NULLdata" << endl;

  SmartPtr spNULL( NULL );


  cout << endl << "Testing SmartPtr Copy ctor with NULLdata SmartPtr" << endl;
      SmartPtr spNULL_cpy(spNULL);

  cout << endl << "Testing SmartPtr Assignment with NULLdata SmartPtr" << endl;
      SmartPtr spNULL_assign;
      spNULL_assign = spNULL;

  cout << endl <<  "End-of-Scope, Destructors called in reverse order of SmartPtr creation\n (spNULL_assign, spNULL_cpy, spNULL, sp3, sp2, sp1): " << endl;

  return 0;
}
