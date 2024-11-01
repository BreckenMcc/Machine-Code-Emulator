#include "operation.h"

Operation::Operation(){
    
}
Operation::Operation(Hex h1){
    hexOne = h1;
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

Hex Operation::ADD(){
    Hex output;
    uint32_t hexOneDecimal = hexOne.hexToDecimal();
    uint32_t hexTwoDecimal = hexTwo.hexToDecimal();
    output.decimalToHex(hexOneDecimal + hexTwoDecimal);

    return output;
}

Hex Operation::AND(){
    Hex output;
    string str;
    string hexOneBinary = hexOne.hexToBinary();
    string hexTwoBinary = hexTwo.hexToBinary();
    int oneLength = hexOneBinary.length();
    int twoLength = hexTwoBinary.length();

    if(oneLength != twoLength){
        if(oneLength > twoLength){
            for(int i = twoLength; i < oneLength; i++){
                hexTwoBinary.insert(hexTwoBinary.begin(), '0');
            }
        }else{
            for(int i = oneLength; i < twoLength; i++){
                hexOneBinary.insert(hexOneBinary.begin(), '0');
            }
        }
    }

    for(int i = 0; i < oneLength; i++){
        if(hexOneBinary[i] == '1' && hexTwoBinary[i] == '1'){
            str += '1';
        }else{
            str += '0';
        }
    }

    output.binaryToHex(str);
    return output;
}
Hex Operation::ASR(int shiftAmt){
    Hex output;
    string binary = hexOne.hexToBinary();
    int length = binary.length();
    char msb = binary[0];

    binary.append(shiftAmt, '0');

    if (binary.length() > 32) {
        binary = binary.substr(binary.length() - 32);
        binary[0] = msb;
    }

    output.binaryToHex(binary);
    return output;
}
Hex Operation::LSR(int shiftAmt){
    Hex output;
    string binary = hexOne.hexToBinary();
    int length = binary.length();

    binary = string(shiftAmt, '0') + binary.substr(0, length - shiftAmt);

    if (binary.length() > 32) {
        binary = binary.substr(binary.length() - 32);
    }

    output.binaryToHex(binary);
    return output;
}
Hex Operation::LSL(int shiftAmt){
    Hex output;
    string binary = hexOne.hexToBinary();
    int length = binary.length();

    if(shiftAmt >= length){
        binary = string(length, '0');
    }else{
        binary = binary.substr(shiftAmt) + string(shiftAmt, '0');
    }

    if (binary.length() > 32) {
        binary = binary.substr(binary.length() - 32);
    }

    output.binaryToHex(binary);
    return output;
}
Hex Operation::NOT(){
    Hex output;
    string str;
    string hexOneBinary = hexOne.hexToBinary();

    for(int i = 0; i < hexOneBinary.length(); i++){
        if(hexOneBinary[i] == '1'){
            str += '0';
        }else{
            str += '1';
        }
    }

    output.binaryToHex(str);
    return output;
}
Hex Operation::ORR(){
    Hex output;
    string str;
    string hexOneBinary = hexOne.hexToBinary();
    string hexTwoBinary = hexTwo.hexToBinary();
    int oneLength = hexOneBinary.length();
    int twoLength = hexTwoBinary.length();

    if(oneLength != twoLength){
        if(oneLength > twoLength){
            for(int i = twoLength; i < oneLength; i++){
                hexTwoBinary.insert(hexTwoBinary.begin(), '0');
            }
        }else{
            for(int i = oneLength; i < twoLength; i++){
                hexOneBinary.insert(hexOneBinary.begin(), '0');
            }
        }
    }

    for(int i = 0; i < oneLength; i++){
        if(hexOneBinary[i] == '1' || hexTwoBinary[i] == '1'){
            str += '1';
        }else{
            str += '0';
        }
    }

    output.binaryToHex(str);
    return output;
}
Hex Operation::SUB(){
    Hex output;
    uint32_t hexOneDecimal = hexOne.hexToDecimal();
    uint32_t hexTwoDecimal = hexTwo.hexToDecimal();
    output.decimalToHex(hexOneDecimal - hexTwoDecimal);

    return output;
}
Hex Operation::XOR(){
    Hex output;
    string str;
    string hexOneBinary = hexOne.hexToBinary();
    string hexTwoBinary = hexTwo.hexToBinary();
    int oneLength = hexOneBinary.length();
    int twoLength = hexTwoBinary.length();

    if(oneLength != twoLength){
        if(oneLength > twoLength){
            for(int i = twoLength; i < oneLength; i++){
                hexTwoBinary.insert(hexTwoBinary.begin(), '0');
            }
        }else{
            for(int i = oneLength; i < twoLength; i++){
                hexOneBinary.insert(hexOneBinary.begin(), '0');
            }
        }
    }

    for(int i = 0; i < oneLength; i++){
        if(hexOneBinary[i] == '1' && hexTwoBinary[i] == '1'){
            str += '0';
        }else if(hexOneBinary[i] == '1' || hexTwoBinary[i] == '1'){
            str += '1';
        }else{
            str += '0';
        }
    }

    output.binaryToHex(str);
    return output;
}