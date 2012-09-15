#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TEST_STRING "abcdefgh"

int find(char *str, int len, char ch)
{
    char begin = 0;
    char end = len - 1;
    char mid = (begin + end) /2;

    while (begin <= end) {
        if (*(str + mid) == ch) {
            return mid;
        }

        if (*(str + mid) > ch) {
            end = mid -1;
        } else {
            begin = mid + 1;
        }
        mid = (begin + end) / 2;
    }

    return -1;
}

int main()
{
    char *test = TEST_STRING;
    char len = 10;

    assert(0 == find(test, strlen(test), 'a'));
    assert(2 == find(test, strlen(test), 'c'));
    assert(7 == find(test, strlen(test), 'h'));
    assert(-1 == find(test, strlen(test), 'i'));

    return 0;
}
