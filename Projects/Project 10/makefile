all:proj10
proj10:proj10.cpp DataType.o
	      g++ proj10.cpp DataType.o -o proj10 -std=c++11
DataType.o: DataType.cpp
	      g++ -c DataType.cpp -std=c++11
clean:
	      rm -rf *.o proj10
