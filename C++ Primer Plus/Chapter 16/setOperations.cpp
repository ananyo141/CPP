// Set operations

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

int main() {
    std::initializer_list<std::string> init1 = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    std::initializer_list<std::string> init2 = {"metal", "any", "food", "elegant", "deliver", "for"};

    // use an ostream iterator
    std::ostream_iterator<std::string, char> out(std::cout, " ");
    // initialize sets from both lists
    std::set<std::string> s1(init1);
    std::set<std::string> s2(init2);

    // find set union
    std::cout << "s1 union s2\n";
    std::set_union(s1.cbegin(), s1.cend(),
            s2.cbegin(), s2.cend(),
            out);
    std::cout.put('\n');
    // find set intersection
    std::cout << "s1 intersection s2\n";
    std::set_intersection(s1.cbegin(), s1.cend(),
            s2.cbegin(), s2.cend(),
            out);
    std::cout.put('\n');
    // find set difference
    std::cout << "s1 difference s2\n";
    std::set_difference(s1.cbegin(), s1.cend(),
            s2.cbegin(), s2.cend(),
            out);
    std::cout.put('\n');

    // find set union and save in another set
    std::set<std::string> s3;
    std::set_union(s1.cbegin(), s1.cend(),
            s2.cbegin(), s2.cend(),
            std::insert_iterator<std::set<std::string>> (s3, s3.begin()));
    std::cout.put('\n');
    std::cout << "s3 (Union):\n";
    std::copy(s3.cbegin(), s3.cend(), out);
    std::cout.put('\n');

    std::string str("NEWStr");
    s3.insert(str);
    std::cout << "s3:\n";
    std::copy(s3.cbegin(), s3.cend(), out);
    std::cout.put('\n');
    std::copy(s3.lower_bound("any"), s3.upper_bound("thinkers"), out);
    std::cout.put('\n');

    return 0;
}

