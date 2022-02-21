// Implementation file for worker classes

#include <iostream>
#include <iomanip>
#include "worker.hpp"

// Get the readval utility
#include "../StudentClass/studcont.hpp"

namespace work {

    const char *Singer::voices_[VTYPES] = {
        "Other", "Alto", "Contralto", "Soprano",
        "Bass", "Baritone", "Tenor"
    };

    // Worker Methods
    Worker::~Worker() { }
    void Worker::getData() {
        util::readVal(name_, "Enter employee name: ");
        util::readVal(id_, "Enter employee id: ");
    }
    void Worker::showData() const {
        std::cout << std::left << std::setw(10) << "Name: " << name_
                  << std::left << std::setw(10) << "\nId: " << id_
                  << '\n';
    }

    void Worker::set() {
        getData();
    }

    void Worker::show() const {
        showData();
    }

    // Waiter Methods
    void Waiter::getData() {
        util::readVal(panache_, "Enter panache: ");
    }
    void Waiter::showData() const {
        std::cout << "Panache: " << panache_ << '\n';
    }
    void Waiter::set() {
        Worker::getData();
        Waiter::getData();

    }
    void Waiter::show() const {
        std::cout << "Category: Waiter\n";
        Worker::showData();
        Waiter::showData();
    }

    // Singer Methods
    void Singer::getData() {
        int choice, i;
        for (;;) {
            std::cout << "Enter number for singer's vocal range:\n";
            for (i = 0; i < VTYPES; i++) {
                std::cout << i << ": " << voices_[i] << ' ';
                if (i % 5 == 4)
                    std::cout << '\n';
            }
            if (!(i % 5 == 0))
                std::cout << '\n';
            util::readVal(choice, "");
            if (choice < 0 || choice > 6)
                std::cerr << "Invalid Choice\n";
            else break;
        }
        voice_ = Voices(choice);    // cast it to appropriate voice
    }
    void Singer::showData() const {
        std::cout << "Vocal Range: " << voices_[int(voice_)] << '\n';
    }

    void Singer::set() {
        Worker::getData();
        Singer::getData();
    }

    void Singer::show() const {
        std::cout << "Category: Singer\n";
        Worker::showData();
        Singer::showData();
    }
    // SingingWaiter Methods
    // Dummy methods
    void SingingWaiter::getData () { }
    void SingingWaiter::showData() const { }

    void SingingWaiter::set() {
        Worker::getData();
        Singer::getData();
        Waiter::getData();
    }

    void SingingWaiter::show() const {
        std::cout << "Category: SingingWaiter\n";
        Worker::showData();
        Singer::showData();
        Waiter::showData();
    }
}

