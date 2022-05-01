#include <iostream>
#include <cstring>

int main() {
    const char *str1 = "Kansas";
    const char *str2 = "Oklohoma";
    const char *str3 = "Arkansas";

    int i;
    int len = std::strlen(str2);
    std::cout << "Increasing loop index\n";
    for (i = 1; i <= len; i++)
        std::cout.write(str2, i).put('\n');
    std::cout << "\nDecreasing loop index\n";
    while (i-- > 0)
        std::cout.write(str2, i).put('\n');

    std::cout << "Exceeding string length:\n";
    std::cout.write(str2, len + 5).put('\n');
    
     /** Note **
     * The ^@ notation in `cat -A` output of this program is 
     * indicative of the null byte; here it is after str2 
     * and just before str3, when tryng to print more than containing
     * characters in str2 */

    return 0;
}

