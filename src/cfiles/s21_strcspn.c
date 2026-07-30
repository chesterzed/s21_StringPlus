#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  char *tmp = (char *)str1;

  while (*tmp != '\0') {
    if (s21_strchr(str2, *tmp)) {
      return result;
    }
    tmp++;
    result++;
  }
  return (result);
}

// Функция strcspn выполняет поиск первого вхождения в строку string1
// любого из символов строки string2, и возвращает количество символов
// до найденного первого вхождения