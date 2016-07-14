#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "MathFunctions.h"
#include "PrimalityTest.h"
#include "PrimeFactorization.h"
#include "Fibonacci.h"
#include "BaseConversion.h"

int main(int argc, char *argv[]) {

	// Create input variables
	long int numericInput = '\0';
	int baseFrom = '\0';
	int baseTo = '\0';
	char *alphanumericInput = NULL;

	// Create result variables
	int boolResult = '\0';
	unsigned long int unsignedLResult = '\0';
	char *strResult = NULL;

	// Create success pointer
	// This is used to find out if errors occured
	int *success = (int*)malloc(sizeof(int));
	*success = '\0';

	// Create other variables
	int lastDigit = '\0';
	char *ordinalIndicator = NULL;

	while (1) {
		// Display the options at least once. Display again if needed
		do {
			printf("Select one of the following options to continue (1 - 6):\n"
					"1.) Primality Test\n"
					"2.) Prime Factorization\n"
					"3.) Nth Term in Fibonacci Sequence\n"
					"4.) Convert a Number from any Base to any Base\n"
					"5.) Greatest Common Divisor\n"
					"6.) Exit\n"
					"Your Selection: ");

			// Get the input and check if the value is within the range of options.
			numericInput = retrieveNumericInput(success);
			if (*success != 1 || numericInput > 6 || numericInput < 1) {
				printf("\nError parsing response, please try again.\n");
			}
		} while (*success != 1 || numericInput > 6 || numericInput < 1);

		switch (numericInput) {
			// Primality Test
			case 1:

				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Primality Test:\n"
							"Enter a Number to Test the Primality Of: ");

					// Get the input and loop if invalid
					numericInput = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.");
					}
				} while (*success != 1);

				if ((boolResult = isPrime(numericInput)) == 0) {
					printf("The Number IS NOT Prime.\n");
				} else if (boolResult == 1) {
					printf("The Number IS Prime.\n");
				}

				// Reset used variables
				*success = '\0';
				boolResult = '\0';
				numericInput = '\0';
				break;

				// Prime Factorization
			case 2:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Prime Factorization:\n"
							"Enter a Number to take the Prime Factorization Of: ");

					// Get the input and loop if invalid
					numericInput = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						// Now get the Prime Factorization
						strResult = primeFactorization(numericInput, success);
						if (strResult == NULL && *success == -1) {
							printf("\nError: Please Enter a Number Greater Than 1.\n");
						}
					}
				} while (*success != 1);

				printf("The Prime Factorization of %ld is:\n"
						"%s\n", numericInput, strResult);

				// Free the memory and reset used variables
				free(strResult);
				strResult = NULL;

				*success ='\0';
				numericInput = '\0';
				break;

				// Nth Term in Fibonacci Sequence
			case 3:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Nth Term in Fibonacci Sequence:\n"
							"Enter the Term of the Fibonacci Sequence You Want: ");

					// Get the input and loop if invalid
					numericInput = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						// Now get the Term
						unsignedLResult = nthFibonacciTerm(numericInput, success);
						if (*success == -1) {
							printf("\nError: Please Enter a Non-Negative Number.\n");
						} else if (*success == 0 && unsignedLResult == ULONG_MAX) {
							printf("\nError: Number Too Big. Please Enter a Smaller Term.\n");
						}
					}
				} while (*success != 1);

				// Get the ordinal indicator
				lastDigit = numericInput % 10;
				if (lastDigit == 1) {
					ordinalIndicator = "st";
				} else if (lastDigit == 2) {
					ordinalIndicator = "nd";
				} else if (lastDigit == 3) {
					ordinalIndicator = "rd";
				} else {
					ordinalIndicator = "th";
				}

				printf("The %ld%s Term of the Fibonacci Sequence is:\n"
						"%lu\n", numericInput, ordinalIndicator, unsignedLResult);

				// Reset used variables
				*success = '\0';
				numericInput = '\0';
				unsignedLResult = '\0';
				lastDigit = '\0';
				ordinalIndicator = NULL;
				break;

				// Convert from any Base to any Base
			case 4:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Convert a Number From Any Base to Any Base:\n"
							"Enter the Base to Convert From: ");

					// Get the baseFrom input
					baseFrom = retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					} else if (baseFrom < 2 || baseFrom > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
					}

					// Get the number to convert
					printf("Now Enter the Number to Convert: ");
					alphanumericInput = retrieveAlphanumericInput(success, baseFrom);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					}

					// Get the baseTo input
					printf("Now Enter the Base to Convert To: ");
					baseTo = retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					} else if (baseTo < 2 || baseTo > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
					}

					strResult = baseConversion(baseFrom, baseTo, alphanumericInput, success);
					if (*success != 1) {
						printf("\nError Converting Number. Please try again.\n");
						continue;
					}
				} while (*success != 1);

				printf("\nThe Base %d Number %s in Base %d is:\n"
						"%s", baseFrom, alphanumericInput, baseTo, strResult);

				// Reset used variables
				*success = '\0';
				baseFrom = '\0';
				free(alphanumericInput);
				alphanumericInput = NULL;
				baseTo = '\0';
				free(strResult);
				strResult = NULL;
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

				// If we get here, something went wrong
			default:
				free(success);
				success = NULL;
				return 1;
		}

		// On loop, print a line
		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
	}	
}

