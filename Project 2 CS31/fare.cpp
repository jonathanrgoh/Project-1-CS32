//
//  fare.cpp
//  fare
//
//  Created by Jonathan Goh on 10/14/17.
//  Copyright © 2017 Jonathan Goh. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int age, zones;
    double fare;
    string student,student1;
    string destination;
    
    cout << "Age of rider: ";       //asks for age
    cin >> age;
        if (age<0)      //makes sure input is correct
        {
            cout << "---";
            cout << "\nThe age must not be negative\n";
            return 1;
        }
    
    cout << "Student? (y/n): ";     //asks whether student
    cin >> student;
        if (student=="y" || student=="n")      //makes sure input is correct
            student1="y";
        else
        {
            cout << "---";
            cout << "\nYou must enter y or n\n";
            return 2;
        }
    
    cout << "Destination: ";        //asks for destination
    cin >> destination;
        if (destination== "")      //makes sure input is correct
        {
            cout << "---";
            cout << "\nYou must enter a destination\n";
            return 3;
        }
    
    cout << "Number of zone boundaries crossed: ";      //asks for number of boundaries
    cin >> zones;
        if (age<0)      //makes sure input is correct
        {
            cout << "---";
            cout << "\nThe number of zone boundaries crossed must not be negative\n";
            return 4;
        }
    
    
        if(age<18 && zones<=1)      //checks if under 18 and taking a short trip
        {
            fare=0.65;
        }
        else if(age>=65 && zones==0)        //checks if senior citizen with 0 zones
        {
            fare=0.45;
        }
        else if(age>=65 && zones>=1)        //checks if senior citizen with 1 or more zones
        {
            fare=0.55;
            fare+=(.25*zones);
        }
        else if(student=="y" && age>=18 && zones<=1)    //checks if student older than 18 with short trip
        {
            fare=0.65;
        }
        else        //people that don't qualify for any discounts
        {
            fare=1.35;
            fare+=(.55*zones);
        }
    
    
    cout.setf(ios::fixed);  //does not change the number, only changes how the number is displayed
    cout.precision(2);  //2 digits to the right of the decimal point

    cout << "---\nThe fare to " << destination << " is $" << fare << "\n\n";    //outputs the final fare
    
    return 0;
}
