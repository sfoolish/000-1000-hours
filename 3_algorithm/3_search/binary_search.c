#include <stdio.h>
#include <string.h>

#define TEST_STRING "abcdefgh"

char find(char *str, int len, char ch)
{
    char begin = 0;
    char end = len - 1;
    char mid = (begin + end) /2;

    while (begin <= end) {
        if (*(str + mid) == ch) {
            return '1';
        }
        printf("%c %d %d %d %d\n", *(str + mid), len, mid, begin, end);

        if (*(str + mid) > ch) {
            end = mid -1;
        } else {
            begin = mid + 1;
        }
        mid = (begin + end) / 2;
    }

    return '0';
}

int main()
{
    char *test = TEST_STRING;
    char len = 10;

    printf("%c\n",find(test, strlen(test), 'a'));
    
    return 0;
}
