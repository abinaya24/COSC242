/**
 * File: mylib.h
 * @author Josh King.
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

/**
 * Prototypes
 * Purpose: specifies functions to be implemented in the mylib.c file, based on
 * their signatures.
 */
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);

#endif
