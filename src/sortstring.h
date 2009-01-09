/*
 * Copyright 2007-2008 by Tommi Rantala <tt.rantala@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef SORTSTRING_H
#define SORTSTRING_H

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define CHARS 256
#define INSERTBREAK 20
typedef unsigned char* string;

extern "C" {
void quicksort(unsigned char**,  size_t);
void mbmradix(unsigned char**,   size_t);
void multikey2(unsigned char**,  size_t);
void arssort(unsigned char**,    size_t);
void frssort(unsigned char**,    size_t);
void frssort1(unsigned char**,   size_t);
void MSDsort(unsigned char**,    size_t);
void burstsortL(unsigned char**, size_t);
void burstsortA(unsigned char**, size_t);
void CRadix(unsigned char**,     size_t);
void cradix_improved(unsigned char**, size_t);
}

void msd_CE0(unsigned char**, size_t);
void msd_CE1(unsigned char**, size_t);
void msd_CE2(unsigned char**, size_t);
void msd_CE3(unsigned char**, size_t);

void msd_ci(unsigned char**, size_t);
void msd_ci_adaptive(unsigned char**, size_t);

void msd_D_std_vector(unsigned char**, size_t);
void msd_D_std_vector_adaptive(unsigned char**, size_t);
void msd_D_std_list(unsigned char**, size_t);
void msd_D_std_list_adaptive(unsigned char**, size_t);
void msd_D_std_deque(unsigned char**, size_t);
void msd_D_std_deque_adaptive(unsigned char**, size_t);
void msd_D_vector_realloc(unsigned char**, size_t);
void msd_D_vector_malloc(unsigned char**, size_t);
void msd_D_vector_realloc_counter_clear(unsigned char**, size_t);
void msd_D_vector_malloc_counter_clear(unsigned char**, size_t);
void msd_D_vector_realloc_shrink_clear(unsigned char**, size_t);
void msd_D_vector_block(unsigned char**, size_t);
void msd_D_vector_brodnik(unsigned char**, size_t);
void msd_D_vector_bagwell(unsigned char**, size_t);
void msd_D_vector_realloc_adaptive(unsigned char**, size_t);
void msd_D_vector_malloc_adaptive(unsigned char**, size_t);
void msd_D_vector_realloc_counter_clear_adaptive(unsigned char**, size_t);
void msd_D_vector_malloc_counter_clear_adaptive(unsigned char**, size_t);
void msd_D_vector_realloc_shrink_clear_adaptive(unsigned char**, size_t);
void msd_D_vector_block_adaptive(unsigned char**, size_t);
void msd_D_vector_brodnik_adaptive(unsigned char**, size_t);
void msd_D_vector_bagwell_adaptive(unsigned char**, size_t);

void msd_DB(unsigned char**, size_t);
void msd_A(unsigned char**, size_t);
void msd_A_adaptive(unsigned char**, size_t);
void msd_A2(unsigned char**, size_t);
void msd_A2_adaptive(unsigned char**, size_t);

void msd_A_lsd4(unsigned char**, size_t);
void msd_A_lsd6(unsigned char**, size_t);
void msd_A_lsd8(unsigned char**, size_t);
void msd_A_lsd10(unsigned char**, size_t);
void msd_A_lsd12(unsigned char**, size_t);
void msd_A_lsd_adaptive4(unsigned char**, size_t);
void msd_A_lsd_adaptive6(unsigned char**, size_t);
void msd_A_lsd_adaptive8(unsigned char**, size_t);
void msd_A_lsd_adaptive10(unsigned char**, size_t);
void msd_A_lsd_adaptive12(unsigned char**, size_t);

void burstsort_vector(unsigned char**, size_t);
void burstsort_brodnik(unsigned char**, size_t);
void burstsort_bagwell(unsigned char**, size_t);
void burstsort_vector_block(unsigned char**, size_t);
void burstsort_superalphabet_vector(unsigned char**, size_t);
void burstsort_superalphabet_brodnik(unsigned char**, size_t);
void burstsort_superalphabet_bagwell(unsigned char**, size_t);
void burstsort_superalphabet_vector_block(unsigned char**, size_t);
void burstsort_sampling_vector(unsigned char**, size_t);
void burstsort_sampling_brodnik(unsigned char**, size_t);
void burstsort_sampling_bagwell(unsigned char**, size_t);
void burstsort_sampling_vector_block(unsigned char**, size_t);
void burstsort_sampling_superalphabet_vector(unsigned char**, size_t);
void burstsort_sampling_superalphabet_brodnik(unsigned char**, size_t);
void burstsort_sampling_superalphabet_bagwell(unsigned char**, size_t);
void burstsort_sampling_superalphabet_vector_block(unsigned char**, size_t);

void burstsort2_vector(unsigned char**, size_t);
void burstsort2_brodnik(unsigned char**, size_t);
void burstsort2_bagwell(unsigned char**, size_t);
void burstsort2_vector_block(unsigned char**, size_t);
void burstsort2_superalphabet_vector(unsigned char**, size_t);
void burstsort2_superalphabet_brodnik(unsigned char**, size_t);
void burstsort2_superalphabet_bagwell(unsigned char**, size_t);
void burstsort2_superalphabet_vector_block(unsigned char**, size_t);
void burstsort2_sampling_vector(unsigned char**, size_t);
void burstsort2_sampling_brodnik(unsigned char**, size_t);
void burstsort2_sampling_bagwell(unsigned char**, size_t);
void burstsort2_sampling_vector_block(unsigned char**, size_t);
void burstsort2_sampling_superalphabet_vector(unsigned char**, size_t);
void burstsort2_sampling_superalphabet_brodnik(unsigned char**, size_t);
void burstsort2_sampling_superalphabet_bagwell(unsigned char**, size_t);
void burstsort2_sampling_superalphabet_vector_block(unsigned char**, size_t);

void burstsort_mkq_simpleburst_1(unsigned char**, size_t);
void burstsort_mkq_simpleburst_2(unsigned char**, size_t);
void burstsort_mkq_simpleburst_4(unsigned char**, size_t);
void burstsort_mkq_recursiveburst_1(unsigned char**, size_t);
void burstsort_mkq_recursiveburst_2(unsigned char**, size_t);
void burstsort_mkq_recursiveburst_4(unsigned char**, size_t);

void multikey_simd1(unsigned char**, size_t);
void multikey_simd2(unsigned char**, size_t);
void multikey_simd4(unsigned char**, size_t);
void multikey_dynamic_vector1(unsigned char**, size_t);
void multikey_dynamic_vector2(unsigned char**, size_t);
void multikey_dynamic_vector4(unsigned char**, size_t);
void multikey_dynamic_brodnik1(unsigned char**, size_t);
void multikey_dynamic_brodnik2(unsigned char**, size_t);
void multikey_dynamic_brodnik4(unsigned char**, size_t);
void multikey_dynamic_bagwell1(unsigned char**, size_t);
void multikey_dynamic_bagwell2(unsigned char**, size_t);
void multikey_dynamic_bagwell4(unsigned char**, size_t);
void multikey_dynamic_vector_block1(unsigned char**, size_t);
void multikey_dynamic_vector_block2(unsigned char**, size_t);
void multikey_dynamic_vector_block4(unsigned char**, size_t);
void multikey_block1(unsigned char**, size_t);
void multikey_block2(unsigned char**, size_t);
void multikey_block4(unsigned char**, size_t);
void multikey_multipivot_brute_simd1(unsigned char**, size_t);
void multikey_multipivot_brute_simd2(unsigned char**, size_t);
void multikey_multipivot_brute_simd4(unsigned char**, size_t);
void multikey_cache4(unsigned char**, size_t);
void multikey_cache8(unsigned char**, size_t);

void mergesort_2way(unsigned char**, size_t);
void mergesort_3way(unsigned char**, size_t);
void mergesort_4way(unsigned char**, size_t);

void mergesort_2way_unstable(unsigned char**, size_t);
void mergesort_3way_unstable(unsigned char**, size_t);
void mergesort_4way_unstable(unsigned char**, size_t);

void mergesort_losertree_64way(unsigned char**, size_t);
void mergesort_losertree_128way(unsigned char**, size_t);
void mergesort_losertree_256way(unsigned char**, size_t);
void mergesort_losertree_512way(unsigned char**, size_t);
void mergesort_losertree_1024way(unsigned char**, size_t);

void mergesort_lcp_2way(unsigned char**, size_t);
void mergesort_lcp_3way(unsigned char**, size_t);

void mergesort_lcp_2way_unstable(unsigned char**, size_t);
void mergesort_cache1_lcp_2way(unsigned char**, size_t);
void mergesort_cache2_lcp_2way(unsigned char**, size_t);
void mergesort_cache4_lcp_2way(unsigned char**, size_t);

void funnelsort_8way_bfs(unsigned char**, size_t);
void funnelsort_16way_bfs(unsigned char**, size_t);
void funnelsort_32way_bfs(unsigned char**, size_t);
void funnelsort_64way_bfs(unsigned char**, size_t);
void funnelsort_128way_bfs(unsigned char**, size_t);
void funnelsort_8way_dfs(unsigned char**, size_t);
void funnelsort_16way_dfs(unsigned char**, size_t);
void funnelsort_32way_dfs(unsigned char**, size_t);
void funnelsort_64way_dfs(unsigned char**, size_t);
void funnelsort_128way_dfs(unsigned char**, size_t);

void clockon();
void clockoff();
double gettime();

#endif //SORTSTRING_H
