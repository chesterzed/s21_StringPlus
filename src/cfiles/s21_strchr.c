#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *tmp;
  if (c == '\0') {
    tmp = "";
  } else {
    tmp = (char *)str;
    while (*tmp != '\0') {
      if (*tmp == c) {
        break;
      }
      tmp++;
    }

    if (*tmp == '\0') tmp = S21_NULL;
  }
  return tmp;
}
