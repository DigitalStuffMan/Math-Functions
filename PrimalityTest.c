#include <stdlib.h>
#include <math.h>
#include "PrimalityTest.h"

// This is the simple trial division test
int isPrime(long int num) {
	if (num < 1) {
		return 0;
	} else if (num <= 3) {
		return 1;
	}

	// Check if num is even. If so, return false.
	if (num % 2 == 0) {
		return 0;
	}

	// If num is odd, we can start at 3 and skip all even numbers
	int i;
	for (i = 3; i <= sqrt(num); i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}

	// If we haven't returned 0 yet, the number is prime.
	return 1;
}

// Get the first prime after any given number
long int getNextPrime(long int num) {
	if (num < 2) {
		return 2;
	}

	// Check if num is even. If so, make it odd. If not, go to the next odd number.
	if (num % 2 == 0) {
		num += 1;
	} else {
		num += 2;
	}

	// Check the primality of every odd number after num
	while (isPrime(num == 0)) {
		num += 2;
	}

	return num;
}
