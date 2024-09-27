#include "operation.h"

Operation::Operation(){
    logic = "NULL";
}
Operation::Operation(string l, Hex h1, Hex h2){
    logic = l;
    hexOne = h1;
    hexTwo = h2;
}
Operation::Operation(const Operation& rhs){
    logic = rhs.logic;
    hexOne = rhs.hexOne;
    hexTwo = rhs.hexTwo;
}

string Operation::getLogic(){
    return logic;
}
Hex Operation::getHexOne(){
    return hexOne;
}
Hex Operation::getHexTwo(){
    return hexTwo;
}

void Operation::setLogic(string l){
    logic = l;
}
void Operation::setHexOne(Hex h1){
    hexOne = h1;
}
void Operation::setHexTwo(Hex h2){
    hexTwo = h2;
}

Hex Operation::compute(bool printResults){
    Hex output;
    
    if(logic == "ADD"){
        uint32_t hexOneDecimal = hexOne.hexToDecimal();
        uint32_t hexTwoDecimal = hexTwo.hexToDecimal();
        output.decimalToHex(hexOneDecimal + hexTwoDecimal);

        if(printResults){
            cout << "ADD" << centerHex(hexOne.getHex()) << centerHex(hexTwo.getHex()) << ": " << output.formatHex() << endl;
            cout << "Overflow: ";
            if(detectOverflow(hexOneDecimal, hexTwoDecimal)){
                cout << " yes" << endl;
            }else{
                cout << " no" << endl;
            }
        }

    }else{
        cout << "The logic operation {" << logic << "} is not supported." << endl;
    }
    return output;
}
