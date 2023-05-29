#include <stdio.h>

#define TOTAL_FUNCS 256

int main()
{

    for(int i = 0; i < TOTAL_FUNCS; i++)
    {
printf("\
.section    .text\n\
.thumb\n\
.thumb_func\n\
.align      2\n\
.global     fill_2cachelines%d\n\
.type       fill_2cachelines%d, %%function\n\
/*----------------------------------------------------------------------------*/\n\
fill_2cachelines%d:\n\
\tFILL_2CACHE_LINES\n\
\n\
.size fill_2cachelines%d, . - fill_2cachelines%d\n\n",i,i,i,i,i);
    }

    for(int i = 0; i < TOTAL_FUNCS; i++)
    {
        printf("extern void fill_2cachelines%d();\n", i);
    }

    for(int i = 0; i < TOTAL_FUNCS; i++)
    {
        printf("functbl[%d] = fill_2cachelines%d;\n", i, i);
    }
}
