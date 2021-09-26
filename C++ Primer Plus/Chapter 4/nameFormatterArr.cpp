/****************************************************************************************
3. Write a program that asks the user to enter his or her first name and then last
name, and that then constructs, stores, and displays a third string, consisting of the
user’s last name followed by a comma, a space, and first name. Use char arrays and
functions from the cstring header file.A sample run could look like this:
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip
*****************************************************************************************/
#include <iostream>
#include <cstring>    // C library for string handling
const short ARRSIZE = 50;

int main() {
    using namespace std;

    char firstName[ARRSIZE], lastName[ARRSIZE];
    cout << "Enter your first name: ";
    cin.get(firstName, ARRSIZE).get();
    cout << "Enter your last name: ";
    cin.get(lastName, ARRSIZE).get();

    unsigned nameLen = strlen(firstName) + strlen(lastName) + 3; // add comma, space and null

    char fullName[nameLen];
    strcpy(fullName, lastName);
    strcat(fullName, ", ");
    strcat(fullName, firstName);
    cout << "Here's the information in a single string: ";
    cout << fullName << endl;

    return 0;
}
