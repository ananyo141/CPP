// Implementation file for atm.hpp
#include <iostream>
#include <stdexcept>
#include "atm.hpp"

namespace ATM {
    bool checkCustomer(double chance) {
        /* Check if a new customer has arrived,
           Chance: Less is more(1 means 100% probability) 

           For 6, Ranges are 0-1, 1-2, 2-3, 3-4, 4-5, 5-6 */
        std::runtime_error UnboundError("Value less than 1");
        if (chance < 1) 
            throw UnboundError;
        return (std::rand() * chance / RAND_MAX) < 1;
    }

    // Queue Class Methods
    Queue::Queue(int qsize) : queuesize_(qsize) {
        /* Initialize Queue instance attributes */
        qlen_  = 0;
        front_ = rear_ = nullptr;
    }

    Queue::~Queue() {
        /* Delete the node memory allocated by Queue */
        Node *ptr=front_, *temp;
        while (ptr) {
            temp = ptr->next_;
            delete ptr;
            ptr = temp;
        }
    }

    bool Queue::isfull() const {
        /* Return if the queue is full */
        return qlen_ == queuesize_;
    }

    bool Queue::isempty() const {
        /* Return if the queue is empty */
        return front_ == nullptr;
    }

    bool Queue::enqueue(const Item &item) {
        /* Insert item into queue, return true if
           successful (no overflow), else false */
        if (isfull()) return false;
        Node *newnode = new Node{item, nullptr};    // create the new node
        (front_ ? rear_->next_ : front_) = newnode; // add to the list
        rear_ = newnode; // make rear point to the new node
        qlen_++;
        return true;
    }

    bool Queue::dequeue(Item &item) {
        /* Delete an item from queue into item reference and 
           return true if successful (no underflow), else false */
        if (isempty()) return false;
        qlen_--;
        item = front_->data_;    // set the return data

        // Delete the node from the list
        Node *tmp = front_;
        front_ = front_->next_;
        delete tmp;
        return true;
    }
}

