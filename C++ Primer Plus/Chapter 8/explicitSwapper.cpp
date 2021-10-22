// Create a swapper that swaps generic types, and specify an explicit specialization
// that swaps two job structures

#include <iostream>
const int ARRSIZE = 40;

struct Job {
	char name[ARRSIZE];
	double salary;
	int floor;
};

// prototypes //
void getJobDesc(Job & a);
void displayJobs(const Job & j1, const Job & j2);
template<typename T>
void displayNums(const T &a, const T &b);
template<typename T>
void swap(T & a, T & b);
template <> void swap<Job>(Job & a, Job & b);

int main() {
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	int a, b;
	double c, d;
	Job e, f;
	std::cout << "Enter two ints: ";
	std::cin  >> a >> b;
	std::cout << "\nUser input: ";
	displayNums(a, b);
	swap(a, b);
	std::cout << "After swapping: ";
	displayNums(a, b);

	std::cout << "\nEnter two doubles: ";
	std::cin  >> c >> d;
	std::cout << "\nUser input: ";
	displayNums(c, d);
	swap(c, d);
	std::cout << "After swapping: ";
	displayNums(c, d);
	std::cout << "\nNow for job structs";
	getJobDesc(e);
	getJobDesc(f);
	std::cout << "\n\nUser input:";
	displayJobs(e, f);
	swap(e, f);
	std::cout << "\nAfter swapping:";
	displayJobs(e, f);

	return 0;
}

// definitions // 
void getJobDesc(Job & a) {
	std::cout << "\nEnter name: ";
	std::cin >> std::ws;
	std::cin.getline(a.name, ARRSIZE);
	std::cout << "Enter salary: ";
	std::cin  >> a.salary;
	std::cout << "Enter floor: ";
	std::cin  >> a.floor;
}

void displayJobs(const Job & j1, const Job & j2) {
	std::cout << "\nNames: "    << j1.name   << ", " << j2.name
		  << "\nSalaries: " << j1.salary << ", " << j2.salary
		  << "\nFloors: "   << j1.floor  << ", " << j2.floor << "\n";
}

template<typename T>                       // template for displaying
void displayNums(const T &a, const T &b) { // numbers of generic types
	std::cout << "Num1 = " << a
		  << ", Num2 = " << b << "\n";
}

template<typename T>    // generic template for swapping two numbers
void swap(T & a, T & b) {
	T temp = a;
	a = b;
	b = temp;
}

template <> void swap<Job>(Job & a, Job & b) {  // explicit specialization for
	int floorA;			        // for type Job
	double salaryA;

	salaryA = a.salary;
	floorA = a.floor;
	a.salary = b.salary;
	a.floor = b.floor;

	b.salary = salaryA;
	b.floor = floorA;
}

