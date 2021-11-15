#include <iostream>
#include <cstring>

const int SIZE = 35;
struct customer {
    char fullname[SIZE];
    double payment;
};

// Customer Stack
typedef customer Item;

class Stack {
private:
    enum {INCREMENT = 5};
    int top_;
    int size_;
    Item *items_;    // dynamic array to hold values
public:
    Stack() {
        top_ = 0;
        size_ = INCREMENT;
        items_ = new Item[size_];
    }
    ~Stack() {       // destructor
        top_ = size_ = 0;
        delete[] items_;
    }
    bool isfull()  const {
        return top_ == size_;
    }
    bool isempty() const {
        return top_ == 0;
    }
    void push(const Item &item) {
        if (isfull()) 
            expand();
        items_[top_++] = item;
    }
    Item pop() {
        if (isempty())
            throw "Attempt to pop on Empty Stack";
        return items_[--top_];
    }
    void expand(unsigned expBy = INCREMENT) {
        Item *newStack = new Item[size_+expBy];
        memcpy(newStack, items_, sizeof(Item) * size_);
        size_ += expBy;
        delete[] items_;
        items_ = newStack;
    }
};

int main() {
    Stack customers;
    char inp; double total = 0;
    std::cout << "Press 'a' to add customer, 'p' to remove\n";
    while (std::cin >> inp && inp != 'q') {
        switch(inp) {
            case 'a': case 'A':
                customer entry;
                std::cout << "Enter customer name: ";
                std::cin  >> std::ws;
                std::cin.getline(entry.fullname, SIZE);
                std::cout << "Payment calculation: ";
                std::cin  >> entry.payment;
                customers.push(entry);
                break;
            case 'p': case 'P':
                if (customers.isempty()) {
                    std::cerr << "No customers!\n";
                    continue;
                }/* then, by limiting scope */ {
                customer exit = customers.pop();
                std::cout << "Exiting customer: "   << exit.fullname
                          << "\nPayment received: " << exit.payment;
                total += exit.payment;
                std::cout << "\nRunning total: " << total << "\n";
                } /* exit scope ends here */
                break;
            default:
                std::cerr << "Invalid command\n";
                break;
        }
        std::cout << "\nNext ('a' or 'p'): ";
    }
    std::cout << "Exit\n";

    return 0;
}

