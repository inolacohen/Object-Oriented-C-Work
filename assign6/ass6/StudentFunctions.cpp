#include <iostream>
#include "Student.h"
#include <iomanip>
#include <string>
using namespace std;

/***** Student Functions *****/

/*Student& Student::operator=( Student &s)
 {
 if (s != *this)         // not to copy into itself
     set(s.name, s.ID, s.units, s.gpa);
 return *this;
 }*/

void Student::set(string n, string I, int u, double g)
{
    name = n;
    ID = I;
    units = u;
    gpa = g;
}

void Student::read()
{
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    
    
    cout << "\nEnter student ID: ";
    cin >> ID;
    
    cout << "\nEnter units completed: ";
    cin >> units;
    
    cout << "\nEnter student's GPA: ";
    cin >> gpa;
    
}

void Student::print()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Units completed: " << units << endl;
    cout << "GPA: " << gpa << endl;
}

string Student::getName()
{
    return name;
}

double Student::getGPA()
{
    return gpa;
}

double averageGPA(int counter, Student* students[])
{
    double GPA = 0;
    for (int i = 0; i < counter; i++)
    {
        GPA += students[i] -> getGPA();
        GPA /= counter;
    }
    return GPA;
}


/***** Student Worker Functions *****/

/*StuWorker& StuWorker::operator=(StuWorker &sw)
 {
 //if (sw != *this)         // not to copy into itself
 {
 set(sw.hours, sw.hourlyRate);
 }
 return *this;
 }*/


void StuWorker::read()
{
    Student::read();
    
    cout << "\nEnter hours assigned per week: ";
    cin >> hours;
    
    cout << "\nEnter hourly rate: ";
    cin >> hourlyRate;
}

void StuWorker::set(int h, double hr)
{
    hours = h;
    hourlyRate = hr;
}

void StuWorker::print()
{
    Student::print();
    cout << "Hours working per work: " << hours << endl;
    cout << "Hourly rate: " << hourlyRate << endl;
}


/***** Generic Functions *****/

void sort(Student* students[], int size)                  //sort the array of Students
{
    bool swap;
    do
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (students[i]->getName() > students[i + 1]->getName())
            {
                Student temp = *students[i];
                students[i] = students[i + 1];
                students[i + 1] = &temp;
                swap = true;
            }
        }
    } while (swap);
}

int binSearch(Student* students[], string name, int size)                //searches for name in list
{
    int first = 0, last = size - 1, mid, index = -1;
    bool found = false;
    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (name == students[mid]->getName())
        {
            found = true;
            index = mid;
        }
        else if (name < students[mid]->getName())
            last -= mid;
        else first += mid;
    }
    return index;
}


