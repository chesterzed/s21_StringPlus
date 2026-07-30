#define S21_NULL ((void *)0)

#define s21_size_t long long unsigned int

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strerror(int errnum);

int s21_sprintf(char *buffer, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// WINDOWS: according to gcc.exe -x c -E -dM nul | findstr /i __SIZE_TYPE__:
// #define __SIZE_TYPE__ long long unsigned int LINUX: gcc -x c -E -dM /dev/null
// | grep -i __SIZE_TYPE__: #define __SIZE_TYPE__ long unsigned int typedef
// unsigned long long s21_size_t; // from definition from
// https://stackoverflow.com/questions/72867644/why-can-i-use-size-t-without-defining-it
