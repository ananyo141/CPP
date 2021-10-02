/*
8. Write a program that opens a text file, reads it character-by-character to the end of
the file, and reports the number of characters in the file.
*/
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: <fileCharCount> /path/to/file\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }

    unsigned spaces = 0, numChars = 0;
    char ch;
    while(inFile.get(ch)) {
        if  (isblank(ch)) spaces++; 
        else if (isspace(ch)) ; // skip newlines, tabs
        else numChars++;
    }
    if (inFile.eof())  std::cout << "End of file reached\n";
    else if (inFile.fail()) std::cerr << "Unable to read file\n";

    std::cout << "Total characters: " << numChars << 
                 " (and " << spaces << " spaces)" << std::endl;

    inFile.close();

    return 0;
}
