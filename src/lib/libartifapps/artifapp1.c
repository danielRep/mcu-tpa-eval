#define IT 10
#define N_INSTR 500

#define REPEAT_MOV_R0(count) \
    do { \
        asm volatile ("mov r0, r0"); \
        if ((count) > 1) { \
            for (int i = 1; i < (count); i++) { \
                asm volatile ("mov r0, r0"); \
            } \
        } \
    } while (0)

void initialise_benchmark (void)
{
    return;
}

int verify_benchmark (int res)
{
    return 1;
}

static inline void func1(void)
{
    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func2(void)
{
    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func3(void)
{
    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func4(void)
{
    /* some code */
    REPEAT_MOV_R0(N_INSTR);
}

static inline void func5(void)
{
    /* some code */
    REPEAT_MOV_R0(N_INSTR);

    /* callback to func3 */
    func3();
}

int __attribute__((noinline))
benchmark_body(int rpt)
{
    func1();
    func2();
    func3();

    for(int i = 0; i < IT; i++)
    {
        func5();
    }

    func4();
    return 0;
}