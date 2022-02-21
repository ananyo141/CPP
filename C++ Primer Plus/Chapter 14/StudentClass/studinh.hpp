// Has-A relationship by Private Inheritance

#ifndef STUDINH_HPP_
#define STUDINH_HPP_

#include <iostream>
#include <valarray>

namespace studinh {
    using ScoreDB = std::valarray<double>;
    // Inheriting base classes create unnamed base objects
    class Student: private std::string, private ScoreDB
    {
    protected:
        void _showScore(std::ostream &os) const;
    public:
        // Use the methods of the privately derived classes
        using std::string::size;
        using ScoreDB::max;
        using ScoreDB::min;

        explicit Student(const std::string &name="None")
            : std::string(name), ScoreDB()               { }   // call base class constructors
        explicit Student(int n)
            : std::string("None"), ScoreDB(n)            { }
        Student(const std::string &name, int scoresize)
            : std::string(name), ScoreDB(scoresize)      { }
        Student(const std::string &name, const ScoreDB &values)
            : std::string(name), ScoreDB(values)         { }   // invoke base copy constr
        Student(const char *name, const double *scorearr, int size)
            : std::string(name), ScoreDB(scorearr, size) { }

        virtual const std::string & getName() const { return (std::string &) *this; }
        virtual double average() const {
            return (!ScoreDB::size()) ? 0 : ScoreDB::sum() / double(ScoreDB::size());
        }
        double & operator[] (int i)     { return ScoreDB::operator[](i); }
        double operator[] (int i) const { return ScoreDB::operator[](i); }

        friend std::ostream &
        operator<<(std::ostream &os, const Student &st);
        friend std::istream &
        operator>>(std::istream &is, Student &st);
        friend std::istream &
        getline(std::istream &is, Student &st);
    };
}

#endif

