#include <stdio.h>

int main(void)
{
	int i;

	printf("Infinite loop incoming :(\n");

	i = 0;

	while (i < 10)
	{
		putchar(i + '0'); // Add '0' to convert the integer to its corresponding ASCII character
		i++; // Increment i by 1 in each iteration
	}
				  
	printf("Infinite loop avoided! \\o/\n");
				  

	 return 0;

}				   
