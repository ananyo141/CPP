/* 4. The following is a program skeleton,
Complete this skeleton by providing the described functions and prototypes. Note
that there should be two show() functions, each using default arguments. Use
const arguments when appropriate. Note that set() should use new to allocate
sufficient space to hold the designated string.The techniques used here are similar
to those used in designing and implementing classes. (You might have to alter the
header filenames and delete the using directive, depending on your compiler.) */

#include <iostream>
#include <cstring>
using namespace std;

struct stringy {
    char * str;
    int ct;
};

// prototypes for set(), show(), and show() go here
void set(stringy &ref, const char *str, int ct = 1);
void show(stringy &ref, int ct = 1);
void show(const char *str, int ct = 1);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);        // prints member string once
    show(beany, 2);     // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);      // prints testing string once
    show(testing, 3);   // prints testing string thrice

    show("Done!");
    return 0;
}

// definitions //
void set(stringy &ref, const char *str, int ct) {
    /* first argument is a reference,
    allocates space to hold copy of testing,
    sets str member of beany to point to the
    new block, copies testing to new block,
    and sets ct member of beany */

    ref.str = new char[strlen(str)];
    strcpy(ref.str, str);
    ref.ct = ct;
}
void show(stringy &ref, int ct) {
    for (int i = 0; i < ct; i++)
        cout << ref.str << "\n";
}
void show(const char *str, int ct) {
    for (int i = 0; i < ct; i++)
        cout << str << "\n";
}
