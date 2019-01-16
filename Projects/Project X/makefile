projx: projx.cpp DataType.o SmartPtr.o
	       g++ projx.cpp DataType.cpp SmartPtr.cpp -o projx
DataType.o: DataType.cpp
	      g++ -c DataType.cpp
SmartPtr.o: SmartPtr.cpp
	      g++ -c SmartPtr.cpp
clean:
	      rm -rf  *.o  main
