#include <stdio.h>
#include <stdlib.h>

int factorial(unsigned int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(int argc, char** argv) {
	int n = atoi(argv[argc-1]);
	printf("Factorial of %d is %d\n", n, factorial(n));
	return 0;
}
