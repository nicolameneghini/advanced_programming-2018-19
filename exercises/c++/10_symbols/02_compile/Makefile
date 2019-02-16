EXE = exe

LFLAGS = -lblas
CXX = c++
CXXFLAGS = -I include -I -std=c++11

SRC = src/src1.cc src/src2.cc main.cc
OBJ = $(SRC:.o=.cc)

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXFLAGS)


$(EXE): main.o src/src.o src/src2.o
	$(CXX) $^ -o $(EXE) $(LFLAGS)

main.o: src/src1.o src/src2.o foo.h

src/src1.o: include/utility.h
src/src2.o: include/utility.h

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all format
