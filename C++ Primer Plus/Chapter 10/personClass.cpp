#include <iostream>
#include <cstring>

class Person {
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person() {
        lname = "nil";
        strncpy(fname, "nil", LIMIT-1);
        fname[LIMIT-1] = '\0';
    }
    Person(const std::string & ln, const char *fn = "Heyyou") {
        lname = ln;
        strncpy(fname, fn, LIMIT-1);
        fname[LIMIT-1] = '\0';      // assure always null-terminated
    }
    void Show() const {
        std::cout << fname << " " << lname << '\n';
    }
    void FormalShow() const {
        std::cout << lname << ", " << fname << '\n';
    }
};

int main() {
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    std::cout << std::endl;
    one.FormalShow();

    two.Show();
    std::cout << std::endl;
    two.FormalShow();

    three.Show();
    std::cout << std::endl;
    three.FormalShow();

    return 0;
}

