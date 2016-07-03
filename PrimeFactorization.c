#include <stdlib.h>
#include <string.h>
#include "PrimeFactorization.h"
#include "PrimalityTest.h"

char* primeFactorization(long int num) {
	// Check if input is already prime.
	// If so, return the input num.
	if (isPrime(num) == 1) {
		return toString(num);
	}

	// Allocate spcae for the list
	char* list = (char*)malloc(sizeof(char));
	long int base = 2;
	long int power = 0;

	// Set final spot to NULL
	list[0] = '\0';

	while (num != 1) {
		while (num % base == 0) {
			num /= base;
			power++;
		}

		if (power != 0) {
			list = addToList(list, base, power);

			// Check if the new num is prime.
			// If so, add it to the list and break.
			if (num != 1 && isPrime(num) == 1) {
				list = addToList(list, num, 1);
				break;
			}
			power = 0;
		}
		base = getNextPrime(base);
	}
	return list;
}

char* toString(long int num) {
	// Get Number of digits
	int len = 1;
	long int newNum = num;

	while (newNum / 10 != 0) {
		newNum /= 10;
		len++;
	}

	// Allocate space for the new string
	char *ret = (char*)malloc(sizeof(char) * len + 1);

	// Set last spot to NULL
	ret[len] = '\0';

	// Place each digit in the new string
	int i;
	for (i = len - 1; i >= 0; i--) {
		ret[i] = ((num % 10) + '0');
		num /= 10;
	}
	return ret;
}

char* addToList(char* list, long int base, long int power) {
	// Get all the lengths
	int currentLen = strlen(list);
	char* baseStr = toString(base);
	char* powerStr = toString(power);
	int newLen = currentLen + strlen(baseStr) + strlen(powerStr);

	char* newList;
	// Reallocate the memory
	if (currentLen == 0) {
		newList = (char*)realloc(list, sizeof(char) * newLen + 2);
		strcat(newList,baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	} else {
		newList = (char*)realloc(list, sizeof(char) * newLen + 5);
		strcat(newList, " * ");
		strcat(newList, baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	}
	free(baseStr);
	free(powerStr);
	baseStr = NULL;
	powerStr = NULL;
	return newList;
}
