#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
int _printf(const char *format, ...);
int _strlen(char *s);
int print_c(va_list arg);
int print_s(va_list arg);
int print_switch(const char *format, va_list ap, int i);
int print_di(va_list arg);
int print_bui(va_list ap);
int print_inreverse(int n);
#endif /* MAIN_H */
