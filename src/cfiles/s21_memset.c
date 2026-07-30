#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *new_symb = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) new_symb[i] = c;
  return new_symb;
}