//#include "solution.h"
//#include <string.h>
//#include <stddef.h>

int stringStat(const char *string, int multiplier, int *count)
{
	int len = strlen(string);
	*count = (*count) + 1;
	return len * multiplier;
}

