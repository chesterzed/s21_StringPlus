#include "../s21_string.h"

void ldoubleToString(char *str, long double num, int precision) {
  if (num < 0) {
    num = -num;
  }
  long int intPart = (long int)num;
  double fracPart = num - (double)intPart;

  if (precision > 0) {
    double roundFactor = pow(10, precision);
    fracPart = round(fracPart * roundFactor) / roundFactor;
  }

  if (fracPart >= 0.5 && precision == 0) intPart += 1;

  long int intPartCopy = intPart;
  int i = 0;

  if (!intPartCopy) str[i++] = '0';
  while (intPartCopy) {
    str[i++] = intPartCopy % 10 + '0';
    intPartCopy /= 10;
  }

  char *start = str;
  char *end = str + i - 1;

  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }

  if (precision > 0) {
    str[i++] = '.';

    for (int j = 0; j < precision; j++) {
      fracPart *= 10;
      int digit = (int)fracPart;
      str[i++] = digit + '0';
      fracPart -= digit;
    }
  }

  str[i] = '\0';
}

void doubleToString(char *str, double num, int precision) {
  if (num < 0) {
    num = -num;
  }
  long int intPart = (long int)num;
  double fracPart = num - (double)intPart;

  if (precision > 0) {
    double roundFactor = pow(10, precision);
    fracPart = round(fracPart * roundFactor) / roundFactor;
  }

  if (fracPart >= 0.5 && precision == 0) intPart += 1;

  long int intPartCopy = intPart;
  int i = 0;

  if (!intPartCopy) str[i++] = '0';
  while (intPartCopy) {
    str[i++] = intPartCopy % 10 + '0';
    intPartCopy /= 10;
  }

  char *start = str;
  char *end = str + i - 1;

  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }

  if (precision > 0) {
    str[i++] = '.';

    for (int j = 0; j < precision; j++) {
      fracPart *= 10;
      int digit = (int)fracPart;
      str[i++] = digit + '0';
      fracPart -= digit;
    }
  }

  str[i] = '\0';
}

