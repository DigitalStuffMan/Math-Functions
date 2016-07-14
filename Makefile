goal: MathFunctions

MathFunctions: MathFunctions.c PrimalityTest.c PrimeFactorization.c Fibonacci.c BaseConversion.c
	gcc -g -Wall -Werror -lm -o MathFunctions MathFunctions.c PrimalityTest.c PrimeFactorization.c Fibonacci.c BaseConversion.c

clean:
	rm -f MathFunctions *.out
