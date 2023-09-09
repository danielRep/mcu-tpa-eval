/*
 * Authors:
 *      Daniel Oliveira <daniel.oliveira@tango-project.org>
 *      Sandro Pinto <sandro.pinto@tango-project.org>
 *
 * contention-eval is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 */
#include "content_eval.h"

#define DEFINE_OFFSET(SYMBOL, STRUCT, FIELD)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(offsetof(STRUCT, FIELD)))

#define DEFINE_SIZE(SYMBOL, TYPE)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(sizeof(TYPE)))

