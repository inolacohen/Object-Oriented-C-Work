
#include <iostream>
#include "fraction_class.h"
using namespace std;

/******** Non-Member Function Definitions ********/

ostream& operator<< (ostream& out, const Fraction& frac)
{
    out << frac.num << '/' << frac.den;      // non-member friend function to display invoking objects data
    return out;
}
istream& operator>> (istream& in, Fraction& frac)
{
    char slash;
    in >> frac.num >> slash >> frac.den;
    frac.reduce();
    return in;
}

void swap(FracList& l1, FracList& l2, int& s1, int& s2)
{
    int sizeTemp = s1;        // create a temp size to switch sizes of lists
    s1 = s2;                  // copy second list size (which is smaller) to first list size
    s2 = sizeTemp;           // make second list the larger size (make s1 to s2)
    
    FracList temp = l1;      //uses copy constructor to create temp and copy first list into it
    l1 = l2;            //uses assignment operator to copy from second list into first list
    l2 = temp;
}


/********** Fraction Class: Member Functions Definitions **********/

Fraction::Fraction(int n, int d)               // default constructor
{
    set(n, d);
}

void Fraction::set(int n, int d)
{
    /*while (den == 0)
    {
        cout << "Denominator cannot be 0. Please enter fraction again: ";
        //cin >> n >> slash >> d;
    }*/
    num = n;
    den = d;
    reduce();
}

void Fraction::reduce()         // to reduce fraction to simplest form
{
    if (num == den)
    {
        num = den = 1;
    }
    else                             // check whether need brackets to enclose else statement and for loop
        for (int i = num; i > 1; i--)
            if (num % i == 0 && den % i == 0)
            {
                num /= i;
                den /= i;
            }
}

void Fraction::setReducedSum(Fraction& sum)
{
    sum.reduce();
}

Fraction::Fraction(const Fraction& frac)          // copy constructor used to instantiate an object by copying an existing one
{
    set(frac.num, frac.den);
}

Fraction& Fraction::operator= (const Fraction& frac)     // assignment operator overloaded
{
    if (frac != *this)         // not to copy fraction into itself
    {
        set(frac.num, frac.den);
    }
    return *this;              // dereferencing invoked fraction pointer and returning new assignment
}

Fraction Fraction::operator+ (const Fraction& frac) const
{
    Fraction temp(num * frac.den + den * frac.num, den * frac.den);
    temp.reduce();
    return temp;
}

Fraction& Fraction::operator+= (const Fraction& frac)    // this changes the invoking fraction by storing it back into it
{
    set(num * frac.den + den * frac.num, den * frac.den);
    return *this;
}

Fraction Fraction::operator- (const Fraction& frac) const   // this doesnt change the invoking fraction
{
    Fraction temp(num* frac.den - den * frac.num, den * frac.den);
    temp.reduce();
    return temp;
}

Fraction& Fraction::operator-= (const Fraction& frac)    // this changes the invoking fraction by storing back into original
{
    set(num* frac.den - den * frac.num, den * frac.den);
    return *this;
}

Fraction Fraction::operator* (const Fraction& frac) const //this does not change the invoking fraction
{
    Fraction temp(num * frac.num, den * frac.den);
    temp.reduce();
    return temp;
}

Fraction& Fraction::operator*= (const Fraction& frac) //this changes the invoking fraction by storing back into original
{
    set(num * frac.num, den * frac.den);
    return *this;
}

Fraction Fraction::operator/(const Fraction& frac) const //this does not change the invoking fraction
{
    Fraction temp(num * frac.den, den * frac.num);
    temp.reduce();
    return temp;
}

Fraction& Fraction::operator/= (const Fraction& frac)       //this changes the invoking fraction by storing back into original
{
    set(num * frac.den, den * frac.num);
    return *this;
}

bool Fraction::operator>(const Fraction& frac) const
{
    return num * frac.den > den * frac.num;
}

bool Fraction::operator<(const Fraction& frac) const
{
    return num * frac.den < den * frac.num;
}

bool Fraction::operator>=(const Fraction& frac) const
{
    return num * frac.den >= den * frac.num;
}

bool Fraction::operator<=(const Fraction& frac) const
{
    return num * frac.den <= den * frac.num;
}

bool Fraction::operator==(const Fraction& frac) const
{
    return num * frac.den == den * frac.num;
}

bool Fraction::operator!=(const Fraction& frac) const
{
    return num * frac.den != den * frac.num;
}

Fraction::~Fraction() {}


/******** FracList Class: Member Functions Definitions ********/

FracList::FracList(int s) : listSize(s) //constructor
{
    if (listSize > 0)
        fracPtr = new Fraction[listSize];
    else
        fracPtr = NULL;
}

FracList::FracList(const FracList& list) //copy constructor
{
    listSize = list.listSize;
    fracPtr = new Fraction[listSize];
    for (int i = 0; i < listSize; i++)
        fracPtr[i] = list[i];
}

int FracList::getsize() const
{
    return listSize;
}

FracList& FracList::operator=(const FracList& list) //assignment operator overloaded
{
    if (*this != list)
    {
        delete [] fracPtr;
        listSize = list.listSize;
        fracPtr = new Fraction[listSize];
        for (int i = 0; i < listSize; i++)
            fracPtr[i] = list[i];
    }
    return *this;
}

Fraction& FracList::operator[](int index)
{
    //if(index >= 0 && index < listSize)
        return fracPtr[index];
}

Fraction FracList::operator[](int index) const
{
    //if (index >= 0 && index < listSize)
        return fracPtr[index];
}

FracList& FracList::operator+=(const FracList& list)
{
    int newSize = listSize + list.listSize;
    Fraction* temp = new Fraction[newSize];
    for (int i = 0; i < listSize; i++)
        temp[i] = fracPtr[i];
    for (int i = listSize, j = 0; i < newSize; i++, j++)
        temp[i] = list[j];
    delete[] fracPtr;
    fracPtr = temp;
    listSize = newSize;
    return *this;
}

bool FracList::operator> (const FracList& list) const
{
    return listSize > list.listSize;
}

bool FracList::operator< (const FracList& list) const
{
    return listSize < list.listSize;
}

bool FracList::operator== (const FracList& list) const
{
    if (listSize != list.listSize)
        return false;
    for (int i = 0; i < listSize; i++)
        if (fracPtr[i] != list.fracPtr[i])
            return false;
    return true;
}

bool FracList::operator!= (const FracList& list) const
{
    return(!(*this == list));
}

FracList& FracList::operator++() //increment to add a Fraction object to list
{
    FracList temp(1);
    *this += temp;
    return *this;
}

void FracList::sort() //sort the array of Fractions
{
    bool swap;
    do
    {
        swap = false;
        for (int i = 0; i < listSize - 1; i++)
        {
            if (fracPtr[i] > fracPtr[i + 1])
            {
                Fraction temp = fracPtr[i];        //uses overloaded = (assignment) operator
                fracPtr[i] = fracPtr[i + 1];
                fracPtr[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

int FracList::binarySearch(const Fraction& frac) const
{
    bool found = false;
    int index = -1;
    int first = 0, last = listSize - 1, mid;
    while (!found && first <= last)
    {
        mid = (first + last) / 2;
        if (frac == fracPtr[mid])
        {
            index = mid;
            found = true;
        }
        else if (frac < fracPtr[mid])
            last = mid - 1;
        else
            first = mid + 1;
    }
    return index;
}

void FracList::resizeKeep(int& size, FracList& list)             // keeping old values
{
    ++list;                           // uses overloaded ++ to increase list size
    
    size = list.getsize();            // new size of list w/ sum fraction object
}

FracList::~FracList()
{
    delete[] fracPtr;
    fracPtr = NULL;
}











