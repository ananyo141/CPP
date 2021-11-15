#ifndef STACK_H_
#define STACK_H_

namespace stack {
    typedef unsigned long Item;

    class Stack {
    private:
        enum {INCREMENT = 5};
        int top_;
        int size_;
        Item *items_;    // dynamic array to hold values
    public:
        Stack();         // constructor
        ~Stack();        // destructor
        bool isfull()  const;
        bool isempty() const;
        void push(const Item &);
        Item pop();
        void expand(unsigned expBy = INCREMENT);
    };
}
#endif

