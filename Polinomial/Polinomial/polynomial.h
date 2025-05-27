#pragma once

#include <iostream>
#include <cstdlib>



using namespace std;


// Class for a term in the polynomial
class Term {
public:
    int coefficient;
    int exponent;
    Term* next;

    Term(int coef, int exp) { //constructor
        coefficient = coef;
        exponent = exp;
        next = NULL;
    }
};



// Class for polynomial manipulation using a linked list
class Polynomial {
private:
    Term* head;
    int size = 0;
public:
    Polynomial() {
        head = NULL;
        size++;
    }

    // Function to add a term to the polynomial
    void addTerm(int coef, int exp) {
        Term* newTerm = new Term(coef, exp);
        if (head == NULL || exp > head->exponent) {
            newTerm->next = head;
            head = newTerm;
        }
        else {
            Term* current = head;
            while (current->next != NULL && exp <= current->next->exponent) {
                current = current->next;
            }
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }

    

    // Function to display the polynomial
    void display() {
       
        //print head node 
        if (head->exponent == 0) {
            if (head->coefficient >= 0) // to ommit ax^0 -> a
                cout << abs(head->coefficient);
            else
                cout << head->coefficient;
        }

        else {
            if (head->coefficient < 0)
                if (head->exponent == 1)
                    if (head->coefficient == -1) //to ommit -1x -> -x
                        cout << "-x";

                    else
                        cout << head->coefficient << "x";
                else
                    if (head->coefficient == -1) // to ommit -1x^n -> -x^n
                        cout << "-x^" << head->exponent;
                    else
                        cout << head->coefficient << "x^" << head->exponent;
            else
                if (head->exponent == 1)
                    if (head->coefficient == 1) // 1x -> x
                        cout << "x";
                    else
                        cout << abs(head->coefficient) << "x"; //+ax -> ax
                else
                    if (head->coefficient == 1)
                        cout << "x^" << head->exponent;
                    else
                        cout << abs(head->coefficient) << "x^" << head->exponent;

        }

        //print other terms
        Term* current = head->next;

        while (current != NULL) {
            if (current->coefficient != 0) {

                if (current->coefficient > 0) { //print the sign
                    cout << " + ";
                }
                else {
                    cout << " - ";
                }


                //For ommit the unneccesory "1x"-> x
                if (abs(current->coefficient) != 1 || current->exponent == 0) {
                    cout << abs(current->coefficient); // to print the absolute value of coefficient
                }

                if (current->exponent > 0) {

                    // to print the power
                    cout << "x";    // x^1 -> x

                    if (current->exponent > 1) { //from x^n

                        cout << "^" << current->exponent;
                    }


                }
            }
            current = current->next;
        }
        cout << endl;
    }




    // Function to add two polynomials
    Polynomial add(Polynomial& other) {
        Polynomial result; // To store the answer
        Term* current1 = head;
        Term* current2 = other.head;

        while (current1 != NULL || current2 != NULL) {//Until one polynomial is over
            int coef1;
            if (current1 != NULL) {
                coef1 = current1->coefficient; //untill current1 goes to the coefficient of poly1
            }
            else {
                coef1 = 0;
            }

            int coef2;
            if (current2 != NULL) {
                coef2 = current2->coefficient;//untill current2 goes to the coefficient of poly2
            }
            else {
                coef2 = 0;
            }
            //same as exponential
            int exp1;
            if (current1 != NULL) {
                exp1 = current1->exponent;
            }
            else {
                exp1 = 0;
            }

            int exp2;
            if (current2 != NULL) {
                exp2 = current2->exponent;
            }
            else {
                exp2 = 0;
            }


            if (exp1 == exp2) {
                result.addTerm(coef1 + coef2, exp1); //add terms to plynomial 'result'
                current1 = current1->next; //traverse through the whole polynomial
                current2 = current2->next;
            }
            else if (exp1 > exp2) {//Greater order term only goes to 'addTerm' function
                result.addTerm(coef1, exp1);
                current1 = current1->next;
            }
            else {
                result.addTerm(coef2, exp2);
                current2 = current2->next;
            }
        }

        return result;
    }


    // Function to subtract two polynomials
    Polynomial subtract(Polynomial& other) {
        

        Polynomial result; // To store the answer
        Term* current1 = head;
        Term* current2 = other.head;

        while (current1 != NULL || current2 != NULL) {//Until one polynomial is over
            int coef1;
            if (current1 != NULL) {
                coef1 = current1->coefficient;
            }
            else {
                coef1 = 0;
            }

            int coef2;
            if (current2 != NULL) {
                coef2 = current2->coefficient;
            }
            else {
                coef2 = 0;
            }

            int exp1;
            if (current1 != NULL) {
                exp1 = current1->exponent;
            }
            else {
                exp1 = 0;
            }

            int exp2;
            if (current2 != NULL) {
                exp2 = current2->exponent;
            }
            else {
                exp2 = 0;
            }


            if (exp1 == exp2) {
                result.addTerm(coef1 - coef2, exp1);
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (exp1 > exp2) {//Greater order term only goes
                result.addTerm(coef1, exp1);
                current1 = current1->next;
            }
            else {
                result.addTerm(coef2*-1, exp2); //if the second term has a higher order
                current2 = current2->next;
            }
        }
       

        return result; //return the answer


    }

    Polynomial mult(Polynomial& other) {
        Polynomial A;
        Term* current = head;
        int i = 0;
        while (current != NULL) {//to find the size of polynomial 1
            current = current->next;
            i++; //return no of terms in the polynomial1
        }
        int* temp1 = new int[i]; //create an array with the size of polynomial 1
        current = head;
        for (int j = 0; j < i; j++)//to store the poly.
        {
            temp1[j] = current->coefficient; //assign all coefficient to the temp1
            current = current->next;
            
        }

        //same process to polynomial2
        Term* current2 = other.head;
        
        int k = 0;
        while (current2 != NULL) {
            current2 = current2->next;
            k++;
        }

        int* temp2 = new int[k];
        current2 = other.head;
       
        for (int l = 0; l < k; l++)
        {
            temp2[l] = current2->coefficient;
            current2 = current2->next;
            

        }

        A = multiplyTwoPolynomials(temp1, temp2, i, k); //pass temp1 and temp2 and their sizes to 'multiplyTwoPolynomials' function

        return A;

    }

    Polynomial multiplyTwoPolynomials(int* A, int* B, int m, int n) {

        int* productPolynomial = new int[m + n - 1];
        for (int i = 0; i < m + n - 1; i++) {
            productPolynomial[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                productPolynomial[i + j] += A[i] * B[j];
            }
        }// return coefficient as 1D array
        

       
        Polynomial result;
        for (int i = 0; i < m + n - 1; i++)
        {
            result.addTerm(productPolynomial[i], m + n - 2 - i); //store all coeffients and powers to the addTerm
        }
        return result;
    }


};