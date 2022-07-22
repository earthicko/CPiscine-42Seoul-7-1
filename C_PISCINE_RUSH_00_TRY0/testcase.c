#include <stdio.h>
void rush(int x, int y);
int main()
{
	for (int width = -5; width <= 5; width++)
	{
		for (int height = -5; height <= 5; height++)
		{
			printf("(%d, %d):\n", width, height);
			fflush(stdout);
			rush(width, height);
		}
	}
	return 0;
}
