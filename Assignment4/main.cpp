/*
 Inola Cohen
 Co Sci 840
 Assignment #3
 April 7, 2019
 */

#include <iostream>
#include "session.h"
#include <string>
#include <vector>
#include <iomanip>
#include <string.h>
using namespace std;



int main()
{
    Appointment* appointmentPtr[] = {NULL};
    int choice, appointmentCounter = 0;
    char clientName[100], session;
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
                cout << "Is this a court session? (Y/N) ";
                cin >> session;
                if (session == 'Y' || session == 'y')
                    appointmentPtr[appointmentCounter] = new courtSession;

                else if (session == 'N' || session == 'n')
                    appointmentPtr[appointmentCounter] = new clientSession;
                
                appointmentPtr[appointmentCounter] -> read();
                
                appointmentCounter++;
                break;
            case 2:
                cout << "\nList of scheduled sessions:\n";
                for (int i = 0; i < appointmentCounter; i++)
                {
                    appointmentPtr[i] -> print();
                    cout << endl;
                }
                break;
            case 3:
                cout << "\nEnter client's name: ";
                cin >> clientName;
                cout << endl;
                for (int i = 0; i < appointmentCounter; i++)
                {
                    
                    if (appointmentPtr[i] -> getName() == clientName[99])
                    {
                        appointmentPtr[i] -> print();
                    }
                }
                break;
                
            case 4:
                for (int i = 0; i < appointmentCounter; i++)
                {
                    charges += appointmentPtr[i] -> getCharge();
                    totalHours += appointmentPtr[i]->getHour();
                }
                cout << "\nTotal charges: $" <<fixed<<setprecision(2)<< charges << endl;
                cout << "Average hours: " << fixed <<setprecision(1)<< totalHours / appointmentCounter << endl << endl;
                break;
            case 5: return 0;
        }
    } while (choice != 5);
}
