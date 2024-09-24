#include "hex.h"

Hex::Hex(){
    hexValue = "00000000";
}
Hex::Hex(string h){
    hexValue = h;
}
Hex::Hex(const Hex& rhs){
    hexValue = rhs.hexValue;
}

void Hex::setHex(string h){
    hexValue = h;
}
string Hex::getHex(){
    return hexValue;
}

string Hex::formatHex(){
    string out = "0x" + hexValue;
    return out;
}
void Hex::printHex(){
    cout << "0x" << hexValue;
}

uint32_t Hex::hexToDecimal(){
    int length = hexValue.length();
    uint32_t decimal = 0;
    int power = 1;
    
    for(int i = length - 1; i >= 0; i--) {
        int digit = digitToDecimal(hexValue[i]);
        decimal += (digit * power);
        power *= 16;
    }
    
    return decimal;
}