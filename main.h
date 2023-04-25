#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _strlen(char *s);
void print_c(va_list arg);
int print_s(va_list arg);
int print_cs(const char *format, va_list ap);
int print_di(va_list arg);
#endif /* MAIN_H */
