#include <iostream>
const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int  ooplevel;
};

// prototypes //
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    std::cout << "Enter class size: ";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout << "Done\n";

    return 0;
}

int getinfo(student pa[], int n)
{
/*  getinfo() has two arguments: a pointer to the first element of
    an array of student structures and an int representing the
    number of elements of the array. The function solicits and
    stores data about students. It terminates input upon filling
    the array or upon encountering a blank line for the student
    name. The function returns the actual number of array elements
    filled.                                                       */

    for (student *ptr = pa; ptr < pa + n; ptr++)
    {
        std::cout << "Enter student-#" << ptr - pa + 1 << " name: ";
        std::cin.getline(ptr->fullname, SLEN);
        if (!ptr->fullname[0]) return ptr - pa;

        std::cout << "Enter hobby: ";
        std::cin.getline(ptr->hobby, SLEN);
        std::cout << "Enter OOP Level: ";
        std::cin  >> ptr->ooplevel;
        while (std::cin.get() != '\n') ;
    }
    return n;
}


void display1(student st)
{
/*  display1() takes a student structure as an argument
    and displays its contents                          */

    std::cout << "Student name: " << st.fullname;
    std::cout << "\nHobby: " << st.hobby;
    std::cout << "\nOOP Level: " << st.ooplevel << '\n';
}

void display2(const student *ps)
{
/*  display2() takes the address of student structure as an
    argument and displays the structure’s contents */

    std::cout << "Student name: " << ps->fullname;
    std::cout << "\nHobby: " << ps->hobby;
    std::cout << "\nOOP Level: " << ps->ooplevel << '\n';
}

void display3(const student pa[], int n)
{
/*  display3() takes the address of the first element of an array
    of student structures and the number of array elements as
    arguments and displays the contents of the structures        */

    for (const student *ptr = pa; ptr < pa + n; ptr++)
        display2(ptr);
}
