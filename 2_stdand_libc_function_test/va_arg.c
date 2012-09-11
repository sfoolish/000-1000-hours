#include <stdio.h>
#include <stdarg.h>

int get_max_args(int n, ...)
{
    int i;
    int max = -0x7fffffff;
    int tmp;
    va_list ap;

    va_start(ap, n);

    for (i = 0; i < n; i++) {
        tmp = va_arg(ap, int);
        if (tmp > max) {
            max = tmp;
        }
    }

    va_end(ap);

    return max;
}

int main()
{
    int ret = 0;

    ret = get_max_args(3, 10, 20, 46);
    printf("The max value of max() is %d\n", ret);

    return 0;
}
