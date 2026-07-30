#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *p = malloc(s21_strlen(str) + 1);
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      p[i] = str[i] - 32;
    } else {
      p[i] = str[i];
    }
  }

  p[i] = '\0';
  return p;
}

void *s21_to_lower(const char *str) {
  char *p = malloc(s21_strlen(str) + 1);
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      p[i] = str[i] + 32;
    } else {
      p[i] = str[i];
    }
  }

  p[i] = '\0';
  return p;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  char *new_str;
  if (start_index > src_len) {
    // printf("Error: start_index exceeds source string length!\n");
    new_str = S21_NULL;
  } else {
    s21_size_t new_len = src_len + str_len + 1;
    new_str = malloc(new_len * sizeof(char));

    s21_strncpy(new_str, src, start_index);
    new_str[start_index] = '\0';

    s21_strncat(new_str, str, s21_strlen(str));
    s21_strncat(new_str, src + start_index, s21_strlen(str + start_index));
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  int src_len = s21_strlen(src);
  int start_pos = 0, trim_shift = 0;

  char *new_line = malloc(sizeof(char) * (src_len + 1));

  while (start_pos < src_len) {
    if (!s21_strchr(trim_chars, src[start_pos])) {
      new_line[start_pos - trim_shift] = src[start_pos];
    } else {
      trim_shift++;
    }
    start_pos++;
  }
  new_line[start_pos - trim_shift] = '\0';

  return new_line;
}
