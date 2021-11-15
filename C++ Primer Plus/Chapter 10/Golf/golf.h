#ifndef GOLF_H_
#define GOLF_H_

namespace glf {
    class Golf {
    private:
        enum {LEN = 40};
        char fullname_[LEN];
        int handicap_;
    public:
        Golf();
        Golf(const char *name, int hc);
        int setgolf();
        void handicap(int hc);
        void showgolf() const;
    };
}

#endif

