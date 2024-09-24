#include <iostream>
#include <stdint.h>
using namespace std;

int digitToDecimal(char c);
char digitToHex(int i);
string decimalToHex(uint32_t);
string centerHex(string);
bool detectOverflow(uint32_t, uint32_t);