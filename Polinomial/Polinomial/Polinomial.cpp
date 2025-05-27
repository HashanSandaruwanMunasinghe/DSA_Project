#include <iostream>
#include <cstdlib>
#include"polynomial.h"
#include <limits>


int main();
void menu();
int validation();
using namespace std;

Polynomial* list = new Polynomial[20]; //store the polys
int z = 8; // since the 7 polinomials are add before for demonstration



void AddNewPoly() { // Add new poly
    system("cls");
    cout << "\n\n                    Enter the order of polynomial = ";
    int od;
    od = validation();
    if (od < 0 || od>10) {
        while (od < 0 || od>10) {
            cout << "\n               Enter a valid order = ";
            od = validation();
        }
    }
    
    for (int i = 0; i < od + 1; i++)
    {
        int coef;
        if (od - i == 0)
            cout << "\n                              Enter the constant            = ";
        else
            cout << "\n                              Enter the coefficient for x^" << od - i << " = ";
        coef = validation();
        list[z].addTerm(coef, od - i);

    }
    z++;
    cout << "\n                  -------------- Successfully add a Polinomial  -----------\n\n"<<"                                  Press any key to continue...\n\n";
    system("pause>0");


}



void editPoly(int r) { //edit an specify polinomial

    cout << "                   Enter the order of polynomial = ";
    int od;
    od = validation();
    cout << endl;
    list[r - 1] = list[z];
    for (int i = 0; i < od + 1; i++)
    {
        int coef;

        if (od - i == 0) {
            cout << "                   Enter the constant            = ";
            coef = validation();
        }
        else if (od - i == 1) {
            cout << "                   Enter the coefficient for x   = ";
            coef = validation();
        }
        else {
            cout << "                   Enter the coefficient for x^" << od - i << " = ";
            coef = validation();
        }

        list[r - 1].addTerm(coef, od - i);

    }

    cout << "\n                     Successfully edited polynomial " << r << endl<<endl;


}



void display_List() {
    cout << "                           ---------- Polynomial List -----------\n\n";
    if (z == 0)
        cout << "\n                                    List is empty !!!\n\n\n";
    else {
        for (int i = 0; i < z; i++) {
            cout << "                               Poly " << i + 1 << " : ";
            list[i].display();
        }
    }
    cout << "\n                           ---------------------------------------\n\n";
}

