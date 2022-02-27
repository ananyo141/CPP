#ifndef PAIRS_HPP_
#define PAIRS_HPP_

namespace pairs {
    template <typename T1, typename T2>
    class Pairs {
    private:
        T1 a_;
        T2 b_;
    public:
        Pairs(const T1 &first, const T2 &second);
        T1 & first();
        T2 & second();
        const T1 & first () const;
        const T2 & second() const;
    };

    template <typename T1, typename T2>
    Pairs<T1, T2>::Pairs(const T1 &first, const T2 &second)
        : a_(first), b_(second)  { }

    template <typename T1, typename T2>
    const T1 & Pairs<T1, T2>::first () const { return a_; }

    template <typename T1, typename T2>
    const T2 & Pairs<T1, T2>::second() const { return b_; }

    template <typename T1, typename T2>
    T1 & Pairs<T1, T2>::first()  { return a_; }

    template <typename T1, typename T2>
    T2 & Pairs<T1, T2>::second() { return b_; }
}

#endif

