#include "function.h"

unsigned long long Number(unsigned long long q_)
{
	int count = 0;

	unsigned long long i = 2;

	while (i < q_)
	{

		if (q_ % i == 0)
		{
			++count;

			if (count > 0)
				break;
		}
		++i;
	}
	return count;
}
