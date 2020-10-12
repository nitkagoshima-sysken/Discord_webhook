#include <iostream>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));
	
	/* rand() returns integer */
	std::cout << rand() << std::endl;
	printf("%d\n", rand());
	
	return 0;
}