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
void cleanString(string &str){
    string temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '0' && str[i] != 'x' && str[i] != ' '){
            temp += str[i];
        }
    }
    str = temp;
}
