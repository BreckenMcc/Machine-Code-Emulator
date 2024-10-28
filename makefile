hexAdder: main.o operation.o hex.o helpers.o
	g++ -o hexAdder main.o helpers.o operation.o hex.o -g

main.o: main.cpp helpers.h
	g++ -c main.cpp -g

helpers.o: helpers.cpp helpers.h operation.h
	g++ -c helpers.cpp -g

operation.o: operation.cpp operation.h hex.h
	g++ -c operation.cpp -g

hex.o: hex.cpp hex.h
	g++ -c hex.cpp -g

clean:
	rm *.o hexAdder