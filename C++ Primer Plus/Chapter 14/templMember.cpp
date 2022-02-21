// Class with a template member

#include <iostream>

namespace {
    // Declaration
    template <typename T>
    class Beta {
    private:
        // An internal template class declaration
        template <typename U>
        class Hold;
        Hold<T>   mem1_;
        Hold<int> mem2_;
    public:
        Beta(T n1, int n2);
        // template method
        template <typename V>
        V blob(const V &a, const T &b);
        void show() const;
    };

    // Definitions //
    // Nested template class definition
    template <typename T>
        template <typename U>
        class Beta<T>::Hold {
        private:
            U var_;
        public:
            Hold(U var) : var_(var) { }
            U & get() { return var_; }
            void show() const { std::cout << var_; }
        };

    // template method
    template <typename T>
        template <typename V>
        V Beta<T>::blob(const V &a, const T &b) {
            return (a * b) / (mem1_.get() * mem2_.get());
        }

    template <typename T>
    void Beta<T>::show() const {
        mem1_.show();
        mem2_.show();
    }

    template <typename T>
    Beta<T>::Beta(T n1, int n2) 
        : mem1_(n1), mem2_(n2) { }

}

int main() {
    Beta<double> guy(3.5, 3);
    guy.show();
    std::cout << guy.blob(3, 33.3) << '\n';
    std::cout << guy.blob(3.3, 12) << '\n';
    return 0;
}

