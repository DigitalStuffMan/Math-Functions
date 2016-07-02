goal: MathFunctions

MathFunctions: MathFunctions.c PrimalityTest.c
	gcc -g -Wall -Werror -lm -o MathFunctions MathFunctions.c PrimalityTest.c

clean:
	rm -f MathFunctions *.out
