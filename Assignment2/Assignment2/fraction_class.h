
#ifndef fraction_class_h
#define fraction_class_h
using std::ostream;
using std::istream;

/******** Fraction Class ********/

class Fraction {
    friend ostream& operator<<(ostream& out, const Fraction&frac);               // overloading output
    friend istream& operator>>(istream& in, Fraction&frac);                     // overloading input
private:
    int num, den;
    void reduce();                              // gets called to reduce the fraction to simplest form, must return result of arithmetic operation
    
public:
    Fraction(int num = 0, int den = 1);                       // default: intialize Fraction to 0/1

    Fraction(const Fraction &frac);          // copy constructor - to initialize a Fraction object
    void set(int n, int d);
    void setReducedSum(Fraction&);          // in order to modify sum with private function reduce() from main
    void getReducedSum();
    Fraction& operator= (const Fraction& frac);                        // assignment operator
    Fraction operator+ (const Fraction& frac) const;                   // addition operator
    Fraction& operator+= (const Fraction& frac);                       // += operator
    Fraction operator- (const Fraction& frac) const;                   // subtraction operator
    Fraction& operator-= (const Fraction& frac);                       // -= operator
    Fraction operator* (const Fraction& frac) const;                   // multiplication operator
    Fraction& operator*= (const Fraction& frac);                       // *= operator
    Fraction operator/ (const Fraction& frac) const;                  // division operator
    Fraction& operator/= (const Fraction& frac);                      // /= operator
    bool operator< (const Fraction& frac) const;                      // less than comparison operator
    bool operator<= (const Fraction& frac) const;                     // less than or equal to comparison operator
    bool operator> (const Fraction& frac) const;                     // greater than comparison operator
    bool operator>= (const Fraction& frac) const;                   // greater than or equal to comparison operator
    bool operator== (const Fraction& frac) const;                    // comparison operator
    bool operator!= (const Fraction& frac) const;                   // not equal to operator
    
    ~Fraction();                                                    // destructor frees allocated memory
    
};


/******** List of Fractions Class ********/

class FracList {
private:
    Fraction *fracPtr;                          // points to first fraction element
    int listSize;                               // number of elements
    
public:
    FracList(int listSize = 0);                               // default size is 0
    FracList(const FracList& list);                           // copy constructor - to initalize a FracList object
    int getsize() const;
    FracList& operator= (const FracList& list);               // assignment operator
    Fraction& operator[] (int index);
    Fraction operator[] (int index) const;
    FracList& operator += (const FracList& list);             // this changes the invoking fraction
    bool operator> (const FracList& list) const;
    bool operator< (const FracList& list) const;
    bool operator== (const FracList& list) const;
    bool operator!= (const FracList& list) const;
    FracList& operator++(); //increment operator to add a Fraction object to list
    void resizeKeep(int&, FracList&);             // keeping old values
    void resizeNotKeep(int&);          // not keeping old values
    void sort();
    int binarySearch(const Fraction&) const;
    ~FracList();
    
};

#endif /* fraction_class_h */
