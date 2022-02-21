#include <iostream>
#include <cstring>
#include <cctype>
#include "worker.hpp"
#include "../StudentClass/studcont.hpp"
const int NUM_WORKERS = 5;

int main() {
    int i;
    bool quit = false;
    char inp_type;
    const char *worker_types = "wstq";
    work::Worker *employees[NUM_WORKERS];
    for (i = 0; i < NUM_WORKERS; i++) {
        // Force input validate
        for (;;) {
            util::readVal(inp_type,
                "Enter the employee category:\n"
                "w: waiter  s: singer  t: SingingWaiter  q: quit\n");
            if (!std::strchr(worker_types, inp_type))
                std::cerr << "Invalid Choice\n";
            else break;
        }
        // Build appropriate object
        switch(inp_type) {
            case 'w': employees[i] = new work::Waiter;
                      employees[i]->set();
                      break;
            case 's': employees[i] = new work::Singer;
                      employees[i]->set();
                      break;
            case 't': employees[i] = new work::SingingWaiter;
                      employees[i]->set();
                      break;
            case 'q': quit = true;
                      break;
            default:  std::cerr << "Invalid Input\n";
                      break;
        }
        if (quit) break;
    }

    // Print Results
    std::cout << "\n\nHere's your staff:\n\n";
    for (int j = 0; j < i; j++) {
        employees[j]->show();
        delete employees[j];
        std::cout.put('\n');
    }
    return 0;
}

