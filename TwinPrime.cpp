/* Name: Sofia Sanchez
Date: 02/06/2022
Section: 0011
Assignment: Twin Prime Numbers Program
Due Date: 02/06/2022
About this project: This program finds and displays the (number of) prime
numbers two above or two below another prime number below the maximum number
determined by the user.
Assumptions: NA
All work below was performed by Sofia Sanchez */

#include <iostream>
using namespace std;

//define variable that will store the upper limit inputted by the user
int upperLimit;
/* define variable that will increment to test the "prime" status of different
 values and initialize it at the value of 1 */
int counter = 1;
/* define variable that will increment to test whether counter and counter+2
 are divisible by it and initialize it to 1 */
int divisor = 1;
/* define boolean variable that describes whether counter and counter+2 are
 twin prime numbers */
bool twinPrimes = true;
//defines variable that will store the value of the first twin prime number
int primeNumber1;
//defines variable that will store the value of the second twin prime number
int primeNumber2;
/*defines variable that will increment when a twin prime pair is found and
 initializes it to zero */
int numberOfPrimePairs = 0;

int main() {
    //welcome message
    cout << "Welcome to the Twin Prime Numbers Program!" << endl;
    //prompt
    cout << "To get started, enter a number to set the upper limit" << endl
    << "for the range of numbers inside which you would like" << endl
    << "to look for twin prime numbers. This value should be at least 1."
    << endl;
    //stores the value entered by the user in the upperLimit variable
    cin >> upperLimit;
    /* input validation loop for upperLimit input;
     as long as the upper limit is less than 1... */
    while (upperLimit < 1) {
        //error message
        cout << "The value you entered is invalid. Please input a value"
        << " of 1 or more." << endl;
        //re-prompt
        cout << "Enter another value to set the upper limit: ";
        //store the newly inputted value in place of the previous one
        cin >> upperLimit;
    }
    /* repeats as long as counter variable is less than or equal to the upper
     limit */
    while (counter <= upperLimit) {
        /* repeats as long as counter and counter+2 are being divided by
         a number that is less than counter+2 (count+2 being divisible by
         itself wouldn't make it not a prime number) */
        while (divisor < (counter + 2)) {
            /* tests whether counter and counter+2 are twin prime numbers
             * sets twinPrimes variable to false if the counter is divisible by
             the divisor and the counter is not equal to the divisor (the
             counter being divisible by itself or 1 wouldn't make it not a prime
             number), counter+2 is divisible by the divisor and the divisor is
             not 1 (counter+2 being divisible by 1 wouldn't make it not a prime
             number), or counter is equal to 1 (1 is not a prime number) */
            if ((counter % divisor == 0 && counter != divisor && divisor > 1) || ((counter + 2)
            % divisor == 0  && divisor > 1) || counter == 1) {
                twinPrimes = false;
            }
            //to prepare for process repetition
            //increment the divisor by 1
            divisor++;
        }
        //once all the divisor values between 2 and counter+2 have been tested
        /* if counter and counter+2 are twin prime numbers and counter+2 is less
         than the upper limit (we don't want display a twin prime pair where
         counter+2 (or counter) is/are above the upper limit),... */
        if (twinPrimes && (counter + 2) <= upperLimit) {
            //set the primeNumber1 variable to the value of counter
            primeNumber1 = counter;
            //set the primeNumber2 variable to the value of counter+2
            primeNumber2 = counter + 2;
            //increment the number of prime pairs found by 1
            numberOfPrimePairs++;
            //display the twin prime pair
            cout << "(" << primeNumber1 << "," << primeNumber2 << ")" << endl;
        }
        //to prepare for process repetition
        //increment the counter variable by 1
        counter++;
        //reset divisor and twinPrimes back to their original values
        divisor = 2;
        twinPrimes = true;
    }
    /* if numberOfPrimePairs is equal to zero (there is no way for
     numberOfPrimePairs to be negative),... */
    if (numberOfPrimePairs == 0) {
        //display the following text
        cout << "No twin prime numbers found." << endl;
    }
    //if numberOfPrimePairs is equal to 1
    else if (numberOfPrimePairs == 1) {
        cout << numberOfPrimePairs << " twin prime pair found." << endl;
    }
    //otherwise,...
    else {
        //display the number of prime pairs found in the following sentence
        cout << numberOfPrimePairs << " twin prime pairs found." << endl;
    }
    //finish
    return 0;
}
