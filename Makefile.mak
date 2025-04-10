CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = matrix_app
SRC = main.cpp
HDR = Matrix.hpp

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
