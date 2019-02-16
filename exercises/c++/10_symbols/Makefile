CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++14

default: vector.x

.PHONY: default #allows me to have a file called "default"

vector.x: vector.cc
			$(CXX) $(CXXFLAGS) $< -o $@   #$< > ARE DEPENDENCIES and @ is the target
