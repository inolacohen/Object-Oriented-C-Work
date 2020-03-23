#include <iostream>
#include <iomanip>
#include "session.h"
#include <string>

using namespace std;

/***** Date Class *****/

ostream& operator<<(ostream& out, const Date &date)
{
    out << date.day << '/' << date.month << '/' << date.year;
    return out;
}
istream& operator>>(istream& in, Date &date)
{
    string ch;
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
    while (i < ch.size())
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

Appointment::Appointment(string des, Date d)
{
    description = des;
    date = d;
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
    getline(cin, description);
    cout << "Enter appointment date: ";
    cin >> date;
}

void Appointment::print()
{
    cout << description << endl;
     cout << "Date: " << date << endl;
}

/***** Session Class *****/

void Session::set(string name, double rate, double hour, string des, Date d)
{
    clientName = name;
    hourlyCharge = rate;
    hours = hour;
    description = des;
    date = d;
}
string Session::getName()
{
    return clientName;
}
double Session::getHour()
{
    return hours;
}
void Session::print()
{
    Appointment::print();
    cout << "Client name: " << clientName << endl;
    cout << "Hourly charge: $" << fixed << setprecision(2) << hourlyCharge << endl;
    cout << "Hours: " << hours << endl;
    cout << "Charge: $" << getCharge() << endl;
    
}
void Session::read()
{
    Appointment::read();
    cout << "Enter client name: ";
    cin.ignore();
    getline(cin, clientName);
    cout << "Enter hourly charge: $";
    cin >> hourlyCharge;
    cout << "Enter hours: ";
    cin >> hours;
    cout << endl;
}
double Session::getCharge()
{
    return hours * hourlyCharge;
}


