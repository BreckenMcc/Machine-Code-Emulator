hexAdder: main.o hex.o helpers.o
	g++ -o hexAdder main.o hex.o helpers.o -g

main.o: main.cpp hex.h
	g++ -c main.cpp -g

hex.o: hex.cpp hex.h helpers.h
	g++ -c hex.cpp -g

helpers.o: helpers.cpp helpers.h
	g++ -c helpers.cpp -g

clean:
	rm *.o hexAdder