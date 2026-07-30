#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *tmp = (char *)str1;
  while (*tmp != '\0') {
    if (s21_strrchr(str2, *tmp)) {
      return tmp;
    }
    tmp++;
  }
  return S21_NULL;
}
// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.