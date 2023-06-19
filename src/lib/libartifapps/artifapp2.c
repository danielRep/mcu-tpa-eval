#include "tpa_prof.h"
#include "tpa_mech.h"

#define IT 10
#define N_INSTR 1000

#define REPEAT_MOV_R0(count) \
    do { \
        asm volatile ("mov r0, r0"); \
        if ((count) > 1) { \
            for (int i = 1; i < (count); i++) { \
                asm volatile ("mov r0, r0"); \
            } \
        } \
    } while (0)

#ifdef TPA_PROF
#define FUNC_PATTERN(index) \
    static inline void func##index(void) \
    { \
        tpa_sample_mbb(index); \
        /* some code */ \
        REPEAT_MOV_R0(N_INSTR); \
    }
#elif defined(TPA_MECH)
#define FUNC_PATTERN(index) \
    static inline void func##index(void) \
    { \
        tpa_mech_check_tpi(index); \
        /* some code */ \
        REPEAT_MOV_R0(N_INSTR); \
    }
#endif

FUNC_PATTERN(1);
FUNC_PATTERN(2);
FUNC_PATTERN(3);
FUNC_PATTERN(4);
FUNC_PATTERN(5);
FUNC_PATTERN(6);
FUNC_PATTERN(7);
FUNC_PATTERN(8);
FUNC_PATTERN(9);;
FUNC_PATTERN(10);
FUNC_PATTERN(11);
FUNC_PATTERN(12);
FUNC_PATTERN(13);
FUNC_PATTERN(14);
FUNC_PATTERN(15);
FUNC_PATTERN(16);
FUNC_PATTERN(17);
FUNC_PATTERN(18);
FUNC_PATTERN(19);
FUNC_PATTERN(20);
FUNC_PATTERN(21);
FUNC_PATTERN(22);
FUNC_PATTERN(23);
FUNC_PATTERN(24);
FUNC_PATTERN(25);
FUNC_PATTERN(26);
FUNC_PATTERN(27);
FUNC_PATTERN(28);
FUNC_PATTERN(29);
FUNC_PATTERN(30);
FUNC_PATTERN(31);
FUNC_PATTERN(32);
FUNC_PATTERN(33);
FUNC_PATTERN(34);
FUNC_PATTERN(35);
FUNC_PATTERN(36);
FUNC_PATTERN(37);
FUNC_PATTERN(38);
FUNC_PATTERN(39);
FUNC_PATTERN(40);
FUNC_PATTERN(41);
FUNC_PATTERN(42);
FUNC_PATTERN(43);
FUNC_PATTERN(44);
FUNC_PATTERN(45);
FUNC_PATTERN(46);
FUNC_PATTERN(47);
FUNC_PATTERN(48);
FUNC_PATTERN(49);
FUNC_PATTERN(50);
FUNC_PATTERN(51);
FUNC_PATTERN(52);
FUNC_PATTERN(53);
FUNC_PATTERN(54);
FUNC_PATTERN(55);
FUNC_PATTERN(56);
FUNC_PATTERN(57);
FUNC_PATTERN(58);
FUNC_PATTERN(59);
FUNC_PATTERN(60);
FUNC_PATTERN(61);
FUNC_PATTERN(62);
FUNC_PATTERN(63);
FUNC_PATTERN(64);
FUNC_PATTERN(65);
FUNC_PATTERN(66);
FUNC_PATTERN(67);
FUNC_PATTERN(68);
FUNC_PATTERN(69);
FUNC_PATTERN(70);
FUNC_PATTERN(71);
FUNC_PATTERN(72);
FUNC_PATTERN(73);
FUNC_PATTERN(74);
FUNC_PATTERN(75);
FUNC_PATTERN(76);
FUNC_PATTERN(77);
FUNC_PATTERN(78);
FUNC_PATTERN(79);
FUNC_PATTERN(80);
FUNC_PATTERN(81);
FUNC_PATTERN(82);
FUNC_PATTERN(83);
FUNC_PATTERN(84);
FUNC_PATTERN(85);
FUNC_PATTERN(86);
FUNC_PATTERN(87);
FUNC_PATTERN(88);
FUNC_PATTERN(89);
FUNC_PATTERN(90);
FUNC_PATTERN(91);
FUNC_PATTERN(92);
FUNC_PATTERN(93);
FUNC_PATTERN(94);
FUNC_PATTERN(95);
FUNC_PATTERN(96);
FUNC_PATTERN(97);
FUNC_PATTERN(98);
FUNC_PATTERN(99);
FUNC_PATTERN(100);

void initialise_benchmark(void)
{
    return;
}

int verify_benchmark(int res)
{
    return 1;
}

int __attribute__((noinline)) benchmark_body(int rpt)
{
    func1();
    func2();
    func3();
    func4();
    func5();
    func6();
    func7();
    func8();
    func9();
    func10();
    func11();
    func12();
    func13();
    func14();
    func15();
    func16();
    func17();
    func18();
    func19();
    func20();
    func21();
    func22();
    func23();
    func24();
    func25();
    func26();
    func27();
    func28();
    func29();
    func30();
    func31();
    func32();
    func33();
    func34();
    func35();
    func36();
    func37();
    func38();
    func39();
    func40();
    func41();
    func42();
    func43();
    func44();
    func45();
    func46();
    func47();
    func48();
    func49();
    func50();
    func51();
    func52();
    func53();
    func54();
    func55();
    func56();
    func57();
    func58();
    func59();
    func60();
    func61();
    func62();
    func63();
    func64();
    func65();
    func66();
    func67();
    func68();
    func69();
    func70();
    func71();
    func72();
    func73();
    func74();
    func75();
    func76();
    func77();
    func78();
    func79();
    func80();
    func81();
    func82();
    func83();
    func84();
    func85();
    func86();
    func87();
    func88();
    func89();
    func90();
    func91();
    func92();
    func93();
    func94();
    func95();
    func96();
    func97();
    func98();
    func99();
    func100();

    return 0;
}
