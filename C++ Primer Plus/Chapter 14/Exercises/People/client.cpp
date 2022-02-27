// Client program for people.hpp
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "people.hpp"
#include "../../StudentClass/studcont.hpp"
const int NUM_PEOPLE = 5;

int main() {
    using util::readVal;
    using namespace people;
    int i;
    char choice;
    std::srand(std::time(0));

    Person *peopleArr[NUM_PEOPLE];
    for (i = 0; i < NUM_PEOPLE; i++) {
        for (;;) {
            readVal(choice, "Enter Person type:\n"
                "g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit\n");
            if (!std::strchr("gpbq", choice))
                std::cerr << "Invalid input\n";
            else break;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'g': peopleArr[i] = new Gunslinger;  break;
            case 'p': peopleArr[i] = new PokerPlayer; break;
            case 'b': peopleArr[i] = new BadDude;     break;
        }
        peopleArr[i]->get();
    }

    std::cout << "\n\nMeet your people:\n";
    for (int showCount = 0; showCount < i; showCount++) {
        peopleArr[showCount]->show();
        std::cout << '\n';
    }

    return 0;
}

