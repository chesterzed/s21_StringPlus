#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  if (c == '\0') return "";
  char *tmp = (char *)str;
  while (*tmp != '\0') {
    if (*tmp == c) {
      return tmp;
    }
    tmp++;
  }
  return S21_NULL;
}
