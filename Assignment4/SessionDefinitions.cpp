#include <iostream>
#include <iomanip>
#include "session.h"
#include <string>
#include <string.h>

using namespace std;

/***** Date Class *****/

ostream& operator<<(ostream& out, const Date &date)
{
    out << date.day << '/' << date.month << '/' << date.year;
    return out;
}
istream& operator>>(istream& in, Date &date)
{
    char ch[15];
    in >> ch;
    date.day = 0;
    int i = 0;
    while (ch[i] != '/')
    {
        date.day = date.day * 10 + (ch[i] - '0');
        i++;
    }
    i++;
    date.month = 0;
    while (ch[i] != '/')
    {
        date.month = date.month * 10 + (ch[i] - '0');
        i++;
    }
    i++;
    date.year = 0;
    while (i < strlen(ch))
    {
        date.year = date.year * 10 + (ch[i] - '0');
        i++;
    }
    return in;
}

bool Date::operator<(Date &date)
{
    if (day < date.day && month < date.month && year < date.year)
        return true;
    else if (day == date.day && month < date.month && year < date.year)
        return true;
    else if (day == date.day && month == date.month && year < date.year)
        return true;
    else
        return false;
}

bool Date::operator==(Date&date)
{
    return day == date.day && month == date.month && year == date.year;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

/***** Appointment Class *****/

Appointment::Appointment(char des[100], Date d, char name[100])
{
    strcpy(des, description);
    date = d;
    strcpy(name, clientName);
}

bool operator<(Appointment a1, Appointment a2)
{
    return a1.date < a2.date;
}
bool operator==(Appointment a1, Appointment a2)
{
    return a1.date == a2.date;
}

void Appointment::read()
{
    cout << "Enter description: ";
    cin.ignore();
    cin.get(description, 100);
    cout << "Enter client name: ";
    cin.ignore();
    cin.get(clientName, 100);
    cout << "Enter appointment date: ";
    cin >> date;
    cout << "Enter hourly charge: $";
    cin >> hourlyCharge;
    cout << "Enter hours: ";
    cin >> hours;
    
    
}

void Appointment::print()
{
    cout << "Client name: " << clientName << endl;
    cout << description << endl;
    cout << "Appointment Date: " << date << endl;
    cout << "Hourly Charge: $" << hourlyCharge << endl;
    cout << "Hours: " << hours << endl;
}

/***** Client Session Class *****/

void clientSession::set(double rate, double hour, char des[100], Date d)
{
    hourlyCharge = rate;
    hours = hour;
    strcpy(des, description);
    date = d;
}
char Appointment::getName()
{
    return clientName[99];
}

double Appointment::getHour()
{
    return hours;
}

void clientSession::read()
{
    Appointment::read();
}

void clientSession::print()
{
    cout << "Session Type: Client" << endl;
    Appointment::print();
    
}

double Appointment::getCharge()
{
    return hours * hourlyCharge;
}


/***** Court Session Class *****/

void courtSession::set(char name[100], char location[100])
{
    strcpy(name, courtName);
    strcpy(location, courtLocation);
}

char courtSession::getCourtName()
{
    return courtName[99];
}

char courtSession::getCourtLocation()
{
    return courtLocation[99];
}

void courtSession::read()
{
    cout << "Enter Court Name: " ;
    cin.ignore();
    cin.get(courtName, 100);
    
    cout << "Enter Court Location: " ;
    cin.ignore();
    cin.get(courtLocation, 100);
    
    Appointment::read();
}

void courtSession::print()
{
    cout << "Session Type: Court" << endl;
    cout << "Court Name: " << courtName << endl;
    cout << "Court Location: " << courtLocation << endl;
    Appointment::print();
}





