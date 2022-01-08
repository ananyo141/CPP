#ifndef ATM_HPP_
#define ATM_HPP_ 

/* Simple Logger that logs to stderr;
   Use #undef and redefine DEBUG to disable logging inplace */
#define DEBUG(elem) std::cerr << "LOG #" << __LINE__ << ": " << \
                    #elem " = " << elem << std::endl
#include <iostream>
#include <cstdlib>

namespace ATM {
    const int MIN_PER_HR = 60;

    bool checkCustomer(double chance);

    template <typename T>
    void readValue(const char *prompt, T &inp) {
        /* Read a generic value from stdin */
        char ch;
        for (;;) {
            std::cout << prompt;
            if (!(std::cin >> inp)) {             // for failed read,
                if (std::cin.eof()) {
                    std::cerr << "\nUnexpected EOF\n";
                    std::exit(EXIT_FAILURE);      // if end of file reached, critical failure
                }
                std::cin.clear();                            // else clear error
                while (std::cin && std::cin.get() != '\n') ; // and clear input buffer for next read,
                std::cerr << "Invalid input\n";              // taking care for additional eof
                continue;
            }
            while (std::cin.get(ch)) {
                if (ch == '\n') return;           // read successful
                std::cerr << "Trailing character: '" << ch << "'\n";
            }
        }
    }

    class Customer {
    private:
        long arrival_;
        char processtime_;  // for values between 1-3 (inclusive)

    public:
        Customer()        { arrival_ = processtime_ = 0; }
        long getArrival() { return arrival_; }
        int getProcesstime()   { return processtime_; }   // implicitly converted to int
        void set(long arrival, unsigned maxval=3) {
            arrival_ = arrival; 
            processtime_ = std::rand() % maxval + 1;      // return a random value between 1 and maxval
        }
    };

    typedef Customer Item;  // set queue to hold Item (Customer) type

    class Queue {
    private:
        // Nested Node structure
        struct Node {
            Item data_;
            Node *next_;
        };

        enum {Q_MAX = 10};
        const int queuesize_ = Q_MAX;
        int qlen_ = 0;
        Node *front_ = nullptr;  // Head of the queue for deletion
        Node *rear_  = nullptr;  // Tail of the queue for insertion

        // Restrict public copying
        Queue(const Queue &) : queuesize_(0) { }  // restrict copy constructor
        Queue & operator=(const Queue &) { return *this; } // restrict assignment

    public:
        Queue(int qsize=Q_MAX);
        ~Queue();
        bool isfull()  const;
        bool isempty() const;
        bool enqueue(const Item &);
        bool dequeue(Item &);
        int len() const { return qlen_; }
    };
}

#endif

