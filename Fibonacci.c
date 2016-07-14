#include <stdlib.h>
#include <limits.h>
#include "Fibonacci.h"

unsigned long int nthFibonacciTerm(long int term, int* success) {
	// Make sure the success pointer is valid
	if (success == NULL) {
		return '\0';
	} else {
		*success = '\0';
	}

	// Check if the input is negative
	if (term < 0) {
		*success = -1;
		return '\0';
	}

	// Check if the input is zero
	if (term == 0) {
		*success = 1;
		return 0;
	}

	// Start sequence off with 1 and 1
	unsigned long int num1 = 1;
	unsigned long int num2 = 1;
	int next = 0;


	// We can skip two iterations because we already know the first two terms
	int i;
	for (i = 2; i < term; i++) {
		// Test if the next addition will cause an overflow
		if (willOverflow(num1, num2) == 1) {
			*success = 0;
			return ULONG_MAX;
		}

		// Alternate the variable we add to
		if (next == 0) {
			num1 += num2;
			next = 1;
		} else {
			num2 += num1;
			next = 0;
		}
	}

	// Return the last number we added to
	if (next == 0) {
		*success = 1;
		return num2;
	} else {
		*success = 1;
		return num1;
	}
}

// Test for if the unsigned long int will overflow
int willOverflow(unsigned long int num1, unsigned long int num2) {
	if (num1 > ULONG_MAX - num2) {
		return 1;
	} else {
		return 0;
	}
}
