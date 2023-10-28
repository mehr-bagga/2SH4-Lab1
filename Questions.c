
#include "Questions.h"



int Q1_for(int num) {
    int sum = 0;
    // Declare 'i' here to avoid "expected an expression" error
    int i;
    for (i = 1; i <= 1000; i++) {
        if (i % num == 0) {
            sum += i;
        }
    }
    // here, we return the calculated sum:
    return sum;
}
int Q1_while(int num){
	int sum = 0;
	// calculate your sum below..this has to use while loop
	int i = 1;
	while(i<= 1000) {
		if (i%num == 0) {
			sum+= i;
		}
		i++;
	}
	// here, we return the calcualted sum:
	return sum;
}
int Q1_dowhile(int num){
	int sum = 0;
	// calculate your sum below..this has to use do-while loop
	int i=1;
	do{
		if (i%num == 0){
			sum += i;
		}
		i++;
	} while (i <= 1000);
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	
	int result;
	// Determine which range does Q2_input fall into.  Keep in mind the floating point number range.
	// Assign the correct output to the result.
    if (Q2_input >= -2 * Q2_threshold && Q2_input < -1 * Q2_threshold) {
        result = 0; // Input falls in the range [-2*threshold, -1*threshold)
    } else if (Q2_input >= -1 * Q2_threshold && Q2_input < 0) {
        result = 1; // Input falls in the range [-1*threshold, 0)
    } else if (Q2_input >= 0 && Q2_input < 1 * Q2_threshold) {
        result = 2; // Input falls in the range [0, 1*threshold)
    } else if (Q2_input >= 1 * Q2_threshold && Q2_input < 2 * Q2_threshold) {
        result = 3; // Input falls in the range [1*threshold, 2*threshold)
    } else {
        result = -999; // Input falls outside of specified ranges (wildcard case)
    }
	// Finally, return the result.
	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]) {
    // Counts is the variable that should hold the total number of found perfect numbers
    // You should update it within your code and return it at the end
    int counts = 0;

    // Perfect is an array that you need to add any perfect number you find
    // At the end of this function, the perfect[] array should hold all the found perfect numbers in the range
    // You do not need to return 'perfect' because arrays are already passed by reference, so modifying them will automatically reflect in the main calling function.

    // Declare variables outside of the loops
    int i, num, divisor;

    for (num = 2; num <= Q3_input; num++) {
        int sumOfFactors = 1; // Initialize with 1 (as every number is divisible by 1)

        // Calculate the sum of factors of 'num'
        for (divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                // 'divisor' is a factor of 'num'
                sumOfFactors += divisor;
                if (num / divisor != divisor) {
                    // Add the corresponding factor
                    sumOfFactors += num / divisor;
                }
            }
        }

        // Check if 'num' is a perfect number
        if (sumOfFactors == num) {
            perfect[counts] = num; // Store the perfect number in the array
            counts++; // Increment the count of perfect numbers found
        }
    }
    return counts;
}
//===============================================================================================
int Q4_Bubble(int array[], int size){
    
    // This variable tracks the number of passes done on the array to sort the array.
    int passes = 0;

    // Pseudocode
    //  1. Given an array and its size, visit every single element in the array up to size-2 (i.e. up to the second last element, omit the last element)
    int i;
    int swapped; // Declare swapped here to make it accessible in the while condition
    do {
        swapped = 0; // Flag to track whether any elements were swapped in a pass
        //  2. For every visited element (current element), check its subsequent element (next element).  
        for (i = 0; i < size - 1; i++) {
        //     If the next element is smaller, swap the current element and the next element. 
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1; // Set swapped flag to true
            }
        }
        //  3. Continue until reaching size-2 element.  This is considered One Pass => increment pass count by one.
        passes++;
        //  4. Repeat 1-3 until encountering a pass in which no swapping was done.
    } while(swapped);
    //   -> Sorting Completed.
    // Finally, return the number of passes used to complete the Bubble Sort
    return passes;    
}