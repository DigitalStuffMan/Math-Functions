#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "MathFunctions.h"
#include "PrimalityTest.h"

int main(int argc, char *argv[]) {

	// Create our variables, including a temp one for clearing the input buffer
	long int input = '\0';
	int result = '\0';

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
			if ((input = retrieveInput()) == '\0' || input > 6 || input < 1) {
				printf("\nError parsing response, please try again.\n");
			}
		} while (input == '\0' || input > 6 || input < 1);

		// Primality Test
		if (input == 1) {

			do {
				printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
					"Primality Test:\n"
					"Enter a Number to Test the Primality Of: ");
				// Get the input and loop if invalid
				if ((input = retrieveInput()) == '\0') {
					printf("\nError parsing response, please try again.");
				}
			} while (input == '\0');

			if ((result = isPrime(input)) == 0) {
				printf("The Number IS NOT Prime.\n");
			} else if (result == 1) {
				printf("The Number IS Prime.\n");
			}
	
		// Prime Factorization
		} else if (input == 2) {
			printf("2\n");
			return 0;
		// Nth Number in Fibonacci Sequence
		} else if (input == 3) {
			printf("3\n");
			return 0;
		// Convert from any Base to any Base
		} else if (input == 4) {
			printf("4\n");
			return 0;
		// Greatest Common Divisor
		} else if (input == 5) {
			printf("5\n");
			return 0;
		// Exit
		} else {
			return 0;
		}

		// On loop, print a line and reset variables
		input = '\0';
		result = '\0';
		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
	}	
}

/* All input in the program will be with whole numbers, so we will
 * only return long ints from this function. */
long int retrieveInput() {
	const int MAX_LEN = 21;
	char input[MAX_LEN];
	char c = '\0';
	int len = 0;
	
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

	// If nothing was parsed, exit here with a NULL character
	if (len == 0) {
		return '\0';
	}

	// Convert the string of numbers to a long int
	long int ret;
	errno = 0;
	ret = strtol(input, NULL, 10);

	// If the input number was too large or too small for a long int, return a NULL character
	if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
		return '\0';
	}

	return ret;
}
