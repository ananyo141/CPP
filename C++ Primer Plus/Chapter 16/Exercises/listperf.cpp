// Performance measurement of stl containers

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "perfcounter.hpp"

const int TEST_NUM  = 10000000;
const int RANDUPPER = 10000;

int main() {
    std::srand(std::time(0));
    std::vector<int> value_arr(TEST_NUM);
    for (int i = 0; i < TEST_NUM; i++)
        value_arr[i] = std::rand() % RANDUPPER;

    auto counter = perf::PerfCounter();
    std::vector<int> vi(value_arr);
    std::list<int> li(value_arr.cbegin(), value_arr.cend());

    counter.start("vi (Vector sort using std::sort)");
    std::sort(vi.begin(), vi.end());
    counter.stop();

    counter.start("li (List sort using sort method)");
    li.sort();
    counter.stop();

    std::copy(value_arr.cbegin(), value_arr.cend(), li.begin());

    counter.start("li -> vi (List sort by copying to vector and back)");
    std::copy(li.cbegin(), li.cend(), vi.begin());
    std::sort(vi.begin(), vi.end());
    std::copy(vi.cbegin(), vi.cend(), li.begin());
    counter.stop();

    for (const auto &item: counter.times)
        std::cout << item.first << ": " << item.second << "s\n";

    return 0;
}

