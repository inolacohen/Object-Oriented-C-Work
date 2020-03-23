/*
Co Sci 840
Assignment #3
April 7, 2019
 */

#include <iostream>
#include "session.h"
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<Session*>array;
    int choice;
    string clientName;
    double charges = 0, totalHours = 0;
    
    do
    {
        cout << "Select one of the following actions: "
        << "\n1. Add new session"
        << "\n2. Display all sessions"
        << "\n3. Search for a client"
        << "\n4. Display total charges for all clients and the average hours spent"
        << "\n5. Quit"
        << endl;
        cout << "\nEnter your selection: ";
        cin >> choice;
        cout << endl;
        
        switch (choice)
        {
            case 1:
                array.push_back(new Session());
                break;
            case 2:
                cout << "\nList of scheduled sessions:\n";
                for (int i = 0; i < array.size(); i++)
                {
                    array[i]->print();
                    cout << endl;
                }
                break;
            case 3:
                cout << "\nEnter client's name: ";
                cin.ignore();
                getline(cin, clientName);
                cout << endl;
                for (int i = 0; i<array.size(); i++)
                {
                    if (array[i]->getName() == clientName)
                    {
                        array[i]->print();
                    }
                }
                break;
                
            case 4:
                for (int i = 0; i<array.size(); i++)
                {
                    charges += array[i]->getCharge();
                    totalHours += array[i]->getHour();
                }
                cout << "\nTotal charges: $" <<fixed<<setprecision(2)<< charges << endl;
                cout << "Average hours: " << fixed <<setprecision(1)<< totalHours / array.size() << endl << endl;
                break;
            case 5: return 0;
                
            default: cout << "\nInvalid. Enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
}
