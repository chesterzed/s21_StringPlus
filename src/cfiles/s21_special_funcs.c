#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *p = S21_NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    p = malloc((length + 1) * sizeof(char));
    s21_size_t i;
    for (i = 0; i < length; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        p[i] = str[i] - 32;
      } else {
        p[i] = str[i];
      }
    }

    p[i] = '\0';
  }
  return p;
}

void *s21_to_lower(const char *str) {
  char *p = S21_NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    p = malloc((length + 1) * sizeof(char));
    s21_size_t i;
    for (i = 0; i < length; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        p[i] = str[i] + 32;
      } else {
        p[i] = str[i];
      }
    }

    p[i] = '\0';
  }
  return p;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if ((src != S21_NULL) && (str != S21_NULL)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (start_index > src_len) {
      // printf("Error: start_index exceeds source string length!\n");
      new_str = S21_NULL;
    } else if (src && str && (start_index <= src_len)) {
      s21_size_t new_len = src_len + str_len + 1;
      new_str = malloc(new_len * sizeof(char));

      for (s21_size_t i = 0; i < src_len + str_len; i++) {
        if (i < start_index) {
          new_str[i] = src[i];
        } else if ((i >= start_index) && (i < start_index + str_len)) {
          new_str[i] = str[i - start_index];
        } else {
          new_str[i] = src[i - str_len];
        }
      }

      // s21_strncpy(new_str, src, start_index);
      new_str[src_len + str_len] = '\0';

      // s21_strncat(new_str, str, s21_strlen(str));
      // s21_strncat(new_str, src + start_index, s21_strlen(str + start_index));
    }
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_line = S21_NULL;
  if ((src != S21_NULL) && (trim_chars != S21_NULL)) {
    int src_len = s21_strlen(src);
    int start_pos = 0, trim_shift = 0;

    new_line = malloc(sizeof(char) * (src_len + 2));

    while (start_pos < src_len) {
      if (!s21_strchr(trim_chars, src[start_pos])) {
        new_line[start_pos - trim_shift] = src[start_pos];
      } else {
        trim_shift++;
      }
      start_pos++;
    }
    new_line[start_pos - trim_shift] = '\0';
  } else if (!trim_chars && src) {
    int src_len = s21_strlen(src);
    new_line = malloc(sizeof(char) * (src_len + 1));
    s21_strncpy(new_line, src, src_len);
  }

  return new_line;
}
