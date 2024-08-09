/*
 * Class: CMSC140 10016 and 10152
 * Instructor: Margaret Tseng
 * Project 5
 * Description: This program prompts a user to input numbers into a grid and determine if it is a Lo Shu magic square.
 * Due Date: August 9, 2024
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Adam Yerima
 */
 
#include <iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main() {
    char playAgain;
    do{
        int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
    
        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS)) {
            cout << "This is a Lo Shu magic square." << endl;
        } else {
            cout << "This is not a Lo Shu magic square." << endl;
        };
        
        cout << "Do you want to try again?(Y to continue/ Any other key to end): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    // Display project information
    cout << "\nPROGRAMMER: Adam Yerima\n";
    cout << "CMSC140 Project 5\n";
    cout << "Due Date: August 9, 2024\n";

    return 0;
}

// Function to fill arrays with user input
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    
    for (int i = 0; i < size; ++i) {
        cout << "Enter the number for row 0 and column " << i << ": ";
        cin >> arrayRow1[i];
    }

    for (int i = 0; i < size; ++i) {
        cout << "Enter the number for row 1 and column " << i << ": ";
        cin >> arrayRow2[i];
    }

    for (int i = 0; i < size; ++i) {
        cout << "Enter the number for row 2 and column " << i << ": ";
        cin >> arrayRow3[i];
    }
}

// Function to display the arrays
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    cout << "Grid:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
}

// Function to check if the grid is a magic square
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
           checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
}

// Function to check if all values are within the specified range
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        if (arrayRow1[i] < min || arrayRow1[i] > max ||
            arrayRow2[i] < min || arrayRow2[i] > max ||
            arrayRow3[i] < min || arrayRow3[i] > max) {
            return false;
        }
    }
    return true;
}

// Function to check if all values are unique
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    bool found[10] = {false}; // Values are from 1 to 9
    
    for (int i = 0; i < size; ++i) {
        if (found[arrayRow1[i]] || found[arrayRow2[i]] || found[arrayRow3[i]]) {
            return false;
        }
        found[arrayRow1[i]] = true;
        found[arrayRow2[i]] = true;
        found[arrayRow3[i]] = true;
    }
    return true;
}

// Function to check if the sum of rows are equal
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; ++i) {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }
    return (sum1 == sum2 && sum2 == sum3);
}

// Function to check if the sum of columns are equal
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; ++i) {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }
    return (sum1 == sum2 && sum2 == sum3);
}

// Function to check if the sum of diagonals are equal
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int diag1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int diag2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    return (diag1 == diag2);
}
