#include <iostream>
#include <string>
#include <fstream>
#include "../../Chapter 16/readUtils.hpp"

class abstr_emp {
protected:
    static void readString (std::ifstream &in, std::string &str) {
        /* Read a string length and corresponding stream from
        * a file */
        str.clear();
        size_t len;
        in >> len;
        in.get(); // for the space
        for (int i = 0; i < len; i++)
            str += in.get();
    }

    static void writeString(std::ofstream &out, const std::string &str) {
        /* Write a string along with size to output file stream */
        size_t len = str.size();
        out << len << ' ';
        out.write(str.data(), len).put('\n');
    }

private:
    std::string fname;
    std::string lname;
    std::string job;

public:
    abstr_emp(): fname("None"), lname("None"), job("None") {}
    abstr_emp(const std::string & fn, const std::string & ln,
        const std::string & j): fname(fn), lname(ln), job(j) {}

    virtual void ShowAll() const {          // labels and shows all data
        std::cout << "FirstName: " << fname
                  << "\nLastName: " << lname
                  << "\nJob: " << job
                  << '\n';
    }

    virtual void SetAll() {                  // prompts user for values
        rd::readvalue(fname, "Enter first name: ");
        rd::readvalue(lname, "Enter last name: ");
        rd::readvalue(job, "Enter job: ");
    }

    virtual void WriteAll(std::ofstream &out) {
        writeString(out, fname);
        writeString(out, lname);
        writeString(out, job);
    }

    virtual void ReadAll(std::ifstream &in) {
        readString(in, fname);
        readString(in, lname);
        readString(in, job);
    }

    friend std::ostream &
    operator<<(std::ostream & os, const abstr_emp & e) { // just displays first and last name
        os << e.fname << ' ' << e.lname << '\n';
        return os;
    }
    virtual ~abstr_emp() = 0;               // virtual base class
};

inline abstr_emp::~abstr_emp() { }

class employee : public abstr_emp {
public:
    employee() {}   // defaults
    employee(const std::string & fn, const std::string &ln, const std::string & j)
        : abstr_emp(fn, ln, j) {}

    virtual void ShowAll() const { abstr_emp::ShowAll(); }
    virtual void SetAll()        { abstr_emp::SetAll(); }
};


class manager: virtual public abstr_emp {
private:
    int inchargeof;                         // number of abstr_emps managed

protected:
    int InChargeOf() const { return inchargeof; }      // output
    int & InChargeOf()     { return inchargeof; }      // input

public:
    manager(): inchargeof(-1) {}
    manager(const std::string & fn, const std::string & ln,
        const std::string & j, int ico = 0): abstr_emp(fn, ln, j), inchargeof(ico) {}

    manager(const abstr_emp & e, int ico): abstr_emp(e), inchargeof(ico)           {}
    manager(const manager & m): abstr_emp(m), inchargeof(m.inchargeof)             {}

    virtual void ShowAll() const {
        abstr_emp::ShowAll();
        std::cout << "In charge of " << inchargeof << " employees\n";
    }

    virtual void SetAll() {
        abstr_emp::SetAll();
        rd::readvalue(inchargeof, "Enter in charge of: ");
    }

    virtual void WriteAll(std::ofstream &out) {
        abstr_emp::WriteAll(out);
        out << inchargeof << '\n';
    }

    virtual void ReadAll(std::ifstream &in) {
        abstr_emp::ReadAll(in);
        (in >> inchargeof).get();   // get rid of newline by writeall
    }
};


class fink: virtual public abstr_emp {
private:
    std::string reportsto;                  // to whom fink reports

protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo()           { return reportsto; }

public:
    fink(): reportsto("None") {}    // defaults for abstr_emp

    fink(const std::string & fn, const std::string & ln,
        const std::string & j, const std::string & rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}

    fink(const abstr_emp & e, const std::string & rpo): abstr_emp(e), reportsto(rpo) {}
    fink(const fink & e): abstr_emp(e), reportsto(e.reportsto) {}

    virtual void ShowAll() const {
        abstr_emp::ShowAll();
        std::cout << "ReportsTo: " << reportsto << '\n';
    }

    virtual void SetAll() {
        abstr_emp::SetAll();
        rd::readvalue(reportsto, "Enter reports to: ");
    }

    virtual void WriteAll(std::ofstream &out) {
        abstr_emp::WriteAll(out);
        writeString(out, reportsto);
    }

    virtual void ReadAll(std::ifstream &in) {
        abstr_emp::ReadAll(in);
        readString(in, reportsto);
    }
};

// If a class is derived virtually, passing of arguments to virtual base
// ancestor class through intermediate classes is disabled

class highfink: public manager, public fink {   // management fink
public:
    highfink() {}   // all defaults

    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo, int ico)
        : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}

    highfink(const abstr_emp & e, const std::string & rpo, int ico)
        : abstr_emp(e), fink(e, rpo), manager(e, ico) {}

    highfink(const fink & f, int ico): abstr_emp(f), fink(f), manager(f, ico) {}
    highfink(const highfink & h): abstr_emp(h), fink(h), manager(h) {}

    highfink(const manager & m, const std::string & rpo)
        : abstr_emp(m), fink(m, rpo), manager(m) {}

    virtual void ShowAll() const {
        abstr_emp::ShowAll();
        fink::ShowAll();
        manager::ShowAll();
    }

    virtual void SetAll() {
        abstr_emp::SetAll();
        fink::SetAll();
        manager::SetAll();
    }

    virtual void WriteAll(std::ofstream &out) {
        abstr_emp::WriteAll(out);
        fink::WriteAll(out);
        manager::WriteAll(out);
    }

    virtual void ReadAll(std::ifstream &in) {
        abstr_emp::ReadAll(in);
        fink::ReadAll(in);
        manager::ReadAll(in);
    }
};

