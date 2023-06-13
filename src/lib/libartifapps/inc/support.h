#ifndef SUPPORT_H
#define SUPPORT_H

void initialise_benchmark (void);

int benchmark_body(int rpt) __attribute__((noinline));

int verify_benchmark (int res);

#endif /* SUPPORT_H */
