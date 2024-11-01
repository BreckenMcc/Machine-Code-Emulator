#ifndef HEX_H
#define HEX_H
#include <iostream>
#include <stdint.h>
using namespace std;

class Hex{
    string hexValue;

    public:
    Hex();
    Hex(string);
    Hex(const Hex&);

    void setHex(string);
    string getHex();

    string formatHex();
    void printHex();

    char digitToHex(int i);
    void decimalToHex(uint32_t);

    int digitToDecimal(char c);
    uint32_t hexToDecimal();

    string digitToBinary(char c);
    string hexToBinary();
    uint32_t binaryToInt(string);
    void binaryToHex(string);
    
};
#endif