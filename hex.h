#ifndef HEX_H
#define HEX_H
#include "helpers.h"

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
    uint32_t hexToDecimal();
};
#endif