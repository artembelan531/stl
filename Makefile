CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall

GTEST_LIBS = -lgtest -lgtest_main -pthread

EXECUTABLE_1 = main
EXECUTABLE_2 = tests

$(EXECUTABLE_1): main.o
	$(CXX) $(CXXFLAGS) main.o -o $(EXECUTABLE_1)

$(EXECUTABLE_2): tests.o
	$(CXX) $(CXXFLAGS) tests.o -o $(EXECUTABLE_2) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXECUTABLE_1) $(EXECUTABLE_2)
