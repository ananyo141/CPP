#ifndef TIMECLASS_H_
#define TIMECLASS_H_

namespace TIME {
    class Time {
    private:
        enum {HR_TO_MIN = 60};
        int hours_;
        long mins_;
    public:
        Time();                                 // default constructor
        Time(double hours);            // explicit constructor, 1 arg
        Time(int hours, long mins);             // non-default constructor, 2 args
        void reset(double hours, int mins=0);   // reset the hours and mins fields
        long toMins() const;                     // convert internal hours and mins to total mins
        template<typename T>
        Time operator-(const T &val)    const;  // Obj - Generic type
        Time operator-(const Time &obj) const;  // Obj - Obj
        template<typename T>                    // Generic Type - Obj
        friend Time operator-(const T &val, const Time &obj);
        template<typename T>
        Time operator+(const T &val)    const;  // Obj + Generic
        Time operator+(const Time &obj) const;  // Obj + Obj
        template<typename T>                    // Generic + Obj
        friend Time operator+(const T &val, const Time &obj);
        template<typename T>
        Time operator*(T &val)          const;   // Obj * Generic
        Time operator*(const Time &obj) const;  // Obj * Obj
        friend Time operator*(double val, const Time &obj);
        void show() const;                      // Show the current time
        // Support std::cout or derivatives of ostream
        friend std::ostream & operator<<(std::ostream &os, const Time &obj);
    };
}

#endif