void testCases(int t) {

switch (t) {
case 1: { //Display all the polynomials
    system("cls");
    display_List();
    cout << "\n                               Press any key to Continue....\n";
    system("pause>0");
    system("cls");
    menu();
    break;
}
case 2: { //Add new poly
    AddNewPoly();
    system("cls");
    menu();
    break;
}
case 3: { //Edit an existing polynomial
    system("cls");
    cout << "               This is the list of polynomials. Please select the number of polynomial that you want to edit.\n\n";
    display_List();
    int num;

    if (z == 0) {
        cout << "\n\n                       Since the list is empty you can't edit...\n                       Press any key to go back\n";
        system("Pause>0");
        system("cls");
        menu();
    }
    else {
        cout << "\n\n         Enter the number of polynomial that you want to edit = ";


        num = validation();

        
        if (num > 0 && num < z + 1) {
            //cout << "ok" << endl;
            editPoly(num);
            
        }
        else {

            while (num<1 || num>z) {
                cout << "\n                       Invalid number enter correct polynomial number = ";
                num = validation();
            }
            editPoly(num);
            
        }
        cout << "\n                       Press any key to Continue....\n";
        system("pause>0");
        system("cls");
        menu();

        break;
    }}
case 4: { //Add 2 polynomials
    system("cls");
    cout << "\n                      This is the list of polynomials. Please select two polynomials that you want to add.\n\n";
    display_List();

    if (z == 0){
        cout<<"\n\n                       Since the list is empty you can't add...\n                       Press any key to go back\n";
        system("Pause>0");
        system("cls");
        menu();
    }
    else {
        int a, b;
        cout << "                                    1st poly = ";
        a = validation();
        if (a<1 || a> z) {

            while (a<1 || a> z) {
                cout << "                   This is not valid polinomial enter again 1st poly = ";
                a = validation();
            }
        }
        cout << " \n                                    2nd poly = ";

        b = validation();
        if (b<1 || b> z) {

            while (b<1 || b> z) {
                cout << "                   This is not valid polinomial enter again 2nd poly = ";
                b = validation();


            }

        }
        Polynomial sum ;
         sum = list[a - 1].add(list[b - 1]);
         cout << "\n\n\t\t\t(poly "<<a<<" ) + (poly "<<b<<" )";
        cout << "\n\n\t\t\t\tThe answer is = ";
        sum.display();
        cout << "\n\n";
        cout << "\n                       Press any key to Continue....\n";
        system("pause>0");
        system("cls");
        menu();
        break;
    }
}



case 5: { //Substract
    system("cls");
    cout << "This is the list of polynomials. Please select two polynomials that you want to subtract.\n\n";
    display_List();

    if (z == 0) {
        cout << "\n\n                       Since the list is empty you can't substract...\n                       Press any key to go back\n";
        system("Pause>0");
        system("cls");
        menu();
    }
    else {
        int a, b;
        cout << "                                    1st poly = ";
        a = validation();
        if (a<1 || a> z) {

            while (a<1 || a> z) {
                cout << "                   This is not valid polinomial enter again 1st poly = ";
                a = validation();
            }
        }
        cout << " \n                                    2nd poly = ";

        b = validation();
        if (b<1 || b> z) {

            while (b<1 || b> z) {
                cout << "                   This is not valid polinomial enter again 2nd poly = ";
                b = validation();


            }

        }
        Polynomial sum = list[a - 1].subtract(list[b - 1]);
        cout << "\n\n\t\t\t(poly " << a << " ) - (poly " << b << " )";
        cout << "\n\n\t\t\tThe answer is = ";
        sum.display();
        cout << "\n\n";
        cout << "\n                       Press any key to Continue....\n";
        system("pause>0");
        system("cls");
        menu();
        break;
    }
}


case 6: { //Multiply 2 polinomials
    system("cls");
    cout << "\n      This is the list of polynomials. Please select two polynomials that you want to multiply.\n\n";
    display_List();
    if (z == 0) {
        cout << "\n\n                       Since the list is empty you can't multiply...\n                       Press any key to go back\n";
        system("pause>0");
        system("cls");
        menu();
    }
    else {
        int a, b;
        cout << "                                    1st poly = ";
        a = validation();
        if (a<1 || a> z) {

            while (a<1 || a> z) {
                cout << "                   This is not valid polinomial enter again 1st poly = ";
                a = validation();
            }
        }
        cout << " \n                                    2nd poly = ";

        b = validation();
        if (b<1 || b> z) {

            while (b<1 || b> z) {
                cout << "                   This is not valid polinomial enter again poly 2 = ";
                b = validation();


            }

        }
        Polynomial mul = list[a - 1].mult(list[b - 1]);
        cout << "\n\n\t\t\t(poly " << a << " ) * (poly " << b << " )";
        cout << "\n\n\t\t\tThe answer is = ";
        mul.display();
        cout << "\n\n";
        cout << "\n                       Press any key to Continue....\n";
        system("pause>0");
        system("cls");
        menu();
        break;
    }
}

case 7:
{  //to delete specific polynomial
    if (z == 0) {
        cout << "\n\n\t\t\t  The list is empty\n\n";
        system("pause>0");
        system("cls");

        menu();
        break;
    }
    else {
        system("cls");
        display_List();
        cout << "\n\t\t\t\tEnter the polynomial number that you want to delete = " ;
        int n;
        n = validation();
        if (n<1 || n>z) {
            while (n<1 || n>z) {
                cout << "\n\t\tThe number you entered is not exist polinomial enter again = " ;
                n = validation();
            }
        }
        Polynomial* newArray = new Polynomial[z];
        for (int i = 0; i < n-1; i++)
        {
            newArray[i] = list[i];
        }
        for (int i = n - 1; i < z - 1; i++)
            {
                newArray[i] = list[i + 1];

         }
        z--;
        delete[] list;
        list = newArray;
        //delete[]  newArray;
            
        cout << "\n\t\t\t\tSuccessfully deleted polynomial " << n <<" ..." << endl;
        cout << "\n\n\n\t\t\t\tPress any key to Continue....\n";
            system("pause>0");
            system("cls");
        
        menu();
        break;
    }
}

case 8: //Deletre all polynomials
{ 
    
    system("cls");

    cout << "\n\n\n\t\t Do you sure for delete all the elements?\n\n";
    cout << "\t\t\t [1] Yes\n\t\t\t [2] No\n\n";
    cout << "\t\t Enter the answer( eg. 1.  for yes) = ";
    int t;
    t = validation();
    if (t == 1) {
        

        delete[] list;
        Polynomial* newlist = new Polynomial[20];
        list = newlist;
        z = 0;
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\tSuccessfully deleted all the elements....\n\t\t\t\tPress any key to continue." << endl;
        
        system("pause>0");
        system("cls");
        menu();
        
    }
    else {
        cout << endl << endl;
        system("cls");
        menu();
    }
    break;

}

default: { //Exit from the cal.
    system("cls");
    cout << "\n\n\n\t\t Do you want to exit?\n\n";
    cout << "\t\t\t [1] Yes\n\t\t\t [2] No\n\n";
    cout << "\t\t Enter the answer( eg. 1.  for yes) = ";
    int t;
    t = validation();
    if (t == 1) {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t------------ GOOD BYE ! -------------\n\n\n\n";
        system("pause>0");
        return;
    }
    else {
        cout << endl << endl;
        system("cls");
        menu(); 
    }
    
}
}

}



