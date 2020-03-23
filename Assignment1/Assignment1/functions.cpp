#include <iostream>
#include <string>
#include <iomanip>
#include "courses.h"
using namespace std;

/*******************************************
*     Member Functions of Course Class     *
*******************************************/

void Course::setTitle(string t)
{
    if (islower(t[0]))
    {
        t[0] = toupper(t[0]);
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == ' ')
        {
            t[i + 1] = toupper(t[i + 1]);
            
        }
    }
    
    title = t;
}

void Course::setUnits(int u)
{
    units = u;
}

void Course::setGrade(char g)
{
    if (islower(g))
    {
        g = toupper(g);
    }
    grade = g;
}

string Course::getTitle()
{
    return title;
}

int Course::getUnits()
{
    return units;
}

char Course::getGrade()
{
    return grade;
}

void Course::edit(Course* arrayPtr[], int counter)
{   
    int choice;
    
    if (counter == 0)
    {
        cout << "There are no courses available. Try again.";
    }
    
    else
    {
        cout << "Select the course to edit: \n";
        for (int i = 0; i < counter; i++)
        {
            cout << i + 1 << ". " << arrayPtr[i] -> getTitle() << endl;
        }
       
        cout << "Enter selection: ";
        cin >> choice;
        
        for (int i = 0; i < counter; i++)
            if (choice == (i + 1))
            {
                string t = arrayPtr[i] -> getTitle();
                int u = arrayPtr[i] -> getUnits();
                char g = arrayPtr[i] -> getGrade();
                
                cout << "Editing " << t << u << " units, grade: " << g << endl;
                
                cout << "Enter modified course name: ";
                cin.ignore();
                getline(cin, t);
                arrayPtr[i] -> setTitle(t);
    
                cout << "Enter number of units: ";
                cin >> u;
                arrayPtr[i] -> setUnits(u);
                
                cout << "Enter grade recieved: ";
                cin >> g;
                 arrayPtr[i] -> setGrade(g);
                
                cout << "Course modified.";
            }
    }
}

void Course::displayGPA(Course* arrayPtr[], int counter)
{
    int points;
    int pointArray[counter];
    
    double totalPoints = 0, GPA;
    int totalUnits = 0;
    
    if (counter == 0)
    {
        GPA = 0;
        cout << "\nGPA = " << GPA;
    }
    
    else
    {
        for (int i = 0; i < counter; i++)
        {
            if (arrayPtr[i] -> getGrade() == 'A')
            {
                points = 4;
                pointArray[i] = points * (arrayPtr[i] -> getUnits());
            }
            else if (arrayPtr[i] -> getGrade() == 'B')
            {
                points = 3;
                pointArray[i] = points * (arrayPtr[i] -> getUnits());
            }
            else if (arrayPtr[i] -> getGrade() == 'C')
            {
                points = 2;
                pointArray[i] = points * (arrayPtr[i] -> getUnits());
            }
            else if (arrayPtr[i] -> getGrade() == 'D')
            {
                points = 1;
                pointArray[i] = points * (arrayPtr[i] -> getUnits());
            }
            else if (arrayPtr[i] -> getGrade() == 'F')
            {
                points = 0;
                pointArray[i] = points;
            }
            else
                cout << "Invalid grade. Try again.";
        }
        
        for (int i = 0; i < counter; i++)
        {
            totalPoints += pointArray[i];
            totalUnits += arrayPtr[i] -> getUnits();
        }
        
        GPA = totalPoints / totalUnits;
        
        cout << "\nCurrent GPA = " << fixed << setprecision(2) << GPA;
    }
    
   
    
}

Course::~Course() {}

/*******************************************
 *            General Functions            *
 *******************************************/

void add(Course* arrayPtr[], int counter)
{
    string t;
    int u;
    char g;
    
    arrayPtr[counter] = new Course;
    
    
    cout << "\nEnter course name: ";
    cin.ignore(1000, '\n');
    getline(cin, t);
    arrayPtr[counter] -> setTitle(t);
    
    cout << "\nEnter number of units: ";
    cin >> u;
    
    while (u != 3 && u != 4 && u != 5)
    {
        cout << "Invalid number of units. Please re-enter: ";
        cin >> u;
    }
    
    arrayPtr[counter] -> setUnits(u);
  
    cout << "\nEnter grade recieved: ";
    cin >> g;
    
    if (islower(g))
    {
        g = toupper(g);
    }
    
    while (g != 'A' && g != 'B' && g != 'C' && g != 'D' && g != 'F')
    {
        cout << "Invalid grade. Please re-enter: ";
        cin >> g;
        
        if (islower(g))
        {
            g = toupper(g);
        }
    }
    
    arrayPtr[counter] -> setGrade(g);
}

void sort(Course* arrayPtr[], int counter)
{
    int startScan, minIndex;
    Course* minAddress;
    
    for (startScan = 0; startScan < counter; startScan++)
    {
        minIndex = startScan;
        minAddress = arrayPtr[minIndex];
        
        for (int index = startScan + 1; index < counter; index++)
        {
            if (arrayPtr[index] -> getTitle() < arrayPtr[minIndex] -> getTitle())
            {
               minAddress = arrayPtr[index];
               minIndex = index;
            }
        }
        arrayPtr[minIndex] = arrayPtr[startScan];
        arrayPtr[startScan] = minAddress;
      
    }
}


int binarySearch(Course* arrayPtr[], string name, int counter)
{
    int first = 0,                                // First array element
    last = counter,                               // Last array element
    middle,                                       // Midpoint
    position = -1;                                // Position of search value
    bool found = false;                           // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;                     // Calculate midpoint
        if (arrayPtr[middle] -> getTitle() == name)   // If users course input is found at the midpoint of array
        {
            found = true;
            position = middle;
        }
        else if (arrayPtr[middle] -> getTitle() > name)     // Searching lower half of array
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;                  // Searching upper half of array
        }
    }
    return position;                              // Once position is found
}


void display(Course* arrayPtr[], int counter)
{
    cout << arrayPtr[counter] -> getTitle() << ", "
         << arrayPtr[counter] -> getUnits() << " units, grade: "
         << arrayPtr[counter] -> getGrade();
    
}

void Delete(Course* arrayPtr[], int &counter)
{
    for (int i = 0; i < counter; i++)
         {
             delete arrayPtr[i];
             arrayPtr[i] = {NULL};
         }
    counter = 0;
}
