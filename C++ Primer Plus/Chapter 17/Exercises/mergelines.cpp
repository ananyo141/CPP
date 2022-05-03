/* 4. Write a program that opens two text files for input and one for output.The pro-
gram should concatenate the corresponding lines of the input files, use a space as a
separator, and write the results to the output file. If one file is shorter than the other,
the remaining lines in the longer file should also be copied to the output file.  */

#include <iostream>
#include <fstream>
#include "../terminate.hpp"

template <typename T>
static void checkfile(T &stream, const std::string &fname) {
    /* Use only files types i.e, ifstream, ofstream, fstream */
    if (!stream.is_open())
        ter::terminate("Unable to open file", fname);
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4)
        ter::terminate("Usage:", *argv, "FILE1 FILE2 [OUTFILE]");
    const char *filename1 = argv[1];
    const char *filename2 = argv[2];
    const char *filename3 = (argc == 4) ? argv[3] : "result.out";

    std::ifstream infile1(filename1), infile2(filename2);
    checkfile(infile1, filename1);
    checkfile(infile2, filename2);
    std::ofstream outfile(filename3);
    checkfile(outfile, filename3);

    std::string buffer;
    while (infile1 || infile2) {
        if (getline(infile1, buffer))
            outfile << buffer << ' ';
        if (getline(infile2, buffer))
            outfile << buffer;
        outfile << '\n';
    }
    std::cout << "File written as: " << filename3 << '\n';
    return 0;
}

