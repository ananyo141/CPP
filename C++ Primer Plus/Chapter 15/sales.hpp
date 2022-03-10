#ifndef SALES_HPP_
#define SALES_HPP_
#include <stdexcept>

namespace Sales {
    class Sales {
    protected:
        enum {MONTHS = 12};
    private:
        int _year;
        double _gross[MONTHS] = {0};
    public:
        class bad_index: public std::logic_error {
        private:
            int _badInd;
            std::string _errmsg;
        public:
            bad_index(int ind, const std::string &what_arg="Index Error");
            virtual ~bad_index() {}
            int index() const { return _badInd; }
            const char *what() noexcept;
        };

        explicit Sales(int year=0);
        Sales(int year, const double *grossArr, int n);
        virtual ~Sales() noexcept { }
        int yearVal() const { return _year; }
        virtual double & operator[](int i);
        virtual double operator[](int i) const;
    };

    class LabeledSales: public Sales {
    private:
        std::string _label;
    public:
        class lbad_index: public Sales::bad_index {
        private:
            std::string _label;
        public:
            lbad_index(const std::string &label, int ind, 
                    const std::string &what_arg="Labeled Index Error")
                : bad_index(ind, what_arg), _label(label) {}
            const std::string &get_label() const { return _label; }
        };

        explicit LabeledSales(const std::string &label="None", int y=0);
        LabeledSales(const std::string &label, int y, double *grossArr, int n);
        const std::string &get_label() const { return _label; }
        double & operator[](int i);
        double operator[](int i) const;
    };
}

#endif

