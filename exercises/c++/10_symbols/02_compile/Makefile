EXE = exe
CXX = c++

SRC = src/src1.cc src/src2.cc main.cc
OBJ = $(SRC:.cc=.o)

CXXFLAGS = -I include -std=c++11


all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE) $(CXXFLAGS)


main.o: src/src1.o src/src2.o include/foo.h

src/src1.o: src/src1.cc include/utility.h
src/src2.o: src/src2.cc include/utility.h

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all