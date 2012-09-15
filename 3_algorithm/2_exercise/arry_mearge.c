#include <stdio.h>
#include <string.h>

#define ARRY_SIZE 8

int arry_mearge(int *res, int *x, int *y, int size)
{
    int i   = 0;
    int j   = 0;
    int idx = 0;
    
    for ( ; i < size; ++i) {
        for ( ; j < size; ++j) {
            if(x[i] <= y[j]) {
                res[idx] = x[i];
                ++idx;
                break;
            } else {
                res[idx] = y[j];
                ++idx;
            }
        }
    }
    
    for ( ; i < size; ++i) {
        res[idx] = x[i];
        ++idx;
    }
    
    for ( ; j < size; ++j) {
        res[idx] = y[j];
        ++idx;
    }
    
    return 0;
}

int arry_print(int *arr, int size)
{
    int i;

    for (i = 0; i < size; ++i) {
        printf("%4d ", arr[i]);
        if((i & 0x7) == 0x7)
            printf("\n");
    }
    printf("\n");

    return 0;
}

int main()
{
    int x[ARRY_SIZE] = {1, 3, 5, 6, 9, 17, 19, 23};
    int y[ARRY_SIZE];
    int result[2 * ARRY_SIZE];
    int i;

    for (i = 0; i < ARRY_SIZE; ++i) {
        y[i] = x[i] + i;
    }
    memset(result, 0, sizeof(result));
    
    arry_print(x, ARRY_SIZE);
    arry_print(y, ARRY_SIZE);
    arry_print(result, 2 * ARRY_SIZE);
    
    arry_mearge(result, x, y, ARRY_SIZE);
    
    arry_print(x, ARRY_SIZE);
    arry_print(y, ARRY_SIZE);
    arry_print(result, 2 * ARRY_SIZE);
    
    return 0;
}
