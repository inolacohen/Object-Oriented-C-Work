#ifndef session_h
#define session_h
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
    char description[100];
    char clientName[100];
    double hourlyCharge, hours;
public:
    Appointment() {}
    Appointment(char[100], Date, char[100]);
    friend bool operator<(Appointment, Appointment);
    friend bool operator==(Appointment, Appointment);
    virtual void read();
    virtual void print();
    char getName();
    double getHour();
    double getCharge();
};

class clientSession : public Appointment
{
public:
    clientSession() {};
    void set(double, double, char[100], Date);
    void read();
    void print();
    ~clientSession() {};
};

class courtSession : public Appointment
{
private:
    char courtName[100], courtLocation[100];
public:
    courtSession() {};
    char getCourtName();
    char getCourtLocation();
    void set(char[], char[]);
    void read();
    void print();
    ~courtSession() {};
};
#endif /* session_h */
