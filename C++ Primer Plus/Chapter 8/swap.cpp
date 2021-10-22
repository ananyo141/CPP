// Swap two variables using references and pointers, using templates
#include <iostream>
const int FIELD_WIDTH = 20;

// prototypes //
template <typename T>
void swap(T &a, T &b);
template <typename T>
void swap(T *a, T *b);
template <typename T>
void displayNum(const T &a, const T &b);

int main()
{
	double num1, num2;
	std::cout << "Enter numbers: ";
	std::cin  >> num1 >> num2;
	std::cout << '\n';

	std::cout.width(FIELD_WIDTH);
	std::cout << "User input:\n";
	displayNum(num1, num2);
	swap(num1, num2);
	std::cout.width(FIELD_WIDTH);
	std::cout << "After swapping:\n";
	displayNum(num1, num2);

	std::cout.width(FIELD_WIDTH);
	std::cout << "Using pointer swapping:\n";
	swap(&num1, &num2);
	displayNum(num1, num2);

	return 0;
}

// definitions //
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> // overloaded function that
void swap(T *a, T *b) // takes pointer as args
{ 
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void displayNum(const T &a, const T &b)
{
	std::cout << "The first number is " << a
			  << "\nThe second number is " << b << "\n\n";
}
