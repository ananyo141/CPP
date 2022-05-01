#ifndef RECORD_HPP_
#define RECORD_HPP_

#include <iostream>
#include <iomanip>
#include <vector>

namespace rec {
    class Record {
    private:
        enum: short { NAME_MAX = 20, FIELD_W = 15 };
    public:
        char name[NAME_MAX];
        unsigned long population;
        double g_accl;

        void show() const;
        friend std::ostream& operator<<(std::ostream& out, const Record &r);
        friend std::istream& operator>>(std::istream& in,  Record &r);
    };

    using recdb = std::vector<Record>;

    class FileOperation {
    private:
        std::streampos inpPos_, outPos_;
    protected:
        void savepos(std::fstream&);
        void resetpos(std::fstream&) const;
        virtual void execute(std::fstream&) = 0;
    public:
        virtual ~FileOperation() {}
        virtual std::fstream& operator()(std::fstream&);
    };

    class PrintFile: public FileOperation {
        virtual void execute(std::fstream &file) override final;
    };

    class GetRecords: public FileOperation {
        virtual void execute(std::fstream &file) override final;
    };

    class PutRecords: public FileOperation {
    protected:
        virtual void execute(std::fstream& file) {}
        virtual void execute(std::fstream &, const recdb&);    // base method hidden
    public:
        virtual std::fstream& operator() (std::fstream&, const recdb&);
    };

    class AppendRecords: public PutRecords {
    public:
        virtual std::fstream& operator() (std::fstream&, const recdb &records) override;
    };
}

#endif // for #ifndef RECORD_HPP_

