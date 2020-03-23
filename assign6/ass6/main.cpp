/*
 Inola Cohen
 June 2, 2019
 Assignment 6
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Student.h"
using namespace std;

void sort(Student*[], int);
int binSearch(Student*[], string, int);
double averageGPA(int, Student*[]);

int main() {
    
    const int arraySize = 20;
    int arrayCounter = 0;
    char answer1, answer2;
    string search;
    Student* studentPtr[arraySize];
    //vector<Student*>pointer;
    
    
    do {
        cout << "Add new student? [Y/N]: ";                       // This is all to ADD a new student (YES option)
        cin >> answer1;
        
        if (toupper(answer1) == 'Y')
        {
            cout << "Is this a student worker? [Y/N]: ";
            cin >> answer2;
            
            if (toupper(answer2) == 'Y')                                // If student IS a student worker
                
                studentPtr[arrayCounter] = new StuWorker;
            
            
            //pointer.push_back(new Student());
            
            else                                                       // If student is NOT a student worker
                studentPtr[arrayCounter] = new Student;
            
            //pointer.push_back(new StuWorker());
            
            studentPtr[arrayCounter]->read();
            arrayCounter++;                              // To move on to next index in the array for next student
        }
        
    } while (toupper(answer1) == 'Y');
    
    /* Print students */
    
    if (toupper(answer1) == 'N')
    {
        for (int i = 0; i < arrayCounter; i++)
        {
            studentPtr[i]->print();
            cout << endl;
        }
    }
    
    
    /* Sort Students Alphabetically */
    
    sort(studentPtr, arrayCounter);
    
    cout << "Sorted Students List: " << endl;
    
    for (int i = 0; i < arrayCounter; i++)
    {
        studentPtr[i]->print();
        cout << endl;
    }
    
    
    /* Average GPA */
    
    cout << "Average GPA: " << averageGPA(arrayCounter, studentPtr);
    
    
    /* Search for Student */
    
    cout << "\nEnter name of student to search for: ";
    cin.ignore();
    getline(cin, search);
    int index = binSearch(studentPtr, search, arraySize);
    
    if (index == -1)
        cout << "\nStudent not found! ";
    else
        cout << "\nStudent found at index " << index;
    
    return 0;
}




