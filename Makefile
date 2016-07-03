goal: MathFunctions

MathFunctions: MathFunctions.c PrimalityTest.c PrimeFactorization.c
	gcc -g -Wall -Werror -lm -o MathFunctions MathFunctions.c PrimalityTest.c PrimeFactorization.c

clean:
	rm -f MathFunctions *.out
