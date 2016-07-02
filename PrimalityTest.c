#include <stdlib.h>
#include <math.h>
#include "PrimalityTest.h"

// This is the simple trial division test
int isPrime(long num) {
	if (num < 1) {
		return 0;
	} else if (num <= 3) {
		return 1;
	}

	int i;
	for (i = 2; i < sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	// If we haven't returned 0 yet, the number is prime.
	return 1;
}
