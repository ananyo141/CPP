/* 3. Write overloaded versions of iquote(), a function that displays its argument
enclosed in double quotation marks.Write three versions: one for an int argument,
one for a double argument, and one for a string argument. */

#include <iostream>

template<typename T>
void iquote(T arg);
template<> void iquote(const char *arg);

int main() {
	iquote(4);
	iquote(5.5);
	iquote("This is a good day!");
	const char *ptr = "This is char *";
	iquote(ptr);

	return 0;
}

// definitions //
template<typename T>
void iquote(T arg) {
	std::cout << "\"" << arg << "\"\n";
}

template<> void iquote(const char *arg) { // explicit specialization for char *
	std::cout << "String: ";
	std::cout << "\"" << arg << "\"\n";
}

