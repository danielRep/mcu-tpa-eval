#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "content_eval.h"
#include "platform_config.h"

/* Functions Definition */
void systick_enable_counter(void);
void systick_reset_counter(void);
uint32_t systick_read_counter(void);

#endif  /* __SYSTICK_H__ */


