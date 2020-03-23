/*
 Inola Cohen
 Assignment 2
 March 20, 2019
 Co Sci 840
 */

#include <iostream>
#include "fraction_class.h"
using namespace std;

void swap(FracList&, FracList&, int&, int&);

int main()
{
    /*** Creating List Objects ***/
    
    int size1, size2;
    
    cout << "Enter size of first fraction list: ";
    cin >> size1;
    
    cout << "\nEnter size of second fraction list: ";
    cin >> size2;
    
    FracList list1(size1), list2(size2);
    
    cout << "\nEnter " << size1 << " fraction(s) for first list: ";
    
    for (int i = 0; i < size1; i++)
    {
        cin >> list1[i];
    }
    
    cout << "\nEnter " << size2 << " fraction(s) for second list: ";
    
    for (int i = 0; i < size2; i++)
    {
        cin >> list2[i];
    }
    
    
    /*** Sort Lists ***/
    
    list1.sort();
    list2.sort();
    
    cout << "\nSorted lists: \n" << endl;
    
    cout << "List 1: ";
    for (int i = 0; i < size1; i++)
    {
        cout << list1[i] << " ";
    }
    
    cout << endl << endl;
    
    cout << "List 2: ";
    for (int i = 0; i < size2; i++)
    {
        cout << list2[i] << " ";
    }
    
    /*** Search Lists ***/
    
    Fraction fracSearch;
    
    cout << "\n\nEnter a fraction to search for: ";                    // to search for fraction in a list
    cin >> fracSearch;
    
    int index1 = list1.binarySearch(fracSearch),
        index2 = list2.binarySearch(fracSearch);
    
        while (index2 == -1 && index1 == -1)
        {
            cout << "\nFraction could not be found. Please re-enter: ";
            cin >> fracSearch;
            
            index1 = list1.binarySearch(fracSearch);
            index2 = list2.binarySearch(fracSearch);
            
            if (index1 != -1 || index2 != -1)             // if fraction is finally found in atleast one of the lists then break out of while loop
                break;
        }
    
    if (index1 != -1)
        cout << "\n" << fracSearch << " was found at index " << index1 << " of list 1." << endl;     // if fraction is found in list 1
    
    if (index2 != -1)
        cout << "\n" << fracSearch << " was found at index " << index2 << " of list 2." << endl;     // if fraction is found in list 2
    
    /*** Swap Lists ***/
    
    if (list2 < list1)                                   // if list 2 size is less than size of list 1, then swap lists
    {
        swap(list1, list2, size1, size2);
        
        cout << "\nSwapped lists: " << endl;
        
        cout << "\nList 1: ";
        for (int i = 0; i < size1; i++)
        {
            cout << list1[i] << " ";
        }
        cout << endl;
        
        cout << "\nList 2: ";
        for (int i = 0; i < size2; i++)
        {
            cout << list2[i] << " ";
        }
    }
    else
    {
        cout << "\nList 1: ";
        for (int i = 0; i < size1; i++)
        {
            cout << list1[i] << " ";
        }
        cout << endl;
        
        cout << "\nList 2: ";
        for (int i = 0; i < size2; i++)
        {
            cout << list2[i] << " ";
        }
    }

    
    /*** Creating SUM object for list 2 ***/
    
    Fraction sum;
    
    for (int i = 0; i < size2; i++)
    {
        sum += list2[i];                        // add up all fraction elements from list 2
    }
    
    sum.setReducedSum(sum);                     // reassign sum to reduced form
    
    list2.resizeKeep(size2, list2);
    
    list2[size2 - 1] = sum;                    //assigns sum to index size-1 of list object by using its [] and = operators
    
    cout << "\n\nResized list 2 with the sum of fractions at the end: \n" << endl;
    
    for (int i = 0; i < size2; i++)
    {
        cout << list2[i] << " ";
    }
    cout << endl << endl;
    
    return 0;
}
