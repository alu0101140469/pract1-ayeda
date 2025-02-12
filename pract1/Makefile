CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: mcd

mcd: main.o BigUnsigned.o BigInteger.o
	$(CXX) $(CXXFLAGS) -o mcd main.o BigUnsigned.o BigInteger.o

BigUnsigned.o: BigUnsigned.cpp BigUnsigned.hpp
	$(CXX) $(CXXFLAGS) -c BigUnsigned.cpp

BigInteger.o: BigInteger.cpp BigInteger.hpp
	$(CXX) $(CXXFLAGS) -c BigInteger.cpp

main.o: main.cpp BigUnsigned.hpp BigInteger.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o mcd