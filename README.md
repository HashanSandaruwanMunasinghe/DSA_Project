Polynomial Calculator (C++)
📚 Overview
This is a console-based Polynomial Calculator implemented in C++. It allows users to:

Add new polynomials

Edit existing polynomials

Display a list of saved polynomials

Perform polynomial addition, subtraction, and multiplication

Delete specific or all polynomials

This program demonstrates the use of object-oriented programming, dynamic memory allocation, and basic input validation in C++.

🧮 Features
Store and manage up to 20 polynomials

Add, subtract, or multiply any two selected polynomials

Edit an existing polynomial

Delete a specific polynomial or clear the entire list

Validate user inputs to ensure correct polynomial order and coefficients

Built-in menu interface for easy navigation

🛠️ Technologies Used
C++

Standard Template Library (STL)

Console-based interface

Custom header file polynomial.h for the Polynomial class

📁 File Structure
bash
Copy code
Polynomial-Calculator/
│
├── main.cpp          # Main logic of the application
├── polynomial.h      # Header file containing Polynomial class definition
├── polynomial.cpp    # Source file for Polynomial class implementation
├── README.md         # Project description and usage guide
▶️ How to Run
Clone the repository or download the files

Compile the project

css
Copy code
g++ main.cpp polynomial.cpp -o polycalc
Run the executable

bash
Copy code
./polycalc
✏️ Sample Polynomial Operations
Add two polynomials:

Choose option 4 from the menu and select two polynomials.

Edit a polynomial:

Use menu option 3 and select the polynomial index to edit.

Delete:

Use option 7 to delete a specific polynomial

Use option 8 to delete all stored polynomials

📌 Input Format
Polynomial order must be between 0 and 10

Each coefficient is entered manually in descending order of exponent

All inputs are validated using validation() method

