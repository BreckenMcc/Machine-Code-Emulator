#include "operation.h"
#include <fstream>
#define MAX_SIZE 500

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Incorrect command line input. Please supply the name of the input file when running like so:\n./hexAdder Programing-Project-1.txt"<<endl;
        return 1;
    }
    string inFile = argv[1];   
    ifstream fin(inFile);
    Operation ops[MAX_SIZE];

    while(!fin.eof()){
        string operation, hexOne, hexTwo;

        Hex temp;
        getline(fin, operation, '0');
        cleanString(operation);
        getline(fin, hexOne, '0');
        cleanString(hexOne);
        getline(fin, hexTwo);
        cleanString(hexTwo);

        Operation op(operation, hexOne, hexTwo);
        op.compute("true");
    }

    fin.close();

    return 0;
}