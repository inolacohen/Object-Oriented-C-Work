#include <iostream>
#include <string>
using namespace std;

class Date
{
    
private:
    int day, month, year;
public:
    Date() {}
    Date(int day,int month,int year);
     bool operator<(Date&);
     bool operator==(Date&);
    friend ostream& operator<<(ostream& out, const Date &date);
    friend istream& operator>>(istream& in, Date &date);
    ~Date() {};
};

class Appointment
{
protected:
    Date date;
    string description;
public:
    Appointment() {}
    Appointment(string, Date);
    friend bool operator<(Appointment, Appointment);
    friend bool operator==(Appointment, Appointment);
    void read();
    void print();
};

class Session : public Appointment
{
private:
    string clientName;
    double hourlyCharge, hours;
public:
    Session() { read(); }
    void set(string, double, double, string, Date);
    void read();
    void print();
    string getName();
    double getHour();
    double getCharge();
    ~Session() {};
};
