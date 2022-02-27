#ifndef QUEUE_TP_HPP_
#define QUEUE_TP_HPP_

namespace queueTp {
    // Class Template Declaration
    template <typename T>
    class Queue {
    protected:
        struct Node {
            T data_;
            Node *next_;
        };
    private:
        Node *front_;
        Node *rear_;
    public:
        Queue();
        Queue(const Queue &) = delete;
        Queue & operator=(const Queue &) = delete;
        virtual ~Queue();
        virtual bool insert(const T &);
        virtual bool remove(T &);
    };

    // Method Definitions
    template <typename T>
    Queue<T>::Queue() {
        front_ = nullptr;
        rear_  = nullptr;
    }

    template <typename T>
    Queue<T>::~Queue() {
        Node *next, *ptr = front_;
        while (ptr) {
            next = ptr->next_;
            delete ptr;
            ptr = next;
        }
    }

    template <typename T>
    bool Queue<T>::insert(const T &input) {
        Node *curr = new Node{input, nullptr};
        (rear_ ? rear_->next_ : front_) = curr;
        rear_ = curr;
        return true;
    }

    template <typename T>
    bool Queue<T>::remove(T &output) {
        if (!front_)
            return false;
        output = front_->data_;
        Node *next = front_->next_;
        delete front_;
        if (front_ == rear_)
            front_ = rear_ = nullptr;
        else
            front_ = next;
        return true;
    }
}

#endif

