#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
    stack::Stack st;
    char ch;
    stack::Item po;
    std::cout << "Please enter A to add a purchase order,\n"
              << "P to process a PO, or Q to quit.\n";
    while (std::cin >> ch && toupper(ch) != 'Q') {
        while (std::cin.get() != '\n') ;
        if (!isalpha(ch)) {
            std::cout << '\a';
            continue;
        }
        switch(ch) {
            case 'A': case 'a':
                std::cout << "Enter a PO number to add: ";
                std::cin  >> po;
                if (st.isfull())
                    std::cout << "Stack full, adding more slots\n";
                st.push(po);
                break;

            case 'P': case 'p':
                if (st.isempty())
                    std::cout << "Stack already empty\n";
                else {
                    po = st.pop();
                    std::cout << "PO #" << po << " popped\n";
                }
                break;
        }
        std::cout << "Please enter A to add a purchase order,\n"
                  << "P to process a PO, or Q to quit.\n";
    }
    std::cout << "Bye\n";
    return 0;
}

