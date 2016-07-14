#include <stdlib.h>
#include "GreatestCommonDivisor.h"

long int gcd(long int num1, long int num2, int* success) {
	// Verify input
	if (num1 == 0 || num2 == 0) {
		*success = 0;
		return 0;
	}

	if (success == NULL) {
		return 0;
	} else {
		*success = '\0';
	}

	// Make the numbers non-negative
	if (num1 < 0) {
		num1 *= -1;
	}

	if (num2 < 0) {
		num2 *= -1;
	}

	// Make sure num1 is greater
	if (num2 > num1) {
		long int temp = num2;
		num2 = num1;
		num1 = temp;
	}

	// Get the greatest common divisor
	long int remainder = '\0';
	long int lastRemainder = '\0';

	do {
		lastRemainder = remainder;
		remainder = (num1 % ((num1 / num2) * num2));

		num1 = num2;
		num2 = remainder;
	} while (remainder != 0);

	*success = 1;

	// If there was no remainder, return the original 2nd number
	if (lastRemainder == 0) {
		return num1;
	} else {
		return lastRemainder;
	}
}
