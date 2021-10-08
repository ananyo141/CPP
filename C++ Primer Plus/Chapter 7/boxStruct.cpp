/*
3. Here is a structure declaration:
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
a. Write a function that passes a box structure by value and that displays the
value of each member.
b. Write a function that passes the address of a box structure and that sets the
volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions.
*/

#include <iostream>

struct Box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void displayBox(Box box);
void setVolume(Box *box);

int main() {
    Box box = {
        "Godrej", 30, 30, 20
    };
    setVolume(&box);
    displayBox(box);

    return 0;
}

void displayBox(Box box) {
    std::cout << "Box maker: "  << box.maker
              << "\nBox height: " << box.height
              << "\nBox width: "  << box.width
              << "\nBox length: " << box.length
              << "\nBox volume: " << box.volume;
}

void setVolume(Box *box) {
    box->volume = box->height * box->width * box->length;
}
