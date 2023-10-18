// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand
#include "ArrayClass.h"




// main is the test bed for the arrays created in the classes.
int main()
{
    const int maxNumberValue = 10000;
    const int midNumberValue = 500;
    const int arraySize = 21;
    int intArray[arraySize] = { 0 };	// Initialize to 0.
    int tmpArray[arraySize] = { 0 };    // tmp array for non-recursive merge sort.
    int tmp;
    int loop;
    const int maxLoop = 20;

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
    // 3333333333333333.0000000000000000000000
    // This instance is for debug and understanding
    // all cases order = O(n*log n) n = number of elements
    // space complexity = O(2n). Slightly more than 1 due to storing key.
    // Fixed array size and known values were used to understand how it worked.
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    int intArrayFixed[10] = {4, 82, 16, 3, 1, 90, 23, 49, 2, 19};
    ac.printArray(intArrayFixed, 10);

    ac.mergeSort(intArrayFixed, 0, 9);

    ac.printArray(intArrayFixed, 10);
    ac.verifyArray(intArray, 10);

    /*******************************************************/
    // Recursive Merge sort
    // 33333333333333.111111111111111111111111111111
    // larger array size for testing.
    // loop many times for test.
    /*******************************************************/
    std::cout << "Start of recursive merge sort" << std::endl;
    for (loop = 0; loop < maxLoop; loop++) {
        ac.fillArrayRand(intArray, arraySize, maxNumberValue, loop);
        // ac.printArray(intArray, arraySize);      // unsorted array not printed.

        ac.mergeSort(intArray, 0, arraySize - 1);

        ac.printArray(intArray, arraySize);
        ac.verifyArray(intArray, arraySize);
    }

    /*******************************************************/
    // Merge sort
    // Fix array size and values to understand and debug algorithm
    // non-recursive algorithm
    // 44444444444444444.0000000000000000000000000000
   /*******************************************************/
    std::cout << "Start of iterative merge sort fix array" << std::endl;
    int intArrayFixed_02[21] = { 34, 49, 16,  6,
                                 77, 95, 82, 31,
                                 18, 19, 49, 29,
                                 74,  3, 47,  2,
                                 23,  8, 57,  4,
                                 10 };
    ac.zeroOut(tmpArray, 21);
    ac.printArray(intArrayFixed_02, 21);

    ac.iterativeMergeSort(intArrayFixed_02, tmpArray, 21);

    ac.printArray(intArrayFixed_02, 21);
    ac.verifyArray(intArrayFixed_02, 21);

    /*******************************************************/
    // Merge sort
    // non-recursive algorithm
    // 4444444444444444.1111111111111111111111111111111111111
    // all cases order = O(n*log n) n = number of elements
   /*******************************************************/
    std::cout << "Start of iterative merge sort" << std::endl;
    for (loop = 0; loop < maxLoop; loop++) {
        ac.fillArrayRand(intArray, arraySize, maxNumberValue, loop);
        //ac.zeroOut(tmpArray, arraySize);
        //ac.printArray(intArray, arraySize);       // unsorted array not printed.

        ac.iterativeMergeSort(intArray, tmpArray, arraySize);

        ac.printArray(intArray, arraySize);
        ac.verifyArray(intArray, arraySize);
    }

    /*******************************************************/
    // Quick sort
    // 444444444444444.22222222222222222222222222222
    // LL: Is there an array merge in the STL?
    // LL: Is there a merge sort in the STL?
    // here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    //ac.printArray(intArray, arraySize);


    //ac.printArray(intArray, arraySize);



    /*******************************************************/
    // Quick sort
    // 444444444444444444444444444444444
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    //ac.printArray(intArray, arraySize);


    //ac.printArray(intArray, arraySize);


    /*******************************************************/
    // Heap sort
    // 55555555555555555555555555555555555555555555555
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    //ac.printArray(intArray, arraySize);


    //ac.printArray(intArray, arraySize);

    /*******************************************************/
    // Count sort
    // 55555555555555555555555555555555555555555555555
    /*******************************************************/
    //ac.fillArrayRand(intArray, arraySize, maxNumberValue);
    //ac.printArray(intArray, arraySize);


    //ac.printArray(intArray, arraySize);
}
