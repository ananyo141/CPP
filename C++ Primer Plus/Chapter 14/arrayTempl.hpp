#ifndef ARRAY_TEMPL_HPP_
#define ARRAY_TEMPL_HPP_

namespace arr {
    // Class Declaration
    template <typename T, int size>
    class Array {
    protected:
        static void checkBounds(int i);
    private:
        T arr_[size];
        const int arrsiz_ = size; // save the non-type arg as a class attr
    public:
        Array() { }
        explicit Array(const T &val);
        virtual ~Array() { }
        virtual T & operator[](int i);
        virtual T operator[](int i) const;
    };

    // Template Method Definitions
    template <typename T, int n>
    void Array<T,n>::checkBounds(int i) {
        //static_assert(i >= 0 && i < n, "Invalid Range");
    }

    template <typename T, int n>
    Array<T, n>::Array(const T &val) {
        for (int i = 0; i < n; i++)
            arr_[i] = val;
    }

    template <typename T, int n>
    T & Array<T,n>::operator[](int i) {
        checkBounds(i);
        return arr_[i];
    }

    template <typename T, int n>
    T Array<T,n>::operator[](int i) const {
        checkBounds(i);
        return arr_[i];
    }
}

#endif

