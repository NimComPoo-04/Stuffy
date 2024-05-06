CXX = g++
CXXFLAGS = -Wall -Wextra -ggdb -std=c++17 -O0

all: build sorter

build:
	@mkdir -p obj

sorter: obj/main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/main.o: main.cc $(wildcard *.hh)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf obj sorter
