
#include <iostream>
#include <string>
#include "courses.h"
using namespace std;

void add(Course*[], int);
void sort(Course*[], int);
int binarySearch(Course*[], string, int);
void display(Course*[], int);
void Delete(Course*[], int&);


int main()
{
    const int arraySize = 10;
    Course* coursePtr[arraySize] = {NULL};
    
    int choice, courseCounter = 0;
    string courseSearch;
    int position;
    
    do {
        /*** MENU **/
        cout << "\nChoose an option:\n"
             << "1. Add new course\n"
             << "2. Edit an existing course\n"
             << "3. Display a course\n"
             << "4. List all courses\n"
             << "5. Display GPA\n"
             << "6. Delete all courses\n"
             << "7. Quit\n";
        
        cout << "Enter selection: ";
        cin >> choice;                                              // Get choice from user
        
        
        /*** MENU FUNCTIONS ***/
        switch(choice)
        {
            case 1:
                add(coursePtr, courseCounter);                    // To add a new course
                courseCounter++;
                break;
                
            case 2:
                coursePtr[arraySize] -> edit(coursePtr, courseCounter);
                break;
                
            case 3:
                if (courseCounter == 0)
                {
                    cout << "\nNo courses available.";
                }
                
                else
                {
                    sort(coursePtr,courseCounter);
                    cout << "Enter course to find: ";
                    cin.ignore();
                    getline(cin, courseSearch);
                    
                    if (islower(courseSearch[0]))                           // Convert all lower to uppercase
                    {
                        courseSearch[0] = toupper(courseSearch[0]);
                    }
                    
                    for (int i = 0; i < courseSearch.length(); i++)
                    {
                        if (courseSearch[i] == ' ')
                        {
                            courseSearch[i + 1] = toupper(courseSearch[i + 1]);
                        }
                    }
                    
                    position = binarySearch(coursePtr, courseSearch, courseCounter);
                    
                    if (position == -1)
                    {
                        cout << "\nCourse was not found.";
                    }
                    else
                    {
                        for (int i = 0; i < courseCounter; i++)
                        {
                            cout << endl;
                            if (position == i)
                            {
                                display(coursePtr, i);
                            }
                        }
                    }
                }
                
                break;
            
            case 4:
                if (courseCounter == 0)
                {
                    cout << "\nNo course available.";
                }
                else
                {
                    sort(coursePtr, courseCounter);
                    cout << endl;
                    for (int i = 0; i < courseCounter; i++)
                    {
                        display(coursePtr, i);
                        cout << endl;
                    }
                }
                break;
                
            case 5: coursePtr[courseCounter] -> displayGPA(coursePtr, courseCounter);
                break;
                
            case 6:
                Delete(coursePtr, courseCounter);
                cout << "All courses deleted!";
                
            case 7:
                Delete(coursePtr, courseCounter);
        }
        
        cout << endl;
   
    } while (choice != 7);
    
    
    return 0;
}
