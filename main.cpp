#include "operation.h"

int main(){

    Hex one("AF47");
    Hex two("1234");
    string add = "ADD";
    Operation operationOne(add, one, two);
    operationOne.compute(true);

    return 0;
}