/* 6. The CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a frac-
tional part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that uses a function that takes
as arguments a reference to CandyBar, a pointer-to-char, a double, and an int and
uses the last three values to set the corresponding members of the structure.The last
three arguments should have default values of “Millennium Munch,” 2.85, and 350.
Also the program should use a function that takes a reference to a CandyBar as an
argument and displays the contents of the structure. Use const where appropriate. */

#include <iostream>
#include <cstring>
const int ARRSIZE = 50;

struct CandyBar {
	char name[ARRSIZE];
	double weight;
	unsigned calories;
};

// prototypes //
void setBar(CandyBar &bar, const char *name = "Millennium Munch",
	     double weight = 2.85, unsigned calories = 350);
void showBar(const CandyBar &bar);

int main() {
	CandyBar candy;
       	setBar(candy, "Kit Kat", 4.5, 300);
	showBar(candy);	

	return 0;
}

void setBar(CandyBar &bar, const char *name, double weight, unsigned calories) {
	strncpy(bar.name, name, ARRSIZE - 2);
	bar.name[ARRSIZE - 1] = '\0';	
	bar.weight = weight;
	bar.calories = calories; 
}

void showBar(const CandyBar &bar) {
	std::cout << "Bar name: "   << bar.name
		  << "\nWeight: "   << bar.weight
		  << "\nCalories: " << bar.calories << "\n";
}

