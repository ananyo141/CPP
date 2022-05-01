
#include <iostream>
#include <cstdio>

int main() {
    char tmparr[L_tmpnam];
    char mkstemparr[] = "temp.XXXXXXX";
    std::cout << "Creating " << TMP_MAX 
        << " number of temporary filenames of size: " << L_tmpnam << "\n";
    for (int i = 0; i < TMP_MAX; i++)
        std::cout << std::tmpnam(tmparr) << '\n';

    std::cout << mkstemp(mkstemparr) << '\n';
    std::cout << mkstemparr << '\n';
    return 0;
}

