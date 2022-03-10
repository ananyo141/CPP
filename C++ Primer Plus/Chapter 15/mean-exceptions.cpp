// Yes, the filename is deliberate.
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace {
    // Exception Classes
    class mean_exception: public std::logic_error {
        private:
            std::string _errmsg;
        public:
            mean_exception(): std::logic_error("None"), _errmsg("None") { }
            mean_exception(const std::string &what_arg, const std::string &funcname)
                : std::logic_error(what_arg) {
                _errmsg = "Error in " + funcname + "\n" + what_arg + "\n";
            }
            virtual ~mean_exception() = 0;
            virtual const char *what() const noexcept {
                return _errmsg.c_str();
            }
    };
    inline mean_exception::~mean_exception() {}

    class bad_hmean: public mean_exception {
        public:
            bad_hmean() { }
            explicit bad_hmean(const std::string &what_arg)
                : mean_exception(what_arg, "hmean") { }
    };

    class bad_gmean: public mean_exception {
        public:
            bad_gmean() { }
            explicit bad_gmean(const std::string &what_arg)
                : mean_exception(what_arg, "gmean") { }
    };

    // Function definitions
    double hmean(double a, double b) {
        if (a == -b)
            throw bad_hmean("A and B can't be equal and opposite");
        return 2.0 * a * b / (a + b);
    }

    double gmean(double a, double b) {
        if (a <= 0 || b <= 0)
            throw bad_gmean("Arguments can't be 0 or negative");
        return std::sqrt(a * b);
    }
}

int main() {
    double a, b, h_mean, g_mean;
    std::cout << "Keep entering two numbers:\n";
    while (std::cin >> a >> b) {
        try {
            h_mean = hmean(a, b);
            g_mean = gmean(a, b);
        } catch (mean_exception &me) {
            std::cerr << "Exception caught:\n"
                      << me.what();
            break;
        }
        std::cout << "Harmonic mean of "  << a << " and " << b << " is: " << h_mean << '\n';
        std::cout << "Geometric mean of " << a << " and " << b << " is: " << g_mean << '\n';
    }
    return 0;
}

