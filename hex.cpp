#include "hex.h"

Hex::Hex(){
    hexValue = "0";
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

char Hex::digitToHex(int i){
    switch(i){
        case 0:
            return '0';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        case 10:
            return 'A';
            break;
        case 11:
            return 'B';
            break;
        case 12:
            return 'C';
            break;
        case 13:
            return 'D';
            break;
        case 14:
            return 'E';
            break;
        case 15:
            return 'F';
            break;
        default:
            cout << "Error converting " << i << " to decimal from hex." << endl;
            return 'X';
    }
}
void Hex::decimalToHex(uint32_t i){
    uint32_t quotient = i;
    uint32_t remainer;
    string out = "";
    string temp = "";

    if(quotient == 0){
        hexValue = "0";
    }
    while(quotient != 0){
        remainer = quotient % 16;
        quotient /= 16;
        temp += digitToHex(remainer);
    }
    for (int i = temp.length() - 1; i >= 0; i--) {
        out += temp[i];
    }
    hexValue = out;
    
}
int Hex::digitToDecimal(char c){
    if(c >= 'a' && c <= 'f'){
        c -= 32;
    }
    switch(c){
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            cout << "Error converting " << c << " to decimal from hex." << endl;
            return -1;
    }
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

string Hex::digitToBinary(char c){
    if(c >= 'a' && c <= 'f'){
        c -= 32;
    }
    switch(c){
        case '0':
            return "0000";
            break;
        case '1':
            return "0001";
            break;
        case '2':
            return "0010";
            break;
        case '3':
            return "0011";
            break;
        case '4':
            return "0100";
            break;
        case '5':
            return "0101";
            break;
        case '6':
            return "0110";
            break;
        case '7':
            return "0111";
            break;
        case '8':
            return "1000";
            break;
        case '9':
            return "1001";
            break;
        case 'A':
            return "1010";
            break;
        case 'B':
            return "1011";
            break;
        case 'C':
            return "1100";
            break;
        case 'D':
            return "1101";
            break;
        case 'E':
            return "1110";
            break;
        case 'F':
            return "1111";
            break;
        default:
            cout << "Error converting " << c << " to decimal from hex." << endl;
            return "eror";
    }
}
string Hex::hexToBinary(){
    int length = hexValue.length();
    string binary = "";
    
    for(int i = 0 ; i < length; i++) {
        binary += digitToBinary(hexValue[i]);
    }
    
    return binary;
}

uint32_t Hex::binaryToInt(string in){
    int length = in.length();
    uint32_t decimal = 0;
    int power = 1;
    
    for(int i = length - 1; i >= 0; i--) {
        if(in[i] == '1'){
            decimal += power;
        }
        power *= 2;
    }
    
    return decimal;
}

void Hex::binaryToHex(string in){
    uint32_t num = binaryToInt(in);
    decimalToHex(num);
}
