6_5_9.out : 6_5_9.o MinHeap.o
	g++ -o 6_5_9.out 6_5_9.o MinHeap.o
6_5_9.o : 6_5_9.cpp MinHeap.h
	g++ -g -c 6_5_9.cpp -Wall -std=c++1z
MinHeap.o :MinHeap.cpp MinHeap.h
	g++ -g -c MinHeap.cpp -Wall -std=c++1z

clean :
	rm -rf *.o *.out