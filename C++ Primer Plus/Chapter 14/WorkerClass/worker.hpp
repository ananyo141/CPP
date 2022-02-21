#ifndef WORKER_HPP_
#define WORKER_HPP_

#include <iostream>

namespace work {
    class Worker {
    private:
        std::string name_;
        long id_;
    protected:
        virtual void getData () = 0;
        virtual void showData() const = 0;
    public:
        Worker() : name_("None"), id_(0) { }
        Worker(const std::string &name, long id)
            : name_(name), id_(id) { }
        // Pure Virtual Functions
        virtual ~Worker()  = 0;
        virtual void set() = 0;
        virtual void show() const = 0;
    };

    class Waiter: virtual public Worker {
    private:
        int panache_;
    protected:
        virtual void getData ();
        virtual void showData() const;
    public:
        Waiter() : Worker(), panache_(0) { }
        Waiter(const std::string &name, long id, int panache=0)
            : Worker(name, id), panache_(panache) { }
        // For converting sibling classes of worker to waiter
        Waiter(const Worker &wk, int panache = 0)
            : Worker(wk), panache_(panache) { }
        virtual void set();
        virtual void show() const;
    };
    
    class Singer: virtual public Worker {
    protected:
        enum class Voices: short {
            other, alto, contralto, soprano,
            bass, baritone, tenor
        };
        enum {VTYPES = 7};
        virtual void getData ();
        virtual void showData() const;
    private:
        static const char *voices_[VTYPES];
        Voices voice_;
    public:
        Singer() : Worker(), voice_(Voices::other) { }
        Singer(const std::string &name, long id, Voices voice=Voices::other)
            : Worker(name, id), voice_(voice) { }
        Singer(const Worker &wk, Voices voice)
            : Worker(wk), voice_(Voices::other) { }
        virtual void set();
        virtual void show() const;
    };

    // Have to explicitly call virtual base class ancestor as data passing through
    // intermediate classes is disabled for virtual derived base classes
    class SingingWaiter: public Waiter, public Singer {
    protected:
        virtual void getData ();
        virtual void showData() const;
    public:
        SingingWaiter() { }
        SingingWaiter(const std::string &name, long id, int panache=0, Voices voice=Voices::other)
            : Worker(name, id), Waiter(name, id, panache), Singer(name, id, voice) { }
        SingingWaiter(const Worker &wk, int panache=0, Voices voice=Voices::other)
            : Worker(wk), Waiter(wk, panache), Singer(wk, voice) { }
        virtual void set();
        virtual void show() const;
    };
}

#endif

