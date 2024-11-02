Readme File

How to run this file:
(In Terminal)
-> make
-> ./hexAdder {file to pass}

The file to pass in this example is "Programming-Project-2.txt"

Working process:
In the main file using command line arguments the file passed is open and a while loop is created to read from the file until
it is empty. During each instance of the loop the operation is passed in and then using the clean string function the spaces
inbetween the operation and the first hex value are removed. Depending on the operation value diffrent parts of data will be 
collected to create a operation object. Next the first (and in some cases second) hex strings are passed in and cleaned up in
the same way the first operation string was passed. Depending on the value of the operation (which was checked earlier) the
program will call the needed method on the operation object that stores all of the needed hex values (and will take in an int 
for shift operations). Finally using the output of the operation (a hex value) the program prints the desired information to the
terminal.