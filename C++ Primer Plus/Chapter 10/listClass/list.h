#ifndef LIST_H_
#define LIST_H_

namespace LIST {
    class list {
    private:
        typedef double Item;
        struct Node {
            Item data_;
            Node *next_;
        };
        Node *start_;
    public:
        list();
        list(const Item &);
        ~list();
        bool isempty();
        bool isfull();
        void add(const Item &);
        void visit(void (*pf)(Item &));
    };
}

#endif

