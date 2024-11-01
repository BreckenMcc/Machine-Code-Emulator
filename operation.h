#ifndef OPERATION_H
#define OPERATION_H

#include "hex.h"

class Operation{
    Hex hexOne, hexTwo, hexThree;
public:
    Operation();
    Operation(Hex);
    Operation(Hex, Hex);
    Operation(Hex, Hex, Hex);
    Operation(const Operation&);

    Hex getHexOne();
    Hex getHexTwo();
    Hex getHexThree();

    void setHexOne(Hex);
    void setHexTwo(Hex);
    void setHexThree(Hex);

    bool detectOverflow(uint32_t, uint32_t);

    Hex ADD();
    Hex AND();
    Hex ASR(int);
    Hex LSR(int);
    Hex LSL(int);
    Hex NOT();
    Hex ORR();
    Hex SUB();
    Hex XOR();
};
#endif