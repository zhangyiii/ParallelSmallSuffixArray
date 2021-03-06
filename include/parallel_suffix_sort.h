#include <stdint.h>

#ifndef __PARALLEL_SUFFIX_SORT_H__
#define __PARALLEL_SUFFIX_SORT_H__

#define MAX_THREADS 16


/** structure to store data required for suffix array */
typedef struct {
  /* character array */
  unsigned char* A;

  /* inverse suffix array */
  unsigned* ISA;
  unsigned* SA;
  int*      N;

  /* array length */
  unsigned length;
} suffix_struct_t;

/** Parallel Suffix sort based on suffix array
 * @param ss suffix structure containing input parameter and temporary array
 * @return ss->A sorted
 */
void parallel_sort(suffix_struct_t* ss);

void sub_sort(suffix_struct_t* ss, int start, int end, unsigned depth, int param);

void ss_simple_sort(suffix_struct_t* ss, const int n_thread); 

extern int max_depth;

#define PARAM_LIMIT_OK 1
#define PARAM_LIMIT_NO 2

#endif /* ndef __PARALLEL_SUFFIX_SORT_H__ */
