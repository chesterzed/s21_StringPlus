#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int diff = 0;
  const char *p1 = (const char *)str1;
  const char *p2 = (const char *)str2;
  for (s21_size_t i = 0; (i < n) && !diff; i++) diff = p1[i] - p2[i];
  return diff;
}