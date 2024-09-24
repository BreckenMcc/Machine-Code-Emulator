hexAdder: main.o operation.o hex.o helpers.o
	g++ -o hexAdder main.o operation.o hex.o helpers.o -g

main.o: main.cpp operation.h
	g++ -c main.cpp -g

operation.o: operation.cpp operation.h hex.h
	g++ -c operation.cpp -g

hex.o: hex.cpp hex.h helpers.h
	g++ -c hex.cpp -g

helpers.o: helpers.cpp helpers.h
	g++ -c helpers.cpp -g

clean:
	rm *.o hexAdder