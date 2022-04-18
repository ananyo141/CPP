// Use multimap

#include <iostream>
#include <map>

using MapPair = std::pair<int, std::string>;
using MapCode = std::multimap<int, std::string>;

int main() {
    int areaCodes[] = {415, 510, 718, 718, 510, 415};
    const char *areaNames[] = {
        "San Fransisco", "Oakland", "Brooklyn",
        "Staten Island", "Berkeley", "San Rafael"
    };
    const unsigned areaNum = sizeof(areaCodes)  / sizeof(areaCodes[0]);
    static_assert(areaNum == (sizeof(areaNames) / sizeof(areaNames[0]) ),
            "Number of area codes and their corresponding names should be same"); 

    std::multimap<int, std::string> areaMap;
    for (int i = 0; i < areaNum; i++)
        areaMap.insert({areaCodes[i], areaNames[i]});

    // Results
    std::cout << "Number of cities with area code 415: "   << areaMap.count(415)
              << "\nNumber of cities with area code 718: " << areaMap.count(718)
              << "\nNumber of cities with area code 510: " << areaMap.count(510)
              << '\n';

    std::cout << "Area Code\t City\n";
    // std::pair<int, std::string>
    for (const auto &items: areaMap)
        std::cout << items.first << "\t " << items.second << '\n';

    // PAIR OF UPPER AND LOWER BOUND OF MULTIMAP OBJECT
    // std::pair<std::multimap<int, string>::iterator,
    //           std::multimap<int, string>::iterator> range;
    auto range = areaMap.equal_range(718);
    // std::multimap<int, string>::iterator it;
    std::cout << "\nAreas with codes 718\n";
    for (auto it = range.first; it != range.second; it++)
        std::cout << (*it).second << '\n';

    return 0;
}

