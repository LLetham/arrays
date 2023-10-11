// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand


// main is the test bed for the arrays created in the classes.
int main()
{
    const int maxNumberValue = 1000;
    const int midNumberValue = 500;
    const int arraySize = 10;
    int intArray[arraySize] = { 0 };	// array of 100 integers. Initialize to 0.
    int intArraySort[arraySize] = { 0 };  // an array for performing sorting
    int tmp;

    long int randNum = 0;

    int grt499 = 0;

    
    /******************************/
    std::srand(time(0));    // seed the random number generator with the time of day


    /*************************************************/
    // Start of testing the array

    // fill the array with random numbers in valoe from 0 to 999
    for (int i = 0; i < arraySize; i++) {

        intArray[i] = std::rand() % maxNumberValue;    // rand gets a random number. Modulo 1000 to keep less than 1000

    }

    // verify no value in intArray is greater than 1000
    for (int i = 0; i < arraySize; i++) {
        if (intArray[i] > maxNumberValue) {
            std::cout << "intArray[" << i << "]: " << intArray[i] << "\t Greater than\t" << maxNumberValue << std::endl;
        }
    }

    // See of 50% of the values in the array are > 499 to measure randomness of rand()
    for (int i = 0; i < arraySize; i++) {
        if (intArray[i] > midNumberValue) {
            grt499++;
            std::cout << "intArray[" << i << "]:\t" << intArray[i] << "\tGreater than\t" << midNumberValue << std::endl;
        }
    }

    std::cout << grt499 << "\t numbers greater than 499" << std::endl;

    // Sort the numbers in the array. Because 51 are less than 499, the value at intArray[50] after the
    // sort should be very close to 499.
    // Copy intArray into intArraySort. Sort on intArraySort.
    // Do bubbles sort.
    for (int i = 0; i < arraySize; i++) {
        intArraySort[i] = intArray[i];
    }

    // print out array to watch numbers move.
    std::cout << "array:\t";
    for (int k = 0; k < arraySize; k++) {
        std::cout << intArraySort[k] << "\t";
    }
    std::cout << std::endl;


    for (int i = 0; i < arraySize; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (intArraySort[i] < intArraySort[j]);
            tmp = intArraySort[i];
            intArraySort[i] = intArraySort[j];
            intArraySort[j] = tmp;

            // print out array to watch numbers move.
            std::cout << "array:\t";
            for (int k = 0; k < arraySize; k++) {
                std::cout << intArraySort[k] << "\t";
            }
            std::cout << std::endl;
        }
        // print out array to watch numbers move.
        std::cout << "array:\t";
        for (int k = 0; k < arraySize; k++) {
            std::cout << intArraySort[k] << "\t";
        }
        std::cout << std::endl;


    }



    /*************/
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
