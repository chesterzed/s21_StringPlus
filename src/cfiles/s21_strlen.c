#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int i = 0;
  while (str[i]) i++;
  return i;
}
