#include "list.h"

namespace LIST {
    list::list() {
        start_ = nullptr;        // set start_ to null
    }
    list::list(const Item &val) {
        start_ = new Node;       // create and set new node
        start_->data_ = val;     // to the value passed
        start_->next_ = nullptr; // next points to null
    }
    list::~list() {
        Node *temp, *ptr = start_;
        // visit and delete each new-allocated memory
        while (ptr) {
            temp = ptr->next_;
            delete ptr;
            ptr = temp;
        }
    }
    bool list::isempty() {
        return start_ == nullptr;
    }
    bool list::isfull() {       // (proper) linked list 
        return false;           // can't be full
    }
    void list::add(const Item &val) {
        Node *currNode = new Node;
        currNode->data_ = val;
        currNode->next_ = nullptr;

        if (start_ == nullptr) {  // if start is null,
            start_ = currNode;    // make currNode first
            return;               // node and return
        }
        // get end node, and insert new node at end
        Node *end;
        for (end = start_; 
             end->next_; 
             end=end->next_) ;
        end->next_ = currNode;
    }
    // visit each node and apply func pf to each data value
    void list::visit(void (*pf)(Item &)) {
        for (Node *ptr = start_; ptr; ptr=ptr->next_)
            pf(ptr->data_);
    }
}

