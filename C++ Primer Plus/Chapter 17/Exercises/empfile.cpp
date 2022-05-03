/* The first time through, the program
should solicit data from the user, show all the entries, and save the information in a
file. On subsequent uses, the program should first read and display the file data, let the
user add data, and show all the data. One difference is that data should be handled by
an array of pointers to type employee.That way, a pointer can point to an employee
object or to objects of any of the three derived types. */

// FIXME: The copied over logic from Chap 14 Exercise for this base code has a
// bug that solicits information twice for each base class in highfink,
// consider a change that keeps data get and put logic in a separate protected
// method for each atomic input transaction; used in a previous program that
// had Waiter, singing waiter and sorts in the same chapter consisting of
// virtual base classes

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <filesystem>
#include "../terminate.hpp"
#include "../../Chapter 16/readUtils.hpp"
#include "emp.hpp"
using empvec_t = std::vector<abstr_emp *>;

// Helper Functions
empvec_t getEmployees(std::ifstream &in);
void saveEmployees(std::ofstream &out, const empvec_t &);
int getEmployeeCode(const abstr_emp &);
void printEmployees(const empvec_t &);

enum {
    EMPLOYEE, MANAGER,
    FINK, HIGHFINK
};

int main() {
    int choice, subchoice;
    const char *filename = "employees.out";

    empvec_t employees;
    std::ifstream infile(filename);
    if (infile.is_open()) {
        employees = getEmployees(infile);
        if (employees.size())
            printEmployees(employees);
    }

    abstr_emp *readEmp;
    for (;;) {
        std::cout << "1. Add    2. Delete\n"
                     "3. Clear  4. Quit\n";
        rd::readvalue(choice, "Command: ");
        if (choice < 1 || choice > 5) {
            std::cerr << "Invalid choice\n";
            continue;
        }
        switch (choice) {
            case 1: rd::readvalue(subchoice, "1: employee, 2: manager, 3: fink, 4: highfink\n");
                    if (subchoice < 1 || subchoice > 4) {
                        std::cerr << "Invalid choice\n";
                        continue;
                    }
                    switch (subchoice) {
                        case 1: readEmp = new employee; break;
                        case 2: readEmp = new manager;  break;
                        case 3: readEmp = new fink;     break;
                        case 4: readEmp = new highfink; break;
                    }
                    readEmp->SetAll();
                    employees.push_back(readEmp);
                    break;
            case 2: rd::readvalue(subchoice, "Enter index: ");
                    if (subchoice < 0 || subchoice >= employees.size()) {
                        std::cerr << "Invalid index\n";
                        continue;
                    }
                    employees.erase(employees.begin() + subchoice);
                    break;
            case 3: employees.clear();
                    break;
            case 4: goto ExitLoop;
        }
        printEmployees(employees);
    }
    ExitLoop:
    std::ofstream outfile(filename, std::ios_base::out | std::ios_base::trunc);
    if (!outfile.is_open())
        ter::terminate("Unable to open outfile:", filename);
    saveEmployees(outfile, employees);
    std::cout << "Bye\n";

    return 0;
}

empvec_t getEmployees(std::ifstream &in) {
    /* Read the input file for encoded employees and
     * return a vector container of employee pointers */
    int code;
    empvec_t employees;
    abstr_emp *read;
    while (in >> code) {
        switch (code) {
            case EMPLOYEE: read = new employee;
                           read->ReadAll(in);
                           break;
            case MANAGER:  read = new manager;
                           read->ReadAll(in);
                           break;
            case FINK:     read = new fink;
                           read->ReadAll(in);
                           break;
            case HIGHFINK: read = new highfink;
                           read->ReadAll(in);
                           break;
            default: std::cerr << "Invalid Code\n"; continue;
        }
        employees.push_back(read);
    }
    return employees;   // use c++11 move semantics to 
}                       // prevent unnecessary copying

void saveEmployees(std::ofstream &out, const empvec_t &vec) {
    /* Save the employees in the vector container to
     * the given output file */
    for (const auto &emp: vec) {
        out << getEmployeeCode(*emp) << '\n';
        emp->WriteAll(out);
    }
}

int getEmployeeCode(const abstr_emp &emp) {
    /* Get the employee code to save in file */
    if (typeid(emp) == typeid(employee)) 
        return EMPLOYEE;
    else if (typeid(emp) == typeid(manager))
        return MANAGER;
    else if (typeid(emp) == typeid(fink))
        return FINK;
    else if (typeid(emp) == typeid(highfink))
        return HIGHFINK;

    return -1; // error, none of these match
}

void printEmployees(const empvec_t &vec) {
    /* Print a vector of employees */
    for (int i = 0; i < vec.size(); i++) {
        std::cout.put('\n');
        std::cout.width(15);
        std::cout << "Employee " << i+1 << ":\n";
        vec.at(i)->ShowAll();
        std::cout.put('\n');
    }
}

