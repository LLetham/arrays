#pragma once

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand

#define UNDERSTAND_stack 0
#define SHOW_array 0

class ArrayClass
{

private:
	int x, y, z;
    int arraySize = 10;
    int callNumber = 0;


public:
	/******************************************/
    // print out array starting at element zero
	void printArray(int* array, int arraySize) {

		std::cout << "array:\t";
		for (int k = 0; k < arraySize; k++) {
			std::cout << array[k] << "\t";
		}
		std::cout << std::endl;
	}

    /******************************************/
    // print out array between start and end
    void printArray(int* array, int start, int end) {

        std::cout << "array[" << start <<"] to [" << end << "]:""\t";
        for (int k = start; k <= end; k++) {
            std::cout << array[k] << "\t";
        }
        std::cout << std::endl;
    }

    /******************************************/
	// Fill array with random numbers less than maxNumberValue
	void fillArrayRand(int* array, int arraySize, const int maxNumberValue) {

		std::srand(long int(time(0)));    // seed the random number generator with the time of day

		// fill the array with random numbers in valoe from 0 to 999
		for (int i = 0; i < arraySize; i++) {

			// rand gets a random number. 
			// Modulo maxNumberValue to keep values less than maxNumberValue
			array[i] = std::rand() % maxNumberValue;
		}

		// verify no value in intArray is greater than maxNumberValue
		for (int i = 0; i < arraySize; i++) {
			if (array[i] > maxNumberValue) {
				std::cout << "array[" << i << "]: " << array[i] << "\t Greater than\t" << maxNumberValue << std::endl;
			}
		}
	}

    void zeroOut(int *array, int arraySize) {
        for (int i = 0; i < arraySize; i++)
            array[i] = 0;
    }

    /******************************************/
    // Merges two subarrays of array[]. 
    // First subarray is arr[begin..mid] 
    // Second subarray is arr[mid+1..end] 
    void merge(int array[], int const left, int const mid, int const right)
    {
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        // Create temp arrays 
        auto* leftArray = new int[subArrayOne];
        auto* rightArray = new int[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++) {
            leftArray[i] = array[left + i];
        }

        for (auto j = 0; j < subArrayTwo; j++) {
            rightArray[j] = array[mid + 1 + j];
        }

        // Initial index of first sub-array 
        // Initial index of second sub-array 
        auto indexOfSubArrayOne = 0;
        auto indexOfSubArrayTwo = 0;

        // Initial index of merged array 
        int indexOfMergedArray = left;

        // Merge the temp arrays back into array[left..right] 
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        // Copy the remaining elements of left[], if there are any 
        while (indexOfSubArrayOne < subArrayOne)
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        // Copy the remaining elements of right[], if there are any 
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    /***********************************************************************************/
    // The below merge sort code came from geeksforgeeks.org/merge-sort/#
    // 1. It is a recursive algorithm that splits the array in half
    // 2. recursivly splits the lower half of the array in half until the array size is one
    //    then merges the units into the upper half of the lower half until the lower half 
    //    is sorted.
    // 3. Recursively splits the upper half into halfs and sorts.
    // 4. Merges the sorted lower and upper halves of the original array to produce the
    //    final sorted array.
    // To understand the recursion and the effects on the array, I had to use a lot of cout stmts.
    // I tracked the stack and the returns to understand the recursion.
    // Use UNDERSTAND_stack to see the stack messages.
    // Use SHOW_array to see the array as it is processed.
    void mergeSort(int array[], int const begin, int const end)
    {
#if UNDERSTAND_stack
        callNumber++;
        std::cout << "\nmergSort\tbegin:\t" << begin << "\tend:\t" << end << "\tcall number:\t" << callNumber << std::endl;
#endif
        // Returns recursively 
        if (begin >= end) {
#if UNDERSTAND_stack
            callNumber--;
            std::cout << std::endl << "return. Call number:\t" << callNumber << std::endl;
#endif
            return;
        }

        auto mid = begin + (end - begin) / 2;
#if SHOW_array
        std::cout << "\nbegin:\t" << begin << "\tmid:\t" << mid << "\tend:\t" << end << std::endl;
#endif

#if UNDERSTAND_stack
        std::cout << "mergSort L:\tbegin\t" << begin << "\tend:\t" << mid << std::endl;
#endif
#if SHOW_array
        printArray(array, begin, mid);
#endif
        mergeSort(array, begin, mid);       // left (e.g., lower) part of array

#if UNDERSTAND_stack
        std::cout << "mergSort U:\tbegin:\t" << mid + 1 << "\tend:\t" << end << std::endl;
#endif
#if SHOW_array
        printArray(array, mid + 1, end);
#endif
        mergeSort(array, mid + 1, end);     // right (e.g., upper) part of the array

#if UNDERSTAND_stack
        std::cout << "merg:\tbegin\t" << begin << "\tmid:\t" << mid << "\tend:\t" << end << std::endl;
#endif
#if SHOW_array
        printArray(array, begin, end);
#endif
        merge(array, begin, mid, end);
#if SHOW_array
        printArray(array, begin, end);
        printArray(array, 0, arraySize);
        std::cout << std::endl;
#endif
#if UNDERSTAND_stack
        callNumber--;
        std::cout << std::endl << "end. Call number:\t" << callNumber << std::endl;
#endif

    }





};

