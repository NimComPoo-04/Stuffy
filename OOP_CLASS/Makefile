CXX = g++
CXXFLAGS = -Wall -Wextra -ggdb -std=c++17 -O0

%: %.cc
	$(CXX) $(CXXFLAGS) -o a.out $^
	./a.out
	@maim -g 1434x859+0+0 -u $(shell pwd)/screen.png

clean:
	@rm -rf a.out

.PHONY: clean
