// Use containment to implement a class of students

#ifndef STUDCONT_HPP_
#define STUDCONT_HPP_

#include <iostream>
#include <valarray>

namespace stud {
    class Student {
    protected:
        // C++11 alternative 'using' to typedef std::valarray<double> ScoreDB
        using ScoreDB = std::valarray<double>;
        void _showScore(std::ostream &os) const;
    private:
        std::string name_;
        ScoreDB scores_;
    public:
        explicit Student(const std::string &name="None") 
            : name_(name), scores_()               { }
        explicit Student(int n)
            : name_("None"), scores_(n)            { }
        Student(const std::string &name, int scoresize) 
            : name_(name), scores_(scoresize)      { }
        Student(const std::string &name, const ScoreDB &values)
            : name_(name), scores_(values)         { }
        Student(const char *name, const double *scorearr, int size)
            : name_(name), scores_(scorearr, size) { }

        const std::string & getName() const { return name_; }
        double average() const {
            return (!scores_.size()) ? 0 : scores_.sum() / double(scores_.size());
        }
        double & operator[](int i)       { return scores_[i]; } // non-const version, can change insitu
        double   operator[](int i) const { return scores_[i]; } // const version, return by value

        friend std::ostream &
        operator<<(std::ostream &os, const Student &st);
        friend std::istream &
        operator>>(std::istream &is, Student &st);
        friend std::istream &
        getline(std::istream &is, Student &st);
    };

}

namespace util {
    template <typename T>
    void readVal(T &val, const std::string &prompt) {
        for (;;) {
            std::cout << prompt;
            if (!(std::cin >> val)) {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    ;
                std::cerr << "Invalid Input\n";
            }
            else break;
        }
//        while (std::cin.get() != '\n')
//            ;
    }
    template<>
    void readVal(std::string &val, const std::string &prompt);
}

#endif

