#include <stdio.h>
#define LEN 20
char find(char N, char *a, char len)
{
	char begin = 0;
	char end = len - 1;
	char mid = (begin + end) /2;
	while(begin < end)
	{
		if(*(a + mid) == N)
		{
			return '1';
		}
		else
		{
			if(*(a + mid) > N)
			{
				end = mid -1;
			}
			else
			{
				begin = mid + 1;
			}
		mid = (begin + end) / 2;
		}
	}
	return '0';
}

int main()
{
	char test[LEN] = "adsb3873905";
	char len = 10;
	printf("%c\n",find('c', test, len));
	return 0;
}