void menu() { //Display menu


    cout << "                       ===============================================" << endl;
    cout << "                       =========== POLYNOMIAL CALCULATOR =============" << endl;
    cout << "                       ===============================================" << endl;
    cout << "\n                       | Press any key that you want                 |\n                       | to do operation eg: press 1 to see the list |" << endl;
    cout << endl;
    cout << "                       |----------------------------------------------|" << endl;
    cout << "                       |      [1] See the list                        |" << endl;
    cout << "                       |      [2] Add new polynomial                  |" << endl;
    cout << "                       |      [3] Edit existing polynomial            |" << endl;
    cout << "                       |      [4] Add two polynomials                 |" << endl;
    cout << "                       |      [5] Substract two polynomials           |" << endl;
    cout << "                       |      [6] Multiply two polynomials            |" << endl;
    cout << "                       |      [7] Delete a polynomial                 |" << endl;
    cout << "                       |      [8] Delete all polynomials              |" << endl;
    cout << "                       |      [9] Exit from the calculator            |" << endl;
    cout << "                       |                                              |" << endl;
    cout << "                       |----------------------------------------------|" << endl;
    int operation;
    cout << "\n                                  Enter the Value = ";
    operation = validation();
    testCases(operation);


}

int validation() { //To check the validity of user entered integers
    int userInput;

    // Keep prompting the user until a valid integer is entered
    while (true) {
   

        // Check if the input is an integer
        if (cin >> userInput) {
            // Input is an integer
            break; // Exit the loop
        }
        else {
            // Input is not an integer, clear the input buffer
            cin.clear();

            // Ignore any remaining characters in the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n\n                    Invalid input. Please enter an integer = " << endl;
        }
    }

  
    return userInput;;
}



int main() { //Main function

    // Specify sample polynomials for demonstration
    list[0].addTerm(3, 4);
    list[0].addTerm(12, 3);
    list[0].addTerm(2, 0);

    list[1].addTerm(2, 3);
    list[1].addTerm(12, 2);
    list[1].addTerm(2, 0);

    list[2].addTerm(-2, 2);
    list[2].addTerm(1, 1);
    list[2].addTerm(2, 0);


    list[3].addTerm(6, 3);
    list[3].addTerm(1, 1);
    list[3].addTerm(2, 0);
    list[3].addTerm(2, 2);



    list[4].addTerm(1, 3);
    list[4].addTerm(2, 2);
    list[4].addTerm(2, 1);
    list[4].addTerm(2, 0);


    list[5].addTerm(8, 3);
    list[5].addTerm(12, 2);
    list[5].addTerm(21, 0);
    list[5].addTerm(-1, 1);

    list[6].addTerm(2, 0);

    list[7].addTerm(2, 2);
    list[7].addTerm(1, 2);
    list[7].addTerm(-22, 0);

    // Call the menu function
    menu();
    return 0;
}

