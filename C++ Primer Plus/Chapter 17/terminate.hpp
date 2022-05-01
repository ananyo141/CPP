// Use variadic template to rewrite the terminate function
#ifndef TERMINATE_HPP_
#define TERMINATE_HPP_

#include <iostream>

namespace ter {
    // Inline non-template version that acts as the ultimate
    // call to exit with a non-zero return code
    inline void terminate() {
        std::exit(EXIT_FAILURE);
    }

    // Base condition for recursion; displays the final argument
    // and calls an (non-template, non-recursive) overload of itself to 
    // terminate with failure code
    template <typename T>
    void terminate(const T& value) {
        std::cerr << value << '\n';
        terminate();
    }

    // Recursive call to terminate that processes one template parameter
    // at a time and for the final argument calls the base-condition
    // overload that only takes one argument
    template <typename T, typename... Args>               // pack template type args
    void terminate(const T& value, const Args&... args) { // pack function args
        std::cerr << value << ' ';
        terminate(args...);         // unpack function args
    }
}

#endif // for #ifndef TERMINATE_HPP_

