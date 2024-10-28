#include "helpers.h"

/*
* Method Name: centerHex 
* 
* Return type: String
* 
* Parameters: String
* 
* Pre-Condition: A string containing the output of a hex object has been made
* 
* Post-Condition: The string passed in has spaces added to the font of it to center it in the terminal
*
* Description: This function adds the ability to center hex outupts so they match the correct way they should be displayed
* in the terminal
*
* Methods called: None
*/
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
<<<<<<< HEAD
=======

/*
* Method Name: detectOverflow 
* 
* Return type: bool
* 
* Parameters: Decimal number one (uint32_t), Decimal number two (uint32_t)
* 
* Pre-Condition: Two unsigned ints that will be added are passed to check if their addition will result in an overflow
* 
* Post-Condition: True is returned if there is an overflow, false is returned if not
*
* Description: This function checks if there is an overflow by checking if the output of the addition is smaller 
* than either of the inputs
*
* Methods called: None
*/
bool detectOverflow(uint32_t a, uint32_t b){
    uint32_t total = a + b;

    if(total < a || total < b){
        return true;
    }else{
        return false;
    }
}

/*
* Method Name: cleanString 
* 
* Return type: void
* 
* Parameters: file input (string)
* 
* Pre-Condition: A string have been read in from the input file
* 
* Post-Condition: The string is cleaned up, removing unimportant charaters
*
* Description: This function checks cleans up strings by removing spaces or any lingering "0x" before the hex string
* than either of the inputs
*
* Methods called: None
*/
>>>>>>> 5e134c146c140da8c87f86c23c47e92e78c17c15
void cleanString(string &str){
    string temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '0' && str[i] != 'x' && str[i] != ' '){
            temp += str[i];
        }
    }
    str = temp;
}
