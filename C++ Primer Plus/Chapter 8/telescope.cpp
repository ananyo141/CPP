// Based on the property that a base object reference can refer to an object of
// a derived class (or child class), write a program that calculates the magnification
// of given eyepieces, using a function that takes an object reference of both class ostream
// and ofstream to display and save the results in a file.

#include <iostream>
#include <fstream>
const int LIMIT = 5;

// prototypes //
inline int magnification(double focObj, double focEyep);
void displayData(std::ostream & out, double objFocalLen, const double focalLengths[], int limit = LIMIT);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: telescope <filename>\n";
		exit(EXIT_FAILURE);
	}	
	double objFocalLength, focalLengths[LIMIT];
	// take user input
	std::cout << "Enter object focal length of object: ";
	std::cin  >> objFocalLength;
	for (int i = 0; i < LIMIT; i++) {
		std::cout << "Enter focal length of eyepiece #" << i + 1 << ": ";
		while (!(std::cin  >> focalLengths[i])) {   // input validation
			std::cin.clear();
			while (std::cin.get() != ' ') ;
			std::cout << "Please enter decimal value: ";
		}
	}
	// display the values
	displayData(std::cout, objFocalLength, focalLengths);
	// save the values in file
	std::ofstream outfile;
	outfile.open(argv[1]);
	if (!outfile.is_open()) {
		std::cerr << "Unable to open file " << argv[1] << std::endl;
		exit(EXIT_FAILURE);
	}
	displayData(outfile, objFocalLength, focalLengths);
	outfile.close();
	
	return 0;
}

// definitions //
inline int magnification(double focObj, double focEyep) {
	return focObj / focEyep + 0.5; // a ceil effect, so that values are not rounded down
}

void displayData(std::ostream & out, double objFocalLen, const double focalLengths[], int limit) {
	std::cout << "\n";
	std::ios_base::fmtflags initial;
	initial = out.setf(std::ios_base::fixed); // save initial formatting
	out.precision(0);
	out << "Focal length of objective: " << objFocalLen << "mm\n.";
	out.setf(std::ios::showpoint);
	out.precision(1);
	out.width(12);
	out << "f.1 eyepiece";
	out.width(15);
	out << "magnification\n"; 
	for (int i = 0; i < limit; i++) {
		out.width(12);
		out << focalLengths[i];
		out.width(15);
		out << magnification(objFocalLen, focalLengths[i]) << std::endl;
	}
	out.setf(initial); // reset formatting
}

