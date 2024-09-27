#include "helpers.h"

void readInputFile(Operation* inputs){

}

int digitToDecimal(char c){
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
char digitToHex(int i){
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
string decimalToHex(uint32_t i){
    uint32_t quotient = i;
    uint32_t remainer;
    string out = "";
    string temp = "";

    if(quotient == 0){
        return "0";
    }
    while(quotient != 0){
        remainer = quotient % 16;
        quotient /= 16;
        temp += digitToHex(remainer);
    }
    for (int i = temp.length() - 1; i >= 0; i--) {
        out += temp[i];
    }

    return out;
}
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
