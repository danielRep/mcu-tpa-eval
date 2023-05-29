#include <sys/stat.h>

void _exit(int status)
{
    __asm("BKPT #0");
    while (1)
        ;
}

int _close(int fd)
{
    return -1;
}

int _lseek(int file, int offset, int whence)
{
    return 0;
}

void _kill(int pid, int sig)
{
    return;
}

int _getpid(void)
{
    return -1;
}

void *_sbrk(int incr)
{
    extern char end[];
    extern char __HeapLimit[];
    static char *_heap_ptr = end;

    if ((_heap_ptr + incr < end) || (_heap_ptr + incr > __HeapLimit))
        return (void *)-1;

    _heap_ptr += incr;

    return _heap_ptr - incr;
}

int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file)
{
    return 1;
}