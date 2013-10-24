// man backtrace(3)
// test on osx 10.6
#include <execinfo.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define STACK_SIZE 128
#define FILE_NAME "backtrace_dump.txt"
#define DIV_LINE "------------------------------\n"

int backtrace_dump()
{
    void *callstack[STACK_SIZE];
    int i;
    int frames = backtrace(callstack, STACK_SIZE);
    char **strs = backtrace_symbols(callstack, frames);

    for (i = 0; i < frames; ++i) {
        printf("%s\n", strs[i]);
    }

    free(strs);
}

int backtrace_dump_fd(int fd)
{
    void *callstack[STACK_SIZE];
    int frames = -1;

    if (fd < 0) {
        return -1;
    }

    frames = backtrace(callstack, STACK_SIZE);
    backtrace_symbols_fd(callstack, frames, fd);

    return 0;
}

int backtrace_dump_file()
{
    int fd = -1;

    fd = open(FILE_NAME, O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd < 0) {
        return -1;
    }

    write(fd, DIV_LINE, strlen(DIV_LINE));
    backtrace_dump_fd(fd);

    close(fd);
}

int func1()
{
    backtrace_dump();
    backtrace_dump_file();
}

int main()
{
    func1();

    return 0;
}
