#pragma once

#include <iostream>
#include <time.h>       // need for ctime
#include <cstdlib>      // need for srand


class ArrayClass
{

private:
	int j;


public:
	// print out array
	void printArray(int* array, int arraySize) {

		std::cout << "array:\t";
		for (int k = 0; k < arraySize; k++) {
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


};

