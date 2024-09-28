Readme File

How to run this file:
(In Terminal)
-> make
-> ./hexAdder {file to pass}

The file to pass in this example is "Programming-Project-1.txt"

Working process:
In the main file using command line arguments the file passed is open and a while loop is created to read from the file until
it is empty. During each instance of the loop the operation (in this case it will always be add) is passed in and then using
the clean string function the spaces inbetween the operation and the first hex value are removed. Next the first and second hex
strings are passed in and cleaned up in the same way the first operation string was passed. After all the strings are gathered
and cleaned they are passed into a Operation object which compares the operation to known operations (in this case only the 
ADD operation has been implemented) and does to the two passed hex values what needs to be done.

In the case of the ADD operation the hex is converted to decimal and then added together, the result is also checked to see if
there is an overflow. The resulting decimal is then converted back to hex and outputed.

One more thing to note about the operation class is that by default it dosent print the output to the terminal it only returns
the hex, there is a paramter to print the result of the operation to the terminal which is marked as true when called in main
to print the result to the terminal.