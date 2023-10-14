#pragma once

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand

#define UNDERSTAND_stack 0
#define SHOW_array 0

class ArrayClass
{

private:
	//int x, y, z;
    //int arraySize = 10;
    int callNumber = 0;
    //int right, wid, rend;
    //int m, t;
    //int n;
    int x;
    int passNumber;  // the number of passes to merge sort an array
    int low;        // the low eleement of a list for merge sort
    int mid;        // the mid element of a list for merge sort
    int high;       // the high element of a list for merge sort
    int i = 0;          // pointer to sorted list
    int j = 0;          // pointer to sorted list
    int k = 0;          // pointer to a temporary list



public:
	/******************************************/
    // print out array starting at element zero
	void printArray(int* array, int arraySize) {

		std::cout << "a: ";
		for (int k = 0; k < arraySize; k++) {
			std::cout << array[k] << "\t";
		}
		std::cout << std::endl;
	}

    /******************************************/
    // Verify that the array is in ascending order
    void verifyArray(int* array, int arraySize) {
        for (int k = 0; k < arraySize - 1; k++) {
            if (array[k] > array[k + 1])
                std::cout << "elements [" << k << "] and [" << k + 1 << "] not in ascending order" << std::endl;
        }
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
    // Fill array with random numbers less than maxNumberValue
    // when the program runs without pauses, such as in debug, the program runs so fast
    // that the time() function does not change and the numbers are the same for each loop.
    // The seedAdditive adds a changing factor to time() to try to get different numbers.
    void fillArrayRand(int* array, int arraySize, const int maxNumberValue, int seedAdditive) {

        std::srand(long int(time(0) + seedAdditive));    // seed the random number generator with the time of day

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
        printArray(array, 0, end);
        std::cout << std::endl;
#endif
#if UNDERSTAND_stack
        callNumber--;
        std::cout << std::endl << "end. Call number:\t" << callNumber << std::endl;
#endif

    }


    /************************************************************/
    // Based on video by Abdul Bari
    // Each element of the array is considered a sorted list.
    // The sorted lists need to be merged.
    // original array: 4, 82, 16, 3, 1,   90, 23, 49, 2, 19   each element is a separate list
    //                  \  /  \   /  \    /   \   /  \   /
    // after 1st pass  4  82  3  16  1   90  23  49  2  19   5 lists of 2 elements. Each list is sorted.
    //                  \            /   \               /
    // after 2nd pass   1 3  4  16  82   2 19 23 49 90      2 lists of 5 elements. Each list is sorted.
    //                   \                           /
    // after 3rd pass      1 2 3 4 16 19 23 49 82 90        1 list of 10 elements. The list is sorted.
    // intArray is the array to be sorted.
    // numElements is the number of elements in the array
    /*************************************************************/
    void iterativeMergeSort(int* intArray, int* tmpArray, int numElements) {

        // power of 2 merge: 2 elements, 4 elements, 8 elements, etc.
        for (passNumber = 2; passNumber <= numElements; passNumber = passNumber * 2) {

            // merging lists. Lower list from low to mid. Upper list from mid to high.
            for (x = 0; x + passNumber - 1 < numElements; x = x + passNumber) {
                low = x;
                high = x + (passNumber - 1);
                mid = (low + high) / 2;
                mergeArrays(intArray, tmpArray, low, mid, high);
                printArray(intArray, numElements);
                printArray(tmpArray, numElements);
            }
            printArray(intArray, numElements);
            printArray(tmpArray, numElements);
        }
        printArray(intArray, numElements);
        printArray(tmpArray, numElements);

        // Merge any odd, not power of 2 blocks of elements
        if ((passNumber / 2) < numElements) {
            mid = (passNumber / 2) - 1;
            high = numElements - 1;
            mergeArrays(intArray, tmpArray, 0, mid, high);
            printArray(intArray, numElements);
            printArray(tmpArray, numElements);
        }
        printArray(intArray, numElements);
        printArray(tmpArray, numElements);
    }

    /***********************************************************/
    // Merge two lists in a single array
    void mergeArrays(int* intArray, int* tmpArray, int low, int mid, int high) {
        i = low;
        j = mid + 1;
        k = low;

        while (i <= mid && j <= high) {
            if (intArray[i] < intArray[j]) {
                tmpArray[k] = intArray[i];
                k++;
                i++;
            }
            else {
                tmpArray[k] = intArray[j];
                k++;
                j++;
            }
        }

        // end of mid to high reached, so copy the reminder of low to mid
        // into tmpArray.
        for (; i <= mid; i++) {
            tmpArray[k] = intArray[i];
            k++;
        }

        // end of low to mid reached, so copy the reminder of mid to high 
        // into tmpArray.
        for (; j <= high; j++) {
            tmpArray[k] = intArray[j];
            k++;
        }

        // copy tmpArray back into intArray
        for (i = low; i <= high; i++) {
            intArray[i] = tmpArray[i];
        }

    }


};

