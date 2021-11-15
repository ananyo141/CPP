#include <cstring>
#include "stack.h"

namespace stack {
    Stack::Stack() {
        top_ = 0;
        size_ = INCREMENT;
        items_ = new Item[size_];
    }

    Stack::~Stack() {
        top_ = size_ = 0;
        delete[] items_;
    }

    bool Stack::isfull() const {
        return top_ == size_;
    }

    bool Stack::isempty() const {
        return top_ == 0;
    }

    void Stack::push(const Item &item) {
        if (isfull()) 
            expand();
        items_[top_++] = item;
    }

    Item Stack::pop() {
        if (isempty())
            throw "Attempt to pop on Empty Stack";
        return items_[--top_];
    }

    void Stack::expand(unsigned expBy) {
        Item *newStack = new Item[size_+expBy];
        memcpy(newStack, items_, sizeof(Item) * size_);
        size_ += expBy;
        delete[] items_;
        items_ = newStack;
    }
}

