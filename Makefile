CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall

GTEST_LIBS = -lgtest -lgtest_main -pthread

EXECUTABLE = tests

$(EXECUTABLE): tests.o
	$(CXX) $(CXXFLAGS) tests.o -o $(EXECUTABLE) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXECUTABLE)
