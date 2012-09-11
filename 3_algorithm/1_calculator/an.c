//计算整数a的N次幂的三种算法
//TODO 怎样用实验比较三种算法的计算复杂度

#include <stdio.h>
#define MAX_N 32 
int powmanli(const int a, const int n);
int powyouhua(const int a, const int n);
int pow_space_time(const int a, const int n);

int main()
{
	printf("%d\n", powmanli(2, 20));
	printf("%d\n", pow_space_time(2, 20));
	printf("%d\n", powyouhua(2, 20));

	return 0;
}

int powmanli(const int a, const int n)
{
	//printf("this is powmanli\n"); 刚开始方这里
	if (1==n)
	{	//在用中文输入注释的时候在这里用了中文｛｝
		printf("this is powmanli\n");	
		return a;
	}
	else 
		return a*powmanli(a, n-1);
}

int pow_space_time(const int a, const int n)
{
	/*又是段错误没初始化这个i。
	*平时用惯for循环了改用while后
	*老出现这种低级错误
	*/
	int i = 0;
	int tmp_n[MAX_N];
	tmp_n[0] = a;
	printf("this is pow_space_time\n");
	while(++i < n)
	{
		/*开始这里没乘a，真是什么样的错误都可能发生阿。
		*虽然感觉有点郁闷，但是还是能够感到实实在在，
		*心里踏实阿
		*/
		tmp_n[i] = a * tmp_n[i - 1];
	}
	return tmp_n[i - 1];//刚开是这里return的是 tmp_n[i]
}

int powyouhua(const int a, const int n)
{
	/* printf("1") 这样写gdb调试的时候
	*1不能输出更长的字符串也不行
	*/
	printf("this is powyouhua\n");
	int i = 0;
	int j = 1;
	int bin_n[MAX_N];//n --> MAX_N 用n segmantation fault
	int an[MAX_N];
	int sum = 1;	//sum 未初始化
	int m = n;
	an[0] = a;
	
	while (m > 0)
	{	
		bin_n[i] = m % 2;
		m = m/2;
		//printf("%d__%d\n", i, bin_n[i]);
		i++;
	}
	while (j < i)
	{
		an[j] = an[j-1] * an[j-1];//an[j] = an[j-1]
		//printf("%d__%d\n", j, an[j]);
		j++;//没写成了死循环。诶。。。
	}
	while (--i >= 0)//i处理错误程序访问到数组外，及数组中未初始化的部分
	{
		if (bin_n[i] == 1)	
		//if (bin_n[i] != 0)刚开始用这个
		{
			sum *= an[i];
			//printf("%d\n", sum);
		}
		//printf("%d\n", i);
	}
	return sum;
}
