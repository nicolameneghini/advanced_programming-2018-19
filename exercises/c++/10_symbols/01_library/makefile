CXX = c++
LANG = ITALIANO

SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

all: libtest.so

libtest.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude

source/hello.o: include/hello.h

format: $(SRC) include/hello.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	@rm -f *~ */*~ libtest.so src/*.o

.PHONY: clean all format
