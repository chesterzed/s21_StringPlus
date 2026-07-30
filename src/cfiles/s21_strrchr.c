#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *tmp;
  char *last_occurrence = S21_NULL;
  if (c == '\0') {
    last_occurrence = "";
  } else {
    tmp = (char *)str;
    while (*tmp != '\0') {
      if (*tmp == c) {
        last_occurrence = tmp;
      }
      tmp++;
    }
  }
  return last_occurrence;
}
