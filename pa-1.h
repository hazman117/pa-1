#pragma once
// define a boolean type to use in the functions

#ifndef _BOOL_TYPE_
#define _BOOL_TYPE_
typedef enum { false, true } bool;
#endif

bool f_armstrong(int n);
bool f_brackets(char *e);
bool f_perfect(int x);
int f_rotate(int n, int r);
int f_str_search(char *pattern, char *text);
int f_collatz_count(int n);
int f_array(int n);
void f_strings(char *s1, char *s2, char *s3);
void f_sort(int x, int y, int z, int *list);
int *f_cubed_sum(int n);
