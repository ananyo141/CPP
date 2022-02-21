// Template class that takes a template parameter as it's type argument

#include <iostream>
#include "StackTemplate/stackTemp.hpp"

namespace {
    // Template parameter, type parameter, non-type parameter
    template <template <typename T> class TempParam, typename U, int n>
    class ClassWithTemplArg {
    private:
        TempParam<U> TemplMem_;
        int arr_[n];
    public:
        ClassWithTemplArg() { }
        template <typename V>
        V templateMethod(const V &arg) { return arg;                 }
        bool push(const U &arg)        { return TemplMem_.push(arg); }
        bool pop(U &arg)               { return TemplMem_.pop(arg);  }
    };
}

int main() {
    ClassWithTemplArg<stack::Stack, double, 3> nebula;
    nebula.push(nebula.templateMethod(33.3f));
    nebula.push(nebula.templateMethod(33));

    double a1;
    nebula.pop(a1);
    std::cout << a1 << '\n';
    nebula.pop(a1);
    std::cout << a1 << '\n';

    return 0;
}

