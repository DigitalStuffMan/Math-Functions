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

// Get the next prime given a prime number
long int getNextPrime(long int currentPrime) {
	if (currentPrime < 2) {
		return 2;
	} else if (currentPrime == 2) {
		return 3;
	}

	if (isPrime(currentPrime) == 0) {
		return '\0';
	}

	long int nextPrime = currentPrime + 2;
	int prime = 0;

	while (prime == 0) {
		if (isPrime(nextPrime) == 0) {
			nextPrime += 2;
			continue;
		} else {
			prime = 1;
		}
	}
	return nextPrime;
}