void int_to_str(char *buffer, int value) {
  char *ptr = buffer;
  int sign = value < 0 ? -1 : 1;

  unsigned int uvalue = (unsigned int)(value * sign);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void lint_to_str(char *buffer, long int value) {
  char *ptr = buffer;
  int sign = value < 0 ? -1 : 1;

  long unsigned int uvalue = (long unsigned int)(value * sign);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void hint_to_str(char *buffer, short int value) {
  char *ptr = buffer;
  int sign = value < 0 ? -1 : 1;

  short unsigned int uvalue = (short unsigned int)(value * sign);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void uint_to_str(char *buffer, unsigned int value) {
  char *ptr = buffer;

  unsigned int uvalue = (unsigned int)(value);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void luint_to_str(char *buffer, long unsigned int value) {
  char *ptr = buffer;

  long unsigned int uvalue = (long unsigned int)(value);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void huint_to_str(char *buffer, short unsigned int value) {
  char *ptr = buffer;

  short unsigned int uvalue = (short unsigned int)(value);

  do {
    *ptr++ = '0' + (uvalue % 10);
    uvalue /= 10;
  } while (uvalue);

  *ptr = '\0';

  char *start = buffer;
  char *end = ptr - 1;
  while (start < end) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);

  char *result = buffer;

  while (*format != '\0') {
    if (*format != '%') {
      *result++ = *format++;
      continue;
    }

    format++;

    int flag_zero = 0;
    int flag_minus = 0;
    int flag_plus = 0;
    int flag_space = 0;
    int flag_hash = 0;

    while (*format == '0' || *format == '-' || *format == '+' ||
           *format == ' ' || *format == '#') {
      switch (*format) {
        case '0':
          flag_zero = 1;
          break;
        case '-':
          flag_minus = 1;
          break;
        case '+':
          flag_plus = 1;
          break;
        case ' ':
          flag_space = 1;
          break;
        case '#':
          flag_hash = 1;
          break;
      }
      format++;
    }

    int width = 0;
    if (*format == '*') {
      width = va_arg(args, int);
      ++format;
    } else {
      while (*format >= '0' && *format <= '9') {
        width = width * 10 + (*format - '0');
        ++format;
      }
    }

    int precision = -1;
    if (*format == '.') {
      format++;
      if (*format == '*') {
        precision = va_arg(args, int);
        format++;
      } else {
        precision = 0;
        while (*format >= '0' && *format <= '9') {
          precision = precision * 10 + (*format - '0');
          ++format;
        }
      }
    }

    int length_l = 0;
    int length_h = 0;
    int length_L = 0;
    if (*format == 'l') {
      if (*(format + 1) == 'l') {
        length_L = 1;
        format += 2;
      } else {
        length_l = 1;
        format++;
      }
    } else if (*format == 'h') {
      if (*(format + 1) == 'h') {
        length_h = 1;
        format += 2;
      } else {
        length_h = 1;
        format++;
      }
    } else if (*format == 'L') {
      length_L = 1;
      format++;
    }

    switch (*format) {
      case 'c': {
        char ch = (char)va_arg(args, int);
        if (flag_minus) {
          *result++ = ch;
          for (int i = 0; i < width - 1; i++) *result++ = ' ';
        } else if (flag_zero) {
          for (int i = 0; i < width - 1; i++) *result++ = '0';
          *result++ = ch;
        } else {
          for (int i = 0; i < width - 1; i++) *result++ = ' ';
          *result++ = ch;
        }
        break;
      }
      case 's': {
        const char *string = va_arg(args, const char *);
        char nill[20] = "(null)";
        int s_len = 0;
        if (precision != -1) {
          s_len = precision;
        } else if (string != S21_NULL) {
          s_len = (int)s21_strlen(string);
        } else {
          s_len = 7;
        }
        int len;
        if ((width - s_len) <= 0) {
          len = 0;
        } else {
          len = width - s_len;
        }
        if (string != S21_NULL) {
          if (flag_minus) {
            for (int i = 0; i < s_len; i++) *result++ = string[i];

            for (int i = 0; i < len; i++) *result++ = ' ';
          } else if (flag_zero) {
            for (int i = 0; i < len; i++) *result++ = ' ';

            for (int i = 0; i < s_len; i++) *result++ = string[i];
          } else {
            for (int i = 0; i < len; i++) *result++ = ' ';

            for (int i = 0; i < s_len; i++) *result++ = string[i];
          }
        } else {
          if (flag_minus) {
            for (int i = 0; i < s_len; i++) *result++ = nill[i];

            for (int i = 0; i < len; i++) *result++ = ' ';
          } else if (flag_zero) {
            for (int i = 0; i < len; i++) *result++ = ' ';

            for (int i = 0; i < s_len; i++) *result++ = nill[i];
          } else {
            for (int i = 0; i < len; i++) *result++ = ' ';

            for (int i = 0; i < s_len; i++) *result++ = nill[i];
          }
        }
        break;
      }
      case '%': {
        if (flag_minus) {
          *result++ = '%';
          for (int i = 0; i < width - 1; i++) *result++ = ' ';
        } else if (flag_zero) {
          for (int i = 0; i < width - 1; i++) *result++ = '0';
          *result++ = '%';
        } else {
          for (int i = 0; i < width - 1; i++) *result++ = ' ';
          *result++ = '%';
        }
        break;
      }
      case 'p': {
        void *pointer = va_arg(args, void *);
        uintptr_t value = (uintptr_t)pointer;
        char hex_buffer[16];
        char *hex_ptr = hex_buffer;

        do {
          unsigned int digit = value & 0xF;
          *hex_ptr++ = (digit < 10) ? ('0' + digit) : 'a' + (digit - 10);
          value >>= 4;
        } while (value);

        *hex_ptr++ = 'x';
        *hex_ptr++ = '0';

        char *hex_start = hex_buffer;
        char *hex_end = hex_ptr - 1;
        while (hex_start < hex_end) {
          char temp = *hex_start;
          *hex_start++ = *hex_end;
          *hex_end-- = temp;
        }

        int len = (hex_ptr - hex_buffer);

        if (flag_minus) {
          for (int i = 0; i < (hex_ptr - hex_buffer); ++i)
            *result++ = hex_buffer[i];
          for (int i = 0; i < width - len; i++) *result++ = ' ';
        } else if (flag_zero) {
          for (int i = 0; i < width - len; i++) *result++ = '0';
          for (int i = 0; i < (hex_ptr - hex_buffer); ++i)
            *result++ = hex_buffer[i];
        } else {
          for (int i = 0; i < width - len; i++) *result++ = ' ';
          for (int i = 0; i < (hex_ptr - hex_buffer); ++i)
            *result++ = hex_buffer[i];
        }
        break;
      }
      case 'n': {
        int *count_result = va_arg(args, int *);
        *count_result = (int)(result - buffer);
        break;
      }
      case 'd':
      case 'i': {
        int sign;
        char int_buffer[30];

        if (length_l) {
          long int value = (long int)va_arg(args, long int);
          sign = value < 0 ? -1 : 1;
          lint_to_str(int_buffer, value);
        } else if (length_h) {
          short int value = (short int)va_arg(args, int);
          sign = value < 0 ? -1 : 1;
          hint_to_str(int_buffer, value);
          sign = value < 0 ? -1 : 1;
        } else {
          int value = (int)va_arg(args, int);
          sign = value < 0 ? -1 : 1;
          int_to_str(int_buffer, value);
        }
        char full_buffer[1000] = "";
        int i;
        for (i = 0; i < (precision - (int)s21_strlen(int_buffer)); i++)
          full_buffer[i] = '0';
        full_buffer[i++] = '\0';
        s21_strncat(full_buffer, int_buffer, s21_strlen(int_buffer));
        int len;
        if ((width - (int)s21_strlen(full_buffer)) <= 0)
          len = 0;
        else
          len = width - (int)s21_strlen(full_buffer);
        if (flag_plus || flag_space || (sign < 0)) len--;
        if (flag_minus) {
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];

          for (int i = 0; i < len; i++) *result++ = ' ';
        } else if (flag_zero && (precision == -1)) {
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < len; i++) *result++ = '0';

          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];
        } else {
          for (int i = 0; i < len; i++) *result++ = ' ';
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];
        }
        break;
      }
      case 'f': {
        if (precision == -1) precision = 6;
        int sign;
        char str[100];
        if (length_L) {
          long double value = va_arg(args, long double);
          sign = value < 0 ? -1 : 1;
          ldoubleToString(str, value, precision);
        } else {
          double value = va_arg(args, double);
          sign = value < 0 ? -1 : 1;
          doubleToString(str, value, precision);
        }
        int len;
        if ((width - (int)s21_strlen(str)) <= 0)
          len = 0;
        else
          len = width - (int)s21_strlen(str);
        if (flag_plus || flag_space || (sign < 0)) len--;
        if (flag_minus) {
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < (int)s21_strlen(str); i++) *result++ = str[i];

          for (int i = 0; i < len; i++) *result++ = ' ';
        } else if (flag_zero) {
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < len; i++) *result++ = '0';

          for (int i = 0; i < (int)s21_strlen(str); i++) *result++ = str[i];
        } else {
          for (int i = 0; i < len; i++) *result++ = ' ';
          if (flag_plus && sign >= 0) {
            *result++ = '+';
          } else if (sign < 0) {
            *result++ = '-';
          } else if (flag_space) {
            *result++ = ' ';
          }
          for (int i = 0; i < (int)s21_strlen(str); i++) *result++ = str[i];
        }
        break;
      }
      case 'x':
      case 'X': {
        unsigned long int value = va_arg(args, unsigned long int);
        if (length_h)
          value = (unsigned short int)value;
        else
          value = (unsigned int)value;
        char hex_buffer[16];
        char *hex_ptr = hex_buffer;

        do {
          unsigned int digit = value & 0xF;
          *hex_ptr++ = (digit < 10)
                           ? ('0' + digit)
                           : (*format == 'x' ? 'a' : 'A') + (digit - 10);
          value >>= 4;
        } while (value);

        s21_size_t length = hex_ptr - hex_buffer;
        if (precision != -1) {
          while (length < (s21_size_t)precision) {
            *hex_ptr++ = '0';
            ++length;
          }
        }

        if (flag_hash) {
          if (*format == 'x') {
            *hex_ptr++ = 'x';
            *hex_ptr++ = '0';
          } else {
            *hex_ptr++ = 'X';
            *hex_ptr++ = '0';
          }
        }

        char *hex_start = hex_buffer;
        char *hex_end = hex_ptr - 1;
        while (hex_start < hex_end) {
          char temp = *hex_start;
          *hex_start++ = *hex_end;
          *hex_end-- = temp;
        }
        int strl = (hex_ptr - hex_buffer);
        int len = 0;
        if ((width - strl) <= 0)
          len = 0;
        else
          len = width - strl;
        if (flag_minus) {
          for (int i = 0; i < strl; i++) *result++ = hex_buffer[i];

          for (int i = 0; i < len; i++) *result++ = ' ';
        } else if (flag_zero && (precision == -1)) {
          for (int i = 0; i < len; i++) *result++ = '0';

          for (int i = 0; i < strl; i++) *result++ = hex_buffer[i];
        } else {
          for (int i = 0; i < len; i++) *result++ = ' ';

          for (int i = 0; i < strl; i++) *result++ = hex_buffer[i];
        }

        break;
      }
      case 'o': {
        unsigned long int value = va_arg(args, unsigned long int);
        if (length_h)
          value = (unsigned short int)value;
        else
          value = (unsigned int)value;
        char octal_buffer[16];
        char *octal_ptr = octal_buffer;

        do {
          unsigned int digit = value & 0x7;
          *octal_ptr++ = '0' + digit;
          value >>= 3;
        } while (value);

        s21_size_t length = octal_ptr - octal_buffer;
        if (precision != -1) {
          while (length < (s21_size_t)precision) {
            *octal_ptr++ = '0';
            ++length;
          }
        }

        if (flag_hash) {
          *octal_ptr++ = '0';
        }

        char *octal_start = octal_buffer;
        char *octal_end = octal_ptr - 1;
        while (octal_start < octal_end) {
          char temp = *octal_start;
          *octal_start++ = *octal_end;
          *octal_end-- = temp;
        }

        int strl = (octal_ptr - octal_buffer);
        int len = 0;
        if ((width - strl) <= 0)
          len = 0;
        else
          len = width - strl;
        if (flag_minus) {
          for (int i = 0; i < strl; i++) *result++ = octal_buffer[i];

          for (int i = 0; i < len; i++) *result++ = ' ';
        } else if (flag_zero && (precision == -1)) {
          for (int i = 0; i < len; i++) *result++ = '0';

          for (int i = 0; i < strl; i++) *result++ = octal_buffer[i];
        } else {
          for (int i = 0; i < len; i++) *result++ = ' ';

          for (int i = 0; i < strl; i++) *result++ = octal_buffer[i];
        }

        break;
      }
      case 'u': {
        char int_buffer[30];

        if (length_l) {
          long unsigned int value =
              (long unsigned int)va_arg(args, long unsigned int);

          luint_to_str(int_buffer, value);
        } else if (length_h) {
          short unsigned int value =
              (short unsigned int)va_arg(args, unsigned int);

          huint_to_str(int_buffer, value);

        } else {
          unsigned int value = (unsigned int)va_arg(args, unsigned int);

          uint_to_str(int_buffer, value);
        }
        char full_buffer[1000] = "";
        int i;
        for (i = 0; i < (precision - (int)s21_strlen(int_buffer)); i++)
          full_buffer[i] = '0';
        full_buffer[i++] = '\0';
        s21_strncat(full_buffer, int_buffer, s21_strlen(int_buffer));
        int len;
        if ((width - (int)s21_strlen(full_buffer)) <= 0)
          len = 0;
        else
          len = width - (int)s21_strlen(full_buffer);
        if (flag_minus) {
          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];
          for (int i = 0; i < len; i++) *result++ = ' ';
        } else if (flag_zero && (precision == -1)) {
          for (int i = 0; i < len; i++) *result++ = '0';

          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];
        } else {
          for (int i = 0; i < len; i++) *result++ = ' ';

          for (int i = 0; i < (int)s21_strlen(full_buffer); i++)
            *result++ = full_buffer[i];
        }
        break;
      }
    }

    format++;
  }

  *result = '\0';
  va_end(args);
  return (int)(result - buffer);
}

// int main(){

//     char str1[100];
//   char str2[100];
//   char *str3 = "%lu Test %lu Test %hu GOD %hu";
//   long unsigned int val = 3088675747373646;
//   long unsigned val2 = 33030030303;
//   unsigned short val3 = 22600;
//   unsigned short val4 = 120;
//   sprintf(str1, str3, val, val2, val3, val4);
//                    s21_sprintf(str2, str3, val, val2, val3, val4);

//   printf("%s\n",str1);
//   printf("%s",str2);

//   return 0;
// }