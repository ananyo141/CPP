#ifndef STACKTEMP_HPP_
#define STACKTEMP_HPP_

namespace stack {
    template <typename T>
    class Stack {
    private:
        enum {DEFSIZ = 10};
        const unsigned size_;
        T *const items_ = new T[size_];   // define defaults in declaration
        int top_ = 0;                     // instead of member-initializer lists

        Stack(const Stack &) { }             // disable public copy constr and
        Stack & operator=(const Stack &) { } // assignment operator
    public:
        explicit Stack(unsigned s_siz=DEFSIZ) : size_(s_siz) { }
        ~Stack() { delete [] items_; }
        bool isempty() const { return top_ == 0; }
        bool isfull () const { return top_ == size_; }
        bool pop(T &var);
        bool push(const T &var);
    };

    // Template Method Definitions
    template<typename T>
    bool Stack<T>::pop(T &var) {
        if (isempty())
            return false;
        var = items_[--top_];
        return true;
    }

    template<typename T>
    bool Stack<T>::push(const T &var) {
        if (isfull())
            return false;
        items_[top_++] = var;
        return true;
    }
}

#endif

