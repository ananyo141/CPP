/* 8. You can describe a simple list as follows:
# The simple list can hold zero or more items of some particular type.
# You can create an empty list.
# You can add items to the list.
# You can determine whether the list is empty.
# You can determine whether the list is full.
# You can visit each item in the list and perform some action on it.

As you can see, this list really is simple; it doesn’t allow insertion or deletion, for example.
Design a List class to represent this abstract type.You should provide a list.h
header file with the class declaration and a list.cpp file with the class method
implementations.You should also create a short program that utilizes your design.
The main reason for keeping the list specification simple is to simplify this pro-
gramming exercise.You can implement the list as an array or, if you’re familiar with
the data type, as a linked list. But the public interface should not depend on your
choice.That is, the public interface should not have array indices, pointers to nodes,
and so on. It should be expressed in the general concepts of creating a list, adding
an item to the list, and so on.The usual way to handle visiting each item and per-
forming an action is to use a function that takes a function pointer as an argument:
void visit(void (*pf)(Item &));
Here pf points to a function (not a member function) that takes a reference to Item
argument, where Item is the type for items in the list.The visit() function applies
this function to each item in the list.You can use the Stack class as a general guide. */

#include <iostream>
#include "list.h"

// function to change list values
void square(double &);
void print (double &);

int main() {
    int i;
    LIST::list list1, list2(32);

    // empty, full, add, visit
    for (i = 0; i < 5; i++) 
        list1.add(i);
    list1.add(35);
    std::cout << "List 1: ";
    list1.visit([] (double &x) {        // lambda expression visits
            std::cout << x << ' ';      // each value and prints it
    });                                 // (another incarnate of 'print'
    std::cout << '\n';                  // function here)

    for (i = 9; i > 0; i--)
        list2.add(i);
    std::cout << "List 2: ";
    list2.visit(print);
    std::cout << '\n';

    list1.visit(square);
    std::cout << "List 1 after squaring: ";
    list1.visit(print);

    std::cout << "\nlist 1 is empty: " << list1.isempty();
    std::cout << "\nlist 2 is full:  " << list2.isfull() 
              << '\n';

    return 0;
}

/* Visitor Functions */
void square(double &val) {
    /* square the value in-situ */
    val = val*val;
}

void print(double &val) {
    /* print the values */
    std::cout << val << ' ';
}

