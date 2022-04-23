#ifndef PERFCOUNTER_HPP_
#define PERFCOUNTER_HPP_

#include <iostream>
#include <stack>
#include <map>
#include <ctime>

namespace perf {
    class PerfCounter {
    public:
        using recordtime_t = std::pair<clock_t, std::string>; // while recording, use clock_t
        using outputtime_t = std::pair<double,  std::string>; // output elapsed time in seconds

    private:
        std::stack<recordtime_t> time_stack_;
        std::map<std::string, double> time_db_;

    public:
        const std::map<std::string, double> &times = time_db_;

        PerfCounter()          { }
        virtual ~PerfCounter() { }
        virtual void start(const std::string &label) {
            /* Record time in clock_t and label */
            time_stack_.push({clock(), label});
        }

        virtual outputtime_t stop() {
            /* Stop the latest counter and output elapsed time in seconds */
            auto latest = time_stack_.top();
            time_stack_.pop();
            double time_elapsed = (clock() - latest.first) / double(CLOCKS_PER_SEC);
            time_db_[latest.second] = time_elapsed;
            return outputtime_t (time_elapsed, latest.second);
        }

        void clear() {
            /* Clear the stack and time databases */
            time_stack_ = {}; // clear hack in stack; initialize to null stack
            time_db_.clear(); 
        }

        int num_times() const { return time_stack_.size(); }
    };
}

#endif // for #ifndef PERFCOUNTER_HPP_

