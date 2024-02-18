CXX = g++
CXXFLAGS = -Wall -Wextra -ggdb -std=c++17

SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, obj/%.o, $(SRC))

INC = -Iinclude
LIB = -L. -lraylib

all: build snake

build:
	@mkdir -p obj

snake: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIB)

obj/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^ $(INC)

clean:
	rm -rf obj snake
