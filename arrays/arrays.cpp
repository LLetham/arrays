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
    const int arraySize = 12;
    int intArray[arraySize] = { 0 };	// Initialize to 0.
    int tmpArray[arraySize] = { 0 };    // tmp array for non-recursive merge sort.
    int tmp;

    long int randNum = 0;

    ArrayClass ac;

    
    /*******************************************************/
    // Bubble sort
    // 1111111111111111111111111
    // The inner loop traverses from the point in the array where the outer loop points.
    // If the number pointed to by the inner loop is less than the number pointed to by the
    // outer loop, then the less number is put where the outer loop is pointing. The numbers
    // are sorted from lowest to highest iaw where the outer loop is pointing.
    // best case order = O(n^2) n = number of elements
    // worst case order = O(n)
    // space complexity = O(1). Just the size of the array.
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
    // Key scans up the array from 0 to maxNumberValue. j scans
    // down the array from the position 1 less than the key. If the
    // key is less than any value pointed to by j, then the number(s)
    // in the array are right-shifted and the key placed in the position
    // where it is the smallest.
    // best case order = O(n^2) n = number of elements
    // worst case order = O(n)
    // space complexity = ~O(1). Slightly more than 1 due to storing key.
    /*******************************************************/
    ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    ac.printArray(intArray, arraySize);

    for (int i = 1; i < arraySize; i++) {
        int key = intArray[i];
        int j = i - 1; 
        while (j >= 0 && intArray[j] > key) {
            intArray[j + 1] = intArray[j];
            j--;
        }

        intArray[j + 1] = key;
    }

    ac.printArray(intArray, arraySize);


    /*******************************************************/
    // Recursive Merge sort
    // 33333333333333333333333333333333333
    // This instance is for debug and understanding
    // all cases order = O(n*log n) n = number of elements
    // space complexity = O(2n). Slightly more than 1 due to storing key.
    // Fixed array size and known values were used to understand how it worked.
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    int intArrayFixed[arraySize] = {4, 82, 16, 3, 1, 90, 23, 49, 2, 19};
    ac.printArray(intArrayFixed, 10);

    ac.mergeSort(intArrayFixed, 0, 9);

    ac.printArray(intArrayFixed, 10);

    /*******************************************************/
    // Merge sort
    // non-recursive algorithm
    // 44444444444444444444444444444444444444444
    // all cases order = O(n*log n) n = number of elements
    // space complexity = O(2n). Slightly more than 1 due to storing key.
    /*******************************************************/
    int intArrayFixed_02[10] = { 4, 82, 16, 3, 1, 90, 23, 49, 2, 19 };
    int tmpArrayFixed[10] = { 0 };
    ac.printArray(intArrayFixed_02, 10);
    ac.printArray(tmpArray, 10);

    ac.iterativeMergeSort(intArrayFixed_02, tmpArray, 10);

    ac.printArray(intArrayFixed_02, 10);
    ac.printArray(tmpArray, 10);

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
