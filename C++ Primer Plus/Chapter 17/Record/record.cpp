
#include <fstream>
#include "record.hpp"
#include "../../Chapter 16/readUtils.hpp"

namespace rec {
    std::ostream& operator<<(std::ostream& out, const Record &r) {
        std::ios_base::fmtflags old = out.setf(std::ios_base::right, std::ios_base::adjustfield);
        out << std::setw(Record::FIELD_W) << "Planet: "      << r.name       << '\n'
            << std::setw(Record::FIELD_W) << "Population: "  << r.population << '\n'
            << std::setw(Record::FIELD_W) << "Grav. Accln: " << r.g_accl     << '\n';
        std::cout.put('\n');
        out.setf(old, std::ios_base::adjustfield);
        return out;
    }

    std::istream& operator>>(std::istream& in, Record &r) {
        rd::readvalue(r.name, r.NAME_MAX, "Enter planet name: ", false);
        rd::readvalue(r.population, "Enter planet population: ", false);
        rd::readvalue(r.g_accl, "Enter planet gravitational accl: ", false);
        return in;
    }

    void Record::show() const {
        std::cout << std::setw(FIELD_W) << name << ": "
                  << std::setw(FIELD_W) << population 
                  << std::setw(FIELD_W) << g_accl << '\n';
    }

    std::fstream& FileOperation::operator()(std::fstream &file) {
        savepos(file);
        file.clear();

        file.seekg(0);
        file.seekp(0);
        execute(file);

        file.clear();
        resetpos(file);
        return file;
    }

    void FileOperation::savepos(std::fstream &file) {
        inpPos_ = file.tellg();
        outPos_ = file.tellp();
    }

    void FileOperation::resetpos(std::fstream &file) const {
        file.seekg(inpPos_);
        file.seekp(outPos_);
    }

    void PrintFile::execute(std::fstream &file) {
        char ch;
        while (file.get(ch))
            std::cout << ch;
    }

    void GetRecords::execute(std::fstream &file) {
        /* Get the records from the binary file */
        int num = 0;
        Record input;
        while (file.read(reinterpret_cast<char *> (&input), sizeof input) ) {
            std::cout << ++num << ": ";
            input.show();
        }
    }

    std::fstream& PutRecords::operator()(std::fstream &file, const recdb &records) {
        savepos(file);
        file.clear();

        file.seekg(0);
        file.seekp(0);
        execute(file, records);

        file.clear();
        resetpos(file);
        return file;
    }

    void PutRecords::execute(std::fstream &file, const recdb &records) {
        for (const auto &item: records) {
            file.write(reinterpret_cast<const char *> (&item), sizeof(item) );
        }
    }

    std::fstream& AppendRecords::operator()(std::fstream &file, const recdb &records) {
        savepos(file);
        file.clear();

        execute(file, records);

        file.clear();
        resetpos(file);
        return file;
    }
}  

