#ifndef SALES_H_
#define SALES_H_

namespace SALES {
    typedef double salesItem;

    class Sales {
    private:
        enum :short {QUARTERS = 4};
        salesItem sales_[QUARTERS];
        salesItem max_;
        salesItem min_;
        salesItem average_;
    public:
        Sales();
        Sales(const salesItem ar[], int n);
        void showSales() const;
    };
}

#endif
        
