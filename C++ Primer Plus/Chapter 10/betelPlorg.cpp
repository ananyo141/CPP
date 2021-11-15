/* 7. A Betelgeusean plorg has these properties:
Data
A plorg has a name with no more than 19 letters.
A plorg has a contentment index (CI), which is an integer.
Operations
A new plorg starts out with a name and a CI of 50.
A plorg’s CI can change.
A plorg can report its name and CI.
The default plorg has the name "Plorga".
Write a Plorg class declaration (including data members and member function pro-
totypes) that represents a plorg.Write the function definitions for the member func-
tions.Write a short program that demonstrates all the features of the Plorg class. */

#include <iostream>
#include <cstring>

class Plorg {
private:
    enum {ARRSIZE = 20};
    char name_[ARRSIZE];
    int contInd_;
public:
    Plorg() {
        strcpy(name_, "Plorga");
        contInd_ = 50;
    }
    Plorg(const char *name, int ci = 50) {
        strncpy(name_, name, ARRSIZE);
        contInd_ = ci;
    }
    int changeCI(int ci) {
        int prevCI = contInd_;
        contInd_ = ci;
        return prevCI;
    }
    void introduce() const {
        for (int i = 0; i < 35; i++)
            std::cout << '*';
        std::cout << "\nPlorg Name:       " << name_
                  << "\nContentmentIndex: " << contInd_
                  << '\n';
    }
};

int main() {
    Plorg friends[] = {
        Plorg(),
        Plorg("Tekken"),
        Plorg("Tengu", 33)
    };
    int i, len = sizeof(friends) / sizeof(friends[0]);

    for (i = 0; i < len; i++)
        friends[i].introduce();

    for (i = 0; i < len; i++)
        std::cout << "Prev: " << friends[i].changeCI(i) << '\n';

    for (i = 0; i < len; i++)
        friends[i].introduce();

    return 0;
}

