#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "MathFunctions.h"
#include "PrimalityTest.h"
#include "PrimeFactorization.h"
#include "Fibonacci.h"

int main(int argc, char *argv[]) {

	// Create input variable
	long int input = '\0';

	// Create result variables
	int boolResult = '\0';
	unsigned long int unsignedLResult = '\0';
	char* strResult = NULL;

	// Create success pointer
	// This is used to find out if errors occured
	int *success = (int*)malloc(sizeof(int));
	*success = '\0';

	while (1) {
		// Display the options at least once. Display again if needed
		do {
			printf("Select one of the following options to continue (1 - 6):\n"
					"1.) Primality Test\n"
					"2.) Prime Factorization\n"
					"3.) Nth Number in Fibonacci Sequence\n"
					"4.) Convert a Number from any Base to any Base\n"
					"5.) Greatest Common Divisor\n"
					"6.) Exit\n"
					"Your Selection: ");

			// Get the input and check if the value is within the range of options.
			if (((input = retrieveInput(success)) == '\0' && *success == 0) || input > 6 || input < 1) {
				printf("\nError parsing response, please try again.\n");
			}
		} while ((input == '\0' && *success == 0) || input > 6 || input < 1);

		// Primality Test
		switch (input) {
			case 1:

				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Primality Test:\n"
							"Enter a Number to Test the Primality Of: ");
					// Get the input and loop if invalid
					if ((input = retrieveInput(success)) == '\0' && *success == 0) {
						printf("\nError parsing response, please try again.");
					}
				} while ((input == '\0' && *success == 0));

				if ((boolResult = isPrime(input)) == 0) {
					printf("The Number IS NOT Prime.\n");
				} else if (boolResult == 1) {
					printf("The Number IS Prime.\n");
				}
				break;
				// Prime Factorization
			case 2:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Prime Factorization:\n"
							"Enter a Number to take the Prime Factorization Of: ");
					// Get the input and loop if invalid
					if ((input = retrieveInput(success)) == '\0' && *success == 0) {
						printf("\nError parsing response, please try again.");
					} else {
						if ((strResult = primeFactorization(input, success)) == NULL && *success == -1) {
							printf("\nError: Please Enter a Number Greater Than 1.\n");
						}
					}
				} while ((input == '\0' || strResult == NULL) && (*success == 0 || *success == -1));
				printf("The Prime Factorization of %ld is:\n"
						"%s\n", input, strResult);
				free(strResult);
				strResult = NULL;
				break;
				// Nth Number in Fibonacci Sequence
			case 3:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Nth Number in Fibonacci Sequence:\n"
							"Enter the Term of the Fibonacci Sequence You Want: ");
					// Get the input and loop if invalid
					if ((input = retrieveInput(success)) == '\0' && *success == 0) {
						printf("\nError parsing response, please try again.");
					} else {
						if ((unsignedLResult = nthFibonacciTerm(input, success)) == '\0' && *success == -1) {
							printf("\nError: Please Enter a Non-Negative Number.\n");
						} else if (unsignedLResult == ULONG_MAX && *success == 0) {
							printf("\nError: Number Too Big. Please Enter a Smaller Term.\n");
						}
					}
				} while ((input == '\0' || unsignedLResult == '\0' || unsignedLResult == ULONG_MAX) && (*success == 0 || *success == -1));

				printf("The %ld Term of the Fibonacci Sequence is:\n"
						"%lu\n", input, unsignedLResult);
				break;
				// Convert from any Base to any Base
			case 4:
				printf("4\n");
				break;
				// Greatest Common Divisor
			case 5:
				printf("5\n");
				break;
				// Exit
			case 6:
				free(success);
				success = NULL;
				return 0;
				break;
				// Something is wrong
			default:
				free(success);
				success = NULL;
				return 1;
		}
		// On loop, print a line and reset variables
		input = '\0';
		boolResult = '\0';
		unsignedLResult = '\0';
		*success = '\0';
		strResult = NULL;
		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
	}	
}

/* All input in the program will be with whole numbers, so we will
 * only return long ints from this function. */
long int retrieveInput(int* success) {
	const int MAX_LEN = 21;
	char input[MAX_LEN];
	char c = '\0';
	int len = 0;

	// Make sure the success pointer is valid
	if (success == NULL) {
		return '\0';
	} else {
		*success = '\0';
	}

	// Make sure last spot has the terminating NULL
	input[MAX_LEN - 1] = '\0';

	do {
		// Don't bother getting the character if the length has been exceeded
		if (len < MAX_LEN) {
			c = getchar();
		}

		// Check for valid / invalid input
		if (len >= MAX_LEN || ((c < '0' || c > '9') && (c != '\n' && c != EOF))) {
			if (len == 0 && c == '-') {
				input[len] = c;
				len++;
				continue;
			} else if (len == 0 && c == '+') {
				input[len] = c;
				len++;
				continue;
			} else {
				while ((c = getchar()) != '\n' && c != EOF);
				*success = 0;
				return '\0';
			}
		}

		if ((c >= '0' && c <= '9')) {
			if (len == 0) {
				input[len] = '+';
				len++;
			}
			input[len] = c;
			len++;
		}
	} while (c != '\n' && c != EOF);

	// If nothing was parsed, exit here with an error
	if (len == 0) {
		*success = 0;
		return '\0';
	}

	// Set all remaining spaces to NULL
	int i;
	for (i = len; i < MAX_LEN; i++) {
		input[i] = '\0';
	}

	// Convert the string of numbers to a long int
	long int ret = '\0';
	errno = 0;
	ret = strtol(input, NULL, 10);

	// If the input number was too large or too small for a long int, return an error
	if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
		*success = 0;
		return '\0';
	}

	*success = 1;
	return ret;
}
