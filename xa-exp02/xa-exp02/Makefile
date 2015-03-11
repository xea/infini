CXX = g++
CXXFLAGS = -std=c++11 -I.
SOURCES=$(shell find . -type f -iname '*.cpp')

OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

TARGET=xa-exp02

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
