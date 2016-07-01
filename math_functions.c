#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	// Create our variables, including a temp one for clearing the input buffer
	char input = '\0';
	int loop = 0;
	char temp;


	// Display the options at least once. Display again if needed
	do {
		printf("Select one of the following options to continue (1 - 4): \n"
			"1.) Primality Test\n"
			"2.) Prime Factorization\n"
			"3.) Nth Number in Fibonacci Sequence\n"
			"4.) Exit\n"
			"Your Selection: ");

		// Wait until we get input that is a non-space or null character
		do {
			input = getchar();
		} while (input == '\0' || input == '\n' || input == '\r' || input == '\t' || input == ' ');
		
		// Extract the value of the character
		input = input - '0';

		/* Check if the value is within the range of options.
		 * If not, make sure we loop and clear the input buffer.
		 */
		if (input > 4 || input < 1) {
			loop = 1;
			printf("\nError parsing response, please try again.\n");
			while ((temp = getchar()) != '\n' && temp != EOF) { }
		} else {
			loop = 0;
		}
	} while (loop);

	// Primality Test
	if (input == 1) {
		printf("1\n");
		return 0;
	// Prime Factorization
	} else if (input == 2) {
		printf("2\n");
		return 0;
	// Nth Number in Fibonacci Sequence
	} else if (input == 3) {
		printf("3\n");
		return 0;
	// Exit
	} else {
		return 0;
	}
}
