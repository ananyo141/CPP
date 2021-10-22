/* 1. Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type int, argument is provided and is
nonzero, the function should print the string a number of times equal to the num-
ber of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it is
equal to the number of times the function has been called.) Yes, this is a silly func-
tion, but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works. */

#include <iostream>
const int ARRSIZE = 50;

void printTimesCalled(const char * str, int ifPrint = 0);

int main() {
	char string[ARRSIZE];
	std::cout << "Enter a string: ";
	std::cin.getline(string, ARRSIZE);
	printTimesCalled(string); 	// default, should print once
	printTimesCalled(string, 3);	// non-default, should print twice (number of times called)
	printTimesCalled(string);	// default, once
	printTimesCalled(string, -1); 	// non-default, print four times

	return 0;
}

void printTimesCalled(const char * str, int ifPrint) {
	/* Print the string the number of times this function is called (latest call inclusive)*/
	static int numCount = 1;
	if (ifPrint) {
		std::cout << "Printing function " << numCount << " times\n";
		for (int i = 0; i < numCount; i++)
			std::cout << str << "\n";
	} else 
		std::cout << "Printing once: "
			  << str << "\n";
	++numCount;
}

