/* 3. Revise the baseDMA-lacksDMA-hasDMA class hierarchy so that all three classes are
   derived from an ABC.Test the result with a program similar to the one in Listing
   13.10.That is, it should feature an array of pointers to the ABC and allow the user
   to make runtime decisions as to what types of objects are created.Add virtual 
   View() methods to the class definitions to handle displaying the data. */

#include <iostream>
#include <cstring>
#include "BrassBank/brassBank.hpp"

namespace {         // make the class declarations static (internal linkage)
    class DMA {     // with an anonymous namespace
    private:
        char *label_;
        int rating_;
    protected:
        static char *stralloc(const char *tocopy) {
            char *buffer = new char[std::strlen(tocopy) + 1];
            std::strcpy(buffer, tocopy);
            return buffer;
        }
    public:
        DMA(const char *lab="null", int rating=0) {
            label_ = stralloc(lab);
            rating_ = rating;
        }
        DMA(const DMA &ob) {
            label_ = stralloc(ob.label_);
            rating_ = ob.rating_;
        }
        virtual ~DMA() {
            delete[] label_;
        }
        DMA & operator=(const DMA &ob) {
            if (this == &ob) return *this;
            delete[] label_;
            label_ = stralloc(ob.label_);
            rating_ = ob.rating_;
            return *this;
        }
        virtual void view() const = 0;
        friend std::ostream &
        operator<<(std::ostream &os, const DMA &ob) {
            os << "Label: "    << ob.label_
               << "\nRating: " << ob.rating_ 
               << '\n';
            return os;
        }
    };

    class baseDMA: public DMA {
    public:
        baseDMA(const char *lab="null", int rating=0) 
            :DMA(lab, rating) { }
        baseDMA(const DMA &obj) : DMA(obj) { }
        virtual void view() const {
            std::cout << *this;
        }
        friend std::ostream &
        operator<<(std::ostream &os, const baseDMA &bd) {
            os << dynamic_cast<const DMA &> (bd);
            return os;
        }
    };

    class lacksDMA: public DMA {
    private:
        enum {COL_LEN = 40};
        char color_[COL_LEN];
    public:
        lacksDMA(const char *col="null", const char *lab="null", int rating=0)
                :DMA(lab, rating) {
            std::strncpy(color_, col, COL_LEN-1);
            color_[COL_LEN-1] = '\0';
        }
        lacksDMA(const char *col, const DMA &obj)
                :DMA(obj)         {
            std::strncpy(color_, col, COL_LEN-1);
            color_[COL_LEN-1] = '\0';
        }
        virtual void view() const {
            std::cout << *this;
        }
        friend std::ostream &
        operator<<(std::ostream &os, const lacksDMA &ld) {
            os << dynamic_cast<const DMA &> (ld);
            os << "Color: " << ld.color_
            << '\n';
            return os;
        }
    };

    class hasDMA: public DMA {
    private:
        char *style_;
    public:
        hasDMA(const char *styl="null", const char *lab="null",int rating=0)
                :DMA(lab, rating)  { style_ = stralloc(styl); }
        hasDMA(const char *styl, const DMA &obj)
                :DMA(obj)          { style_ = stralloc(styl); }
        virtual ~hasDMA()          { delete[] style_; }
        hasDMA(const hasDMA &hd) : DMA(hd) { style_ = stralloc(hd.style_); }
        hasDMA & operator=(const hasDMA &hd) {
            if (this == &hd) return *this;
            delete[] style_;
            DMA::operator=(hd);
            style_ = stralloc(hd.style_);
            return *this;
        }
        virtual void view() const {
            std::cout << *this;
        }
        friend std::ostream &
        operator<<(std::ostream &os, const hasDMA &hd) {
            os << dynamic_cast<const DMA &> (hd);
            os << "Style: " << hd.style_
            << '\n';
            return os;
        }
    };
}

int main() {
    using Brass::readVal;
    int i;
    const int NUMOBJ = 4;
    DMA *objectPool[NUMOBJ];
    
    int choice, rating;
    std::string label, color, style;
    for (i = 0; i < NUMOBJ; i++) {
        readVal(choice, "Press 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA"
                        "\n(Default 1): ");
        readVal(label,  "Enter label: ");
        readVal(rating, "Enter rating: ");
        switch (choice) {
            default:
            case 1: objectPool[i] = new baseDMA(label.c_str(), rating);
                    break;
            case 2: readVal(color, "Enter color: ");
                    objectPool[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
                    break;
            case 3: readVal(style, "Enter style: ");
                    objectPool[i] = new hasDMA(style.c_str(), label.c_str(), rating);
                    break;
        }
    }

    std::cout << "\nPrinting User Inputs:\n";
    for (i = 0; i < NUMOBJ; i++)
        objectPool[i]->view();

    return 0;
}

