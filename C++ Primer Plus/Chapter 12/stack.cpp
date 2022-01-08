// Stack Implementation with dynamic storage

#include <iostream>
#include <cstring>

namespace Stack {
    typedef unsigned long Item;

    class Stack {
    private:
        enum {DEFSIZ=10};
        Item *sitems_;
        const int size_;
        int top_;
        void checkOverflow() const {
            if (isfull())
                throw "Stack Overflow";
        }
        void checkUnderflow() const {
            if (isempty())
                throw "Stack Underflow";
        }

    public:
        // Default Constructor
        Stack(unsigned size=DEFSIZ): size_(size) {
            sitems_ = new Item[size_];
            top_ = 0;
        }

        ~Stack() {
            delete [] sitems_;
        }
        
        Stack(const Stack &s) : size_(s.size_) {  // Copy Constructor
            sitems_ = new Item[size_];
            // Copy the stack elements
            std::memcpy(sitems_, s.sitems_, sizeof(Item) * s.top_);
            top_ = s.top_;
        }

        Stack & operator=(const Stack &s) { // Assignment Operator Overload
            int tocopy = (s.top_ < size_) ? s.top_ : size_; // get the one with min size
            std::memcpy(sitems_, s.sitems_, sizeof(Item) * tocopy); // copy to dst
            top_ = tocopy;                                          // and set top
            return *this;
        }

        bool isfull() const {
            return top_ == size_;
        }

        bool isempty() const {
            return top_ == 0;
        }

        void push(Item val) {
            checkOverflow();
            sitems_[top_++] = val;
        }

        Item pop() {
            checkUnderflow();
            return sitems_[--top_];
        }
    };
}

const int TEST_STACK_SIZE = 8;
int main() {
    using Stack::Stack;
    Stack s1(TEST_STACK_SIZE);

    int i = 0;
    while (i++ < TEST_STACK_SIZE+2) {
        std::cout << "Pushing: ";
        try { s1.push(i); std::cout << "Success (" << i << ")\n"; }
        catch (const char *err) { std::cerr << err << '\n'; }
    }
    
    Stack s2, s3 = s1; // copy constructor
    s2 = s1;           // assignment operator

    std::cout.put('\n');
    while (--i) {
        try {std::cout << "Popped: " << s3.pop() << '\n'; }
        catch (const char *err) { std::cerr << err << '\n'; }
    }

    return 0;
}

