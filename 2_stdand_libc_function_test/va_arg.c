#include <stdio.h>
#include <stdarg.h>
int max(int n, ...)
{
	int i;
	va_list ap;
	va_start(ap, n);
	int max = -0x7fffffff;
	int tmp;
	for(i = 0; i < n; i++)
	{
		tmp = va_arg(ap, int);
		if(tmp > max)
		{
			max = tmp;
		}
	}
	va_end(ap);
	return max;
}

int main()
{
	printf("The max value of max() is %d\n", max(3, 10, 20,
	46));
	return 0;
}
