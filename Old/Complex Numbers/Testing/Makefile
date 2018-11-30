CXX = g++
CXXFLAGS = -Wall -g

test: tester.o Complex.o
	$(CXX) $(CXXFLAGS) -o test tester.o Complex.o

tester1.o: Complex.h
	$(CXX) $(CXXFLAGS) -c tester.cc

Complex1.o: Complex.h
	$(CXX) $(CXXFLAGS) -c Complex.cc