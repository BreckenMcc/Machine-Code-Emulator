#ifndef OPERATION_H
#define OPERATION_H

#include "hex.h"

class Operation{
    string logic;
    Hex hexOne, hexTwo;
public:
    Operation();
    Operation(string, Hex, Hex);
    Operation(const Operation&);

    string getLogic();
    Hex getHexOne();
    Hex getHexTwo();

    void setLogic(string);
    void setHexOne(Hex);
    void setHexTwo(Hex);

    Hex compute(bool);
};
#endif