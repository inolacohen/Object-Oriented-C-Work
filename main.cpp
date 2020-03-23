#include <iostream>
//#include <conio.h>
using namespace std;

template <class T> class List //contains a series of integers using dynamic memory with flexible size, known as a container class
{
private:
    T size; //number of elements
    T *ptr; //points to first element
public:
    List(int size = 0, T* ptr = 0); //default size is 0 List(const List& l);
    List(const List& l); //copy constructor - used to create and at once initialize a List object
    T get_size() const;
    const List& operator=(const List& l); //overloaded assignment operator
    T& operator[](int index); //returns a reference to int so it can be assigned to(used as lvalue)
    const T operator[](int index) const; //returns list member at specified index(a rvalue)
    ~List(); //destructor frees allocated dynamic memory
};

class Date {
    friend ostream& operator<<(ostream& out, const Date& date); //a non-member function is used to display because
    friend istream& operator>>(istream& in, Date& date); //a non-member function is used to display because
private:
    int day, month, year;
public:
    Date(int = 1, int = 1, int = 1900);
    void set(int = 1, int = 1, int = 1900);
    void get();
    void print() const;
    bool operator==(const Date &) const;
};

Date::Date(int d, int m, int y)
{
    set(d, m, y);
}

void Date::set(int d, int m, int y)
{
    if (d >= 1 && d <= 31)
        day = d;
    else
    {
        std::cout << "\ninvalid day: " << d;
        std::cout << "\nProgram ending. . .";
        system("pause");
        exit(1);
    }
    if (m >= 1 && m <= 12)
        month = m;
    else
    {
        std::cout << "\ninvalid month: " << m;
        std::cout << "\nProgram ending. . .";
        system("pause");
        exit(1);
    }
    if (y >= 1900 && y <= 3000)
        year = y;
    else
    {
        std::cout << "\ninvalid year: " << y;
        std::cout << "\nProgram ending. . .";
        system("pause");
        exit(1);
    }
}

void Date::get()
{
    char ch;
    std::cout << "Enter date in month/day/year format: ";
    cin >> month >> ch >> day >> ch >> year;
}

ostream& operator<<(ostream& out, const Date& date) //a non-member function is used to display because
{
    out << date.month << '/' << date.day << '/' << date.year;
    return out;
}
istream& operator>>(istream& in, Date& date) //a non-member function is used to display because
{
    in >> date.month >> date.day >> date.year;
    return in;
}

bool Date::operator==(const Date &d) const
{
    return day == d.day && month == d.month && year == d.year;
}
template<class T>List<T>::List(int s, T* ptr) : size(s), ptr(new T[s])
{
} //initialization being done by the member initializer; alternatively we could write them in the body like in set_size

template<class T>List<T>::List(const List& l) : size(l.size) //copy constructor used to initialize a List object using an existing List object
{ //this creates the new object with l.size elements
    ptr = new int[size];
    for (int i = 0; i < size; i++) //now copy elements
        ptr[i] = l.ptr[i];
}

template<class T> T List<T>::get_size() const
{
    return size;
}

template<class T> T& List<T>::operator[](int index) //returns a reference to object so it can be assigned to
{
    return ptr[index];
}

template<class T> const T List<T>::operator[](int index) const //returns list member at specified index
{
    return ptr[index];
}

template<class T> List<T>::~List()
{
    delete[] ptr;
}

int main()
{
    List<int>numbers(10);
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i + 1;
        cout << numbers[i] << ' ';
    }
    
    List<Date>dates(3);
    dates[0].set(1, 12, 2016);
    dates[1].set(2, 12, 2016);
    dates[2].set(3, 12, 2016);
    
    for (int i = 0; i < 3; i++)
        cout << endl << dates[i];
    
    cout << "\nPress any key to continue.";
    //_getch();
}
