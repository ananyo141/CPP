#include <iostream>
#include "queueTp.hpp"
#include "../WorkerClass/worker.hpp"
const int SIZE = 5;

int main() {
    queueTp::Queue<work::Worker *> workerQueue;

    bool finished = false;
    char choice;
    work::Worker *newWorker;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Enter the employee category:\n"
                     "w: waiter  s: singer  t: singing waiter  q: quit\n";
        std::cin >> choice;
        switch (choice) {
            case 'w': newWorker = new work::Waiter; break;
            case 's': newWorker = new work::Singer; break;
            case 't': newWorker = new work::SingingWaiter; break;
            case 'q': finished = true; break;
            default:  std::cerr << "Invalid choice\n";
        }
        if (finished) break;
        newWorker->set();
        workerQueue.insert(newWorker);
    }
    std::cout << "Meet your staff:\n";
    while (workerQueue.remove(newWorker))
        newWorker->show();

    return 0;
}

