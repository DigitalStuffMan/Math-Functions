goal: math_functions

math_functions: math_functions.c
	gcc -g -Wall -Werror -o math_functions math_functions.c

clean:
	rm -f math_functions *.out
