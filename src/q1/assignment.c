#include <stdio.h>

int main()
{
	int a = 1;
	int* b = &a;
	long c = 10101010l;
	double d1 = 1.1;
	double* d2 = &d1;
	char ch1 = 'a';
	char* ch2 = &ch1;
	char** ch3 = &ch2;

	printf("%d\n%d\n%d\n%d\n%d", sizeof(a), sizeof(b), sizeof(c), sizeof(d2), sizeof(ch3));
}
