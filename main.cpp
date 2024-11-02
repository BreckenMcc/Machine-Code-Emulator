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
            getline(fin, hexOne, ' ');
            cleanString(hexOne);

            Operation op(hexOne);
            temp = op.NOT();

            if(operation == "NOT"){
                cout << "NOT";
            }else{
                cout << "NOTS";
            }
            cout << centerHex(op.getHexOne().getHex()) << ": " << temp.formatHex() << endl;
        }else if(operation == "ASR" || operation == "ASRS" || operation == "LSR" || operation == "LSRS" || operation == "LSL" || operation == "LSLS"){
            getline(fin, hexOne, ' ');
            cleanString(hexOne);
            getline(fin, tempStr);
            cleanString(tempStr);
            shiftNum = stoi(tempStr);

            if(operation == "ASR" || operation == "ASRS"){
                Operation op(hexOne);
                temp = op.ASR(shiftNum);

                if(operation == "ASR"){
                    cout << "ASR";
                }else{
                    cout << "ASRS";
                }
                cout << centerHex(op.getHexOne().getHex()) << " " << shiftNum << ": " << temp.formatHex() << endl;
            }else if(operation == "LSR" || operation == "LSRS"){
                Operation op(hexOne);
                temp = op.LSR(shiftNum);

                if(operation == "LSR"){
                    cout << "LSR";
                }else{
                    cout << "LSRS";
                }
                cout << centerHex(op.getHexOne().getHex()) << " " << shiftNum << ": " << temp.formatHex() << endl;
            }else{
                Operation op(hexOne);
                temp = op.LSL(shiftNum);

                if(operation == "LSL"){
                    cout << "LSL";
                }else{
                    cout << "LSLS";
                }
                cout << centerHex(op.getHexOne().getHex()) << " " << shiftNum << ": " << temp.formatHex() << endl;
            }
        }else{
            getline(fin, hexOne, '0');
            cleanString(hexOne);
            getline(fin, hexTwo);
            cleanString(hexTwo);

            if(operation == "ADD" || operation == "ADDS"){
                Operation op(hexOne, hexTwo);
                temp = op.ADD();

                if(operation == "ADD"){
                    cout << "ADD";
                }else{
                    cout << "ADDS";
                }
                cout << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "AND" || operation == "ANDS"){
                Operation op(hexOne, hexTwo);
                temp = op.AND();

                if(operation == "AND"){
                    cout << "AND";
                }else{
                    cout << "ANDS";
                }
                cout << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "ORR" || operation == "ORRS"){
                Operation op(hexOne, hexTwo);
                temp = op.ORR();

                if(operation == "ORR"){
                    cout << "ORR";
                }else{
                    cout << "ORRS";
                }
                cout << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "SUB" || operation == "SUBS"){
                Operation op(hexOne, hexTwo);
                temp = op.SUB();

                if(operation == "SUB"){
                    cout << "SUB";
                }else{
                    cout << "SUBS";
                }
                cout << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else if(operation == "XOR" || operation == "XORS"){
                Operation op(hexOne, hexTwo);
                temp = op.XOR();

                if(operation == "XOR"){
                    cout << "XOR";
                }else{
                    cout << "XORS";
                }
                cout << centerHex(op.getHexOne().getHex()) << centerHex(op.getHexTwo().getHex()) << ": " << temp.formatHex() << endl;
            }else{
                cout << "err" << endl;
            }
        }
    }

    fin.close();

    return 0;
}