#include <stdio.h>

int main() {
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p = a;

	printf("a[2] = %d\n", *(p + 2)); // Add this line
					 
	return 0;
}
