#include "operation.h"

Operation::Operation(){

}
Operation::Operation(Hex h1, Hex h2){
    hexOne = h1;
    hexTwo = h2;
}
Operation::Operation(Hex h1, Hex h2, Hex h3){
    hexOne = h1;
    hexTwo = h2;
    hexThree = h3;
}
Operation::Operation(const Operation& rhs){
    hexOne = rhs.hexOne;
    hexTwo = rhs.hexTwo;
    hexThree = rhs.hexThree;
}

Hex Operation::getHexOne(){
    return hexOne;
}
Hex Operation::getHexTwo(){
    return hexTwo;
}
Hex Operation::getHexThree(){
    return hexThree;
}

void Operation::setHexOne(Hex h1){
    hexOne = h1;
}
void Operation::setHexTwo(Hex h2){
    hexTwo = h2;
}
void Operation::setHexThree(Hex h3){
    hexThree = h3;
}

bool Operation::detectOverflow(uint32_t a, uint32_t b){
    uint32_t total = a + b;

    if(total < a || total < b){
        return true;
    }else{
        return false;
    }
}

Hex Operation::add(){
    Hex output;
    uint32_t hexOneDecimal = hexOne.hexToDecimal();
    uint32_t hexTwoDecimal = hexTwo.hexToDecimal();
    output.decimalToHex(hexOneDecimal + hexTwoDecimal);

    return output;
}
