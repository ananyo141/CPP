/*
4. When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a pro-
gram that can list members by real name, by job title, by secret name, or by a mem-
ber’s preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
struct bop {
char fullname[strsize]; // real name
char title[strsize];
// job title
char bopname[strsize]; // secret BOP name
int preference;
// 0 = fullname, 1 = title, 2 = bopname
};
In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alterna-
tives:
a. display by name
c. display by bopname
q. quit
b. display by title
d. display by preference

Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1, choice d would display the programmer’s job title.
*/
#include <iostream>

const int STRSIZE = 50;
const int MEMBERS =  4;

struct Bop {
    char fullname[STRSIZE];
    char title[STRSIZE];
    char bopname[STRSIZE];
    int  preference;
};

int main() {
    char ch;
    Bop members[MEMBERS]  = {
        {"Wimp Macho", "Software", "Loopy", 0},
        {"Raki Rhodes", "Junior Programmer", "Amazonia", 1},
        {"Celia Laiter", "MIPS", "Hoppy Hipman", 2},
        {"Pat Hand", "Analyst Trainee", "Nucleya", 1}
    };

    do {
        std::cout << "\n Benevolent Order Of Programmers Report\n"
                    "a. Display by name      b. Display by title\n"
                    "c. Display by bopname   d. Display by preference\n"
                    "q. Quit\n>> ";
        std::cin >> ch;
        bool invalidChoice = false;
        for (int i = 0; i < MEMBERS; i++) {
            switch (ch) {
                case 'a': std::cout << members[i].fullname; break;
                case 'b': std::cout << members[i].title   ; break;
                case 'c': std::cout << members[i].bopname ; break;
                case 'd': switch (members[i].preference) {
                            case 0: std::cout << members[i].fullname; break;
                            case 1: std::cout << members[i].title   ; break;
                            case 2: std::cout << members[i].bopname ; break;
                        } 
                        break;
                default: invalidChoice = true;
                         break;
            }
            std::cout << std::endl;
            if (invalidChoice) {
                if (ch != 'q')
                    std::cout << "Invalid Choice";
                break;
            }
        }
    } while (ch != 'q');

    return 0;
}
