#include <iostream>
#include <memory>
#include <vector>

namespace {
    class Talkative {
    private:
        static int numObj_;
    public:
        Talkative() {
            std::cerr << "Object #" << ++numObj_ << " created\n";
        }
        virtual ~Talkative() {
            std::cerr << "Object #" << numObj_-- << " destroyed\n";
        }
    };
    int Talkative::numObj_ = 0;
}

int main() {
    // Automatic Scoped Objects 
    // (freed when scope lost)
    std::cout << "\nAutomatic Scoped Objects:\n";
    {
        Talkative a;
        {
            Talkative b;
            Talkative c;
        }
        Talkative d;
    }

    // Dynamically Allocated, not 
    // freed when scope escaped
    std::cout << "\nHeap Allocated bare pointers\n";
    {
        Talkative *a = new Talkative;
        {
            Talkative *b = new Talkative;
            Talkative *c = new Talkative;
        }
        Talkative *d = new Talkative;
    }

    // Using unique pointers
    std::cout << "\nUnique Pointers\n";
    {
        std::unique_ptr<Talkative> a(new Talkative);
        {
            std::unique_ptr<Talkative> b(new Talkative);
            std::unique_ptr<Talkative> c(new Talkative);
        }
        std::unique_ptr<Talkative> d(new Talkative);
    }

    // using shared_ptr
    std::cout << "\nShared Pointers\n";
    {
        using talk_ptr = std::shared_ptr<Talkative>;
        talk_ptr a(new Talkative);
        std::vector<talk_ptr> smart_arr;
        {
            for (int i = 0; i < 10; i++)
                smart_arr.push_back(talk_ptr(a));
            std::cout << "Is Unique: " << std::boolalpha << a.unique()
                      << "\nNumber of references to same object: " << a.use_count()
                      << '\n';
        }
    }
    return 0;
}

