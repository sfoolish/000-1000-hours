#include <stdio.h>

#define MAX_N 32 

int powmanli(const int a, const int n)
{
    return ((1 != n) ? (a * powmanli(a, n-1)) : a);
}

int pow_space_time(const int a, const int n)
{
    int i = 0;
    int tmp_n[MAX_N];

    tmp_n[0] = a;
    while(++i < n)
    {
        tmp_n[i] = a * tmp_n[i - 1];
    }

    return tmp_n[i - 1];
}

int powyouhua(const int a, const int n)
{
    int i = 0;
    int j = 1;
    int bin_n[MAX_N];
    int an[MAX_N];
    int sum = 1;
    int m = n;
    an[0] = a;
    
    while (m > 0) {   
        bin_n[i] = m % 2;
        m = m/2;
        i++;
    }
    while (j < i) {
        an[j] = an[j-1] * an[j-1];
        j++;
    }
    while (--i >= 0) {
        if (bin_n[i] == 1) {
            sum *= an[i];
        }
    }

    return sum;
}

int main()
{
    printf("powmanli(2, 20) = %d\n", powmanli(2, 20));
    printf("pow_space_time(2, 20) = %d\n", pow_space_time(2, 20));
    printf("powyouhua(2, 20) = %d\n", powyouhua(2, 20));

    return 0;
}
