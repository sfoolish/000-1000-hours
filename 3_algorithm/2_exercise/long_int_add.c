#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

void print(int *arr)
{
    int i;

    for(i = *arr; i > 0; i--) {
        printf("%d", *(arr + i));
    }
    printf("\n");
}

void ch_con_in(char *ch, int *in)
{
    char *tem;
    int  i;

    tem = ch;
    i = strlen(ch);
    *in = i;
    while (*tem != '\0') {
        *(in + i) = *tem++ - '0';
        i--;
    }
}

void lon_add(int *a, int *b, int *sum)
{
    int min;
    int tem;
    int i;

    min = *a <= *b ? *a : *b;
    *(sum + 1) = 0;
    for (i = 1; i <= min; i++) {
        tem = *(a + i) + *(b + i) + *(sum + i);
        if (tem >= 10) {
            *(sum + i) = tem - 10;
            *(sum + i + 1) = 1;
        } else {
            *(sum + i) = tem;
            *(sum + i + 1) = 0;
        }
    }
    if (*a != min) {
        for (i = min +1; i <= *a; i++) {
            tem = *(a + i) + *(sum + i);
            if (tem >= 10) {
                *(sum + i) = tem - 10;
                *(sum + i + 1) = 1;
            } else {
                *(sum + i) = tem;
                *(sum + i + 1) = 0;
            }
        }
        if(*(sum + *a + 1) == 0)
            *sum = *a;
        else
            *sum = *a + 1;
    } else {
        for (i = min +1; i <= *b; i++) {
            tem = *(b + i) + *(sum + i);
            if (tem >= 10) {
                *(sum + i) = tem - 10;
                *(sum + i + 1) = 1;
            } else {
                *(sum + i) = tem;
                *(sum + i + 1) = 0;
            }
        }
        if(*(sum + *b + 1) == 0)
            *sum = *b;
        else
            *sum = *b + 1;
    }
}

int main()
{
    char ca[MAX_LEN] = "123456";
    char cb[MAX_LEN] = "655757887879";
    int  ia[MAX_LEN];
    int  ib[MAX_LEN];
    int  ic[MAX_LEN + 1];

    ch_con_in(ca, ia);
    ch_con_in(cb, ib);
    lon_add(ia, ib, ic);
    print(ia);
    print(ib);
    print(ic);
    
    return 0;
}

