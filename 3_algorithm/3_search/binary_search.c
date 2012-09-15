#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TEST_STRING "abcdefgh"

char* sf_strchr(char *str, char ch)
{
    int begin = 0;
    int end = strlen(str) - 1;
    int mid = (begin + end) /2;

    while (begin <= end) {
        if (*(str + mid) == ch) {
            return (str + mid);
        }

        if (*(str + mid) > ch) {
            end = mid -1;
        } else {
            begin = mid + 1;
        }
        mid = (begin + end) / 2;
    }

    return NULL;
}

int main()
{
    char *test = TEST_STRING;
    char *ret = NULL;

    ret = sf_strchr(test, 'a');
    assert('a' == *ret);
    ret = sf_strchr(test, 'b');
    assert('b' == *ret);
    ret = sf_strchr(test, 'h');
    assert('h' == *ret);
    ret = sf_strchr(test, 'i');
    assert(NULL == ret);

    return 0;
}
