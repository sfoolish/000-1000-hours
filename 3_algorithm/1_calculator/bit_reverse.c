#include <stdio.h>

#define DATA 0x1234567 

void bit_print(const unsigned int in)
{
    unsigned int i;

    for (i = 31;i <= 31; i--) {
        printf("%d", (((1<<i) & in) != 0));
        if((i & 0x3) == 0) {
            printf("\t");
        }
    }
    printf("\n");
}

unsigned int bit_reverse_v1(unsigned int n)
{
   n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
   n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
   n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
   n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
   n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);

   return n;
}

unsigned int bit_reverse_v2(unsigned int a)
{
    unsigned int tmp;

    tmp = ((a>>16)&0x0000ffff) | ((a<<16)&0xffff0000);
    a = tmp;
    bit_print(a);
    tmp = ((a>>8)&0x00ff00ff) | ((a<<8)&0xff00ff00);
    a = tmp;
    bit_print(a);
    tmp = ((a>>4)&0x0f0f0f0f) | ((a<<4)&0xf0f0f0f0);
    a = tmp;
    bit_print(a);
    tmp = ((a>>2)&0x33333333) | ((a<<2)&0xcccccccc);
    a = tmp;
    bit_print(a);
    tmp = ((a>>1)&0x55555555) | ((a<<1)&0xaaaaaaaa);
    a = tmp;
    bit_print(a);

    return a;
}

int main()
{
    printf("%x\n", DATA);
    bit_print(DATA);
    printf("%x\n", bit_reverse_v1(DATA));
    printf("%x\n", bit_reverse_v2(DATA));

    return 0;
}
