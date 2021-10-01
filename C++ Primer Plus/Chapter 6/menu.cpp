/*
3. Write a precursor to a menu-driven program.The program should display a menu
offering four choices, each labeled with a letter. If the user responds with a letter
other than one of the four valid choices, the program should prompt the user to
enter a valid response until the user complies.Then the program should use a
switch to select a simple action based on the user’s selection.
*/
#include <iostream>

int main() {
    std::cout << "Please enter one of the following choices:\n"
                 "c) carnivore              p)pianist\n"
                 "t) tree                   g)game\n";
    char ch;
    while(std::cin >> ch) {
        switch (ch) {
            case 'c': case 'C': std::cout << "A tiger is a carnivore";  goto success;
            case 'p': case 'P': std::cout << "There is a movie called"
                                             " the Pianist";            goto success;
            case 't': case 'T': std::cout << "A maple is a tree";       goto success;
            case 'g': case 'G': std::cout << "Call of Duty is a game";  goto success;
            default : std::cout << "Please enter a c, p, t or g: ";     continue;
        }
    }
    success:
    std::cout << std::endl;

    return 0;
}
