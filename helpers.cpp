#include "helpers.h"

string centerHex(string in){
    string out = "  ";
    for(int i = 1; i <= (8 - in.length()); i++){
        out += ' ';
    }
    out += "0x";
    for(int i = 0; i < in.length(); i++){
        out += in[i];
    }

    return out;
}
bool detectOverflow(uint32_t a, uint32_t b){
    uint32_t total = a + b;

    if(total < a || total < b){
        return true;
    }else{
        return false;
    }
}
void cleanString(string &str){
    string temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '0' && str[i] != 'x' && str[i] != ' '){
            temp += str[i];
        }
    }
    str = temp;
}