// Retrieve the input and convert it to a long int
// All numeric input is in base 10
long int retrieveNumericInput(int* success) {
	// Create a space to hold the input
	char *input = NULL;
	char *endptr = NULL;
	retrieveInput(&input, success, 10);

	if (input == NULL || *success != 1) {
		*success = 0;
		return '\0';
	}

	// Convert the input to  a long int
	long int ret = '\0';
	errno = 0;
	ret = strtol(input, &endptr, 10);

	// Free the char array
	free(input);
	input = NULL;

	// Check if a conversion happened If not, return an error
	if (input == endptr) {
		*success = 0;
		return '\0';
	}

	// If the input number was too large or too small for the long int, return an error
	if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
		*success = 0;
		return '\0';
	}

	// Return the long int with a success
	*success = 1;
	return ret;
}

// Retrieve the input and keep it alphanumeric
char* retrieveAlphanumericInput(int* success, int base) {
	char *input = NULL;
	retrieveInput(&input, success, base);

	// Verify the input was successfully retrieved
	if (input == NULL || *success != 1) {
		*success = 0;
		return NULL;
	}

	// Return with a success
	*success = 1;
	return input;

}

// Retrieve the user input
void retrieveInput(char** input, int* success, int base) {
	// Make sure the input is valid
	if (input == NULL || success == NULL || (base < 2 || base > 36)) {
		return;
	} else {
		*success = '\0';
	}

	// Allocate space for the input
	int size = 128;
	*input = (char*)malloc(sizeof(char) * size);

	// Initialzie the array by setting the last space to NULL
	(*input)[size - 1] = '\0';

	// Verify space was allocated
	if (*input == NULL) {
		*success = 0;
		return;
	}

	char* newInput = NULL;
	char maxChar = '\0';
	char c = '\0';
	int len = 0;

	// Find the highest char the user can input
	if (base <= 10) {
		maxChar = base + '0' - 1;
	} else {
		maxChar = 'A' + (base - 11);
	}

	do {
		// Get the next character in the input and convert it to uppercase (if possible)
		c = getchar();
		c = toupper(c);

		// If c is a space character, just skip it
		if (isspace(c)) {
			continue;
		}

		// Verify the input. If invalid, clean up everything and return.
		if ((!isalnum(c) && (c != '-' && c != '+')) || ((c == '-' || c == '+') && len != 0) || c > maxChar) {
			free(*input);
			*input = NULL;
			*success = 0;
			while ((c = getchar()) != '\n' && c != EOF);
			return;
		}

		// Check if the input array needs to be extended. If so, expand it.
		if (len == (size - 1)) {
			size += 64;

			newInput = (char*)realloc(*input, sizeof(char) * size);

			// Verify reallocation worked
			if (newInput == NULL) {
				*success = 0;
				free(*input);
				*input = NULL;
				return;
			} else {
				*input = newInput;
				newInput = NULL;
			}
		}

		// Check if the sign is given. If not, default to positve
		if (len == 0) {
			if (c != '-' && c != '+') {
				(*input)[len] = '+';
				len++;
			}
		}

		// Finally, add the new character to the array
		(*input)[len] = c;
		len++;

	} while (c != '\n' && c != EOF);

	// If nothing was parsed, exit here with an error
	if (len == 0) {
		free(*input);
		*input = NULL;
		*success = 0;
		return;
	}

	// Get rid of all the excess space in the array
	newInput = (char*)realloc(*input, sizeof(char) * len + 1);

	// Verify reallocation worked
	if (newInput == NULL) {
		*success = 0;
		free(*input);
		*input = NULL;
		return;
	} else {
		*input = newInput;
		newInput = NULL;
	}

	// Make sure the last space is NULL
	*success = 1;
	(*input)[len] = '\0';
}
