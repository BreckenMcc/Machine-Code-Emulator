#include "helpers.h"
#include <fstream>

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Incorrect command line input. Please supply the name of the input file when running like so:\n./hexAdder Programing-Project-1.txt"<<endl;
        return 1;
    }
    string inFile = argv[1];   
    ifstream fin(inFile);

    while(!fin.eof()){
        int counter;
        string operation, hexOne, hexTwo;

        Hex temp;
        getline(fin, operation, '0');
        cleanString(operation);
        getline(fin, hexOne, '0');
        cleanString(hexOne);
        getline(fin, hexTwo);
        cleanString(hexTwo);

        if(operation == "ADD"){
            Operation op(hexOne, hexTwo);
            temp = op.add();

            cout << "ADD" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            cout << "Overflow: ";
            if(op.detectOverflow(op.getHexOne().hexToDecimal(), op.getHexTwo().hexToDecimal())){
                cout << " yes" << endl;
            }else{
                cout << " no" << endl;
            }
        }
    }

    fin.close();

    return 0;
}