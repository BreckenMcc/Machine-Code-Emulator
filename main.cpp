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
        int counter, shiftNum;
        string operation, hexOne, hexTwo, tempStr;

        Hex temp;
        getline(fin, operation, '0');
        cleanString(operation);
        if(operation == "NOT" || operation == "NOTS"){
            getline(fin, hexOne, '0');
            cleanString(hexOne);

            Operation op(hexOne);
            temp = op.NOT();

            cout << "NOT" << centerHex(op.getHexOne().getHex()) << ": " << temp.formatHex() << endl;
        }else if(operation == "ASR" || operation == "ASRS" || operation == "LSR" || operation == "LSRS" || operation == "LSL" || operation == "LSLS"){
            getline(fin, hexOne, '0');
            cleanString(hexOne);
            getline(fin, tempStr);
            shiftNum = stoi(tempStr);

            if(operation == "ASR" || operation == "ASRS"){
                Operation op(hexOne);
                temp = op.ASR(shiftNum);

                cout << "ASR" << centerHex(op.getHexOne().getHex()) << shiftNum << ": " << temp.formatHex() << endl;
            }else if(operation == "LSR" || operation == "LSRS"){
                Operation op(hexOne);
                temp = op.LSR(shiftNum);

                cout << "LSR" << centerHex(op.getHexOne().getHex()) << shiftNum << ": " << temp.formatHex() << endl;
            }else{
                Operation op(hexOne);
                temp = op.LSL(shiftNum);

                cout << "LSL" << centerHex(op.getHexOne().getHex()) << shiftNum << ": " << temp.formatHex() << endl;
            }
        }else{
            getline(fin, hexOne, '0');
            cleanString(hexOne);
            getline(fin, hexTwo);
            cleanString(hexTwo);

            if(operation == "ADD"){
                Operation op(hexOne, hexTwo);
                temp = op.ADD();

                cout << "ADD" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "AND" || operation == "ANDS"){
                Operation op(hexOne, hexTwo);
                temp = op.AND();

                cout << "AND" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "ORR" || operation == "ORRS"){
                Operation op(hexOne, hexTwo);
                temp = op.ORR();

                cout << "ORR" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "SUB" || operation == "SUBS"){
                Operation op(hexOne, hexTwo);
                temp = op.SUB();

                cout << "SUB" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "XOR" || operation == "XORS"){
                Operation op(hexOne, hexTwo);
                temp = op.XOR();

                cout << "XOR" << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else{
                cout << "err" << endl;
            }
        }
    }

    fin.close();

    return 0;
}