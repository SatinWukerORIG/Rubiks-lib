TARGET = rubiks
CXX    = g++
FILE   = rubiks.cpp

all:
	$(CXX) $(FILE) -o $(TARGET)

clean:
	rm $(TARGET)
