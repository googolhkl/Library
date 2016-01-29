gxx=g++ -std=c++11
LIBS=./hklUtil.so -lunittest++

test: test.o
	$(gxx) -o test test.o $(LIBS)
test.o: test.cpp
	$(gxx) -c -g test.cpp 
clean:
	rm test test.o
