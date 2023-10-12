// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand
#include "ArrayClass.h"


// main is the test bed for the arrays created in the classes.
int main()
{
    const int maxNumberValue = 1000;
    const int midNumberValue = 500;
    const int arraySize = 10;
    int intArray[arraySize] = { 0 };	// array of 100 integers. Initialize to 0.
    //int intArraySort[arraySize] = { 0 };  // an array for performing sorting
    int tmp;

    long int randNum = 0;

    ArrayClass ac;

    

    // Bubble sort
    // 1111111111111111111111111
    /*******************************************************/
    //// print out array prior to sort
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);

    for (int i = 0; i < arraySize; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (intArray[i] > intArray[j]) {
                tmp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = tmp;
            }
        }
    }

    ac.printArray(intArray, arraySize);

    /*******************************************************/
    // Insertion sort
    // 22222222222222222222222222222222
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);

    //for (int i = 1; i < arraySize; i++) {
    //    int key = intArray[i];
    //    int j = i - 1; 
    //    while (j >= 0 && arraySize[j] > key) {
    //        arraySize[j + 1] = intArray[j];
    //        j--;
    //    }

    //    arraySize[j + 1] = key;
    //}

    ac.printArray(intArray, arraySize);


    /*******************************************************/
    // Merge sort
    // 33333333333333333333333333333333333
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);


    ac.printArray(intArray, arraySize);

    /*******************************************************/
    // Quick sort
    // 444444444444444444444444444444444
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);


    ac.printArray(intArray, arraySize);


    /*******************************************************/
    // Heap sort
    // 55555555555555555555555555555555555555555555555
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);


    ac.printArray(intArray, arraySize);

    /*******************************************************/
    // Count sort
    // 55555555555555555555555555555555555555555555555
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);


    ac.printArray(intArray, arraySize);




    /*************/
    std::cout << "Hello World!\n";
}
