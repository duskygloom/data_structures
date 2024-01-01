#ifndef STRING_H
#define STRING_H

#include <stdio.h>

typedef struct String {
    int maxsize;
    int length;
    char *cstring;
} String;

String *create_empty_string(int maxsize);
String *create_string(const char *cstring);
void delete_string(String *string);

static inline void print_string(const String *string)
{
    printf("%s", string->cstring);
}

void append_cstr(String *dest, const char *src);
void append_char(String *dest, char ch);

static inline void concat_str(String *dest, const String *src)
{
    append_cstr(dest, src->cstring);
}

void assign_cstr(String *old, const char *new);

static inline void assign_str(String *old, const String *new)
{
    assign_cstr(old, new->cstring);
}

#endif
