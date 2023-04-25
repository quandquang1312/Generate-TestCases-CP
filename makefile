CXX = g++
EXECUTABLE = $(F)
SOURCE = ./$(F).cpp
CXXFLAGS = -Wall -std=c++11 -DLOCAL

PYTHON = python3
PY_SOURCE = ./test.py

all: $(EXECUTABLE) run_cpp run_py
$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXECUTABLE)

run_cpp:
	./$(EXECUTABLE)
run_py:
	$(PYTHON) $(PY_SOURCE)

clean:
	rm -f $(EXECUTABLE)
