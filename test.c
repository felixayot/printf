#include "main.h"
#include <stdio.h>
int main()
{
	int count = _printf("Hello %s! Your favorite character is %c. Your average in %% is 140.\n", "Bro", 'S');
	printf("Number of characters printed: %d\n", count);
	return (0);
}
