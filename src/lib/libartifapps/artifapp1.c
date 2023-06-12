#include "tpa_prof.h"

#define IT 10
#define N_INSTR 10

#define REPEAT_MOV_R0(count)                        \
    do {                                            \
        asm volatile ("mov r0, r0");                \
        if ((count) > 1) {                          \
            for (int i = 1; i < (count); i++) {     \
                asm volatile ("mov r0, r0");        \
            }                                       \
        }                                           \
    } while (0)

void initialise_benchmark (void)
{
    return;
}

int verify_benchmark (int res)
{
    return 1;
}

static inline void func0(void)
{
    #ifdef TPA_PROF
    tpa_sample_mbb(0);
    #else
    #endif

    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func1(void)
{
    #ifdef TPA_PROF
    tpa_sample_mbb(1);
    #else
    #endif

    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func2(void)
{
    #ifdef TPA_PROF
    tpa_sample_mbb(2);
    #else
    #endif

    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func3(void)
{
    #ifdef TPA_PROF
    tpa_sample_mbb(3);
    #else
    #endif

    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func4(void)
{
    #ifdef TPA_PROF
    tpa_sample_mbb(4);
    #else
    #endif

    /* some code */
    REPEAT_MOV_R0(N_INSTR);

    /* callback to func2 */
    func2();
}

int __attribute__((noinline))
benchmark_body(int rpt)
{
    func0();
    func1();
    func2();

    for(int i = 0; i < IT; i++)
    {
        func4();
    }

    func3();
    return 0;
}