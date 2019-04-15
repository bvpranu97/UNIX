#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int a)
{
	printf("Caught floating point error. Signal Number: %d\n", a);
	exit(0);
}

int main(void)
{
	int a,b;

	signal(SIGFPE,signal_handler);
	printf("Enter a number: \n");
	scanf("%d", &a);
	b = 0;
	a = a/b;

	printf("This line will not be printed\n");
	return 0;
}
