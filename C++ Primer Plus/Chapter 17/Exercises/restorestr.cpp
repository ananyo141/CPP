
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

namespace {
    class Store {
        std::ofstream &outfile_;
    public:
        Store(std::ofstream &file) : outfile_(file) { }
        void operator()(const string &str) {
            /* Write the contents of the string to the file 
             * Use format: size, string array characters */
            size_t len = str.size();
            outfile_.write(reinterpret_cast<char *> (&len), 
                           sizeof (len) );
            outfile_.write(str.data(), len);
        }
    };

    void ShowStr(const string &str) {
        std::cout << str << '\n';
    }

    void GetStrs(std::ifstream &fin, vector<string> &vstr) {
        /* Get the encoded strings from the file */
        size_t len;
        int i;
        string str;
        while (fin.read(reinterpret_cast<char *> (&len), sizeof len) ) {
            for (i = 0; i < len; i++)
                str += fin.get();
            vstr.push_back(str);
            str.clear();
        }
    }
}

int main() {
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
        vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.out", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.out", ios_base::in | ios_base::binary);

	if (!fin.is_open()) {
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);

	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

