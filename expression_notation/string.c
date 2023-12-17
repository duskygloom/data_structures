#include "string.h"

#include <stdlib.h>
#include <string.h>

String *create_empty_string(int maxsize)
{
    String *string  = malloc(sizeof(String));
    if (!string) return NULL;
    string->maxsize = maxsize;
    string->length  = 0;
    string->cstring = calloc(maxsize, sizeof(char));
    if (!string->cstring) {
        free(string);
        return NULL;
    }
    return string;
}

String *create_string(const char *cstring)
{
    int length = strlen(cstring);
    String *string  = malloc(sizeof(String));
    if (!string) return NULL;
    string->maxsize = length+1;
    string->length  = length;
    string->cstring = calloc(length+1, sizeof(char));
    if (!string->cstring) {
        free(string);
        return NULL;
    }
    strcpy(string->cstring, cstring);
    return string;
}

void delete_string(String *string)
{
    if (string) {
        if (string->cstring) free(string->cstring);
        free(string);
    }
}

void append_cstr(String *dest, const char *src)
{
    int length = strlen(src);
    int required_size = dest->length+length+1;
    if (dest->maxsize < required_size) {
        char *newstring = realloc(dest->cstring, required_size*sizeof(char));
        if (!newstring) return;
        // free(dest->cstring);
        dest->cstring = newstring;
        dest->maxsize = required_size;
    }
    char *cursor = dest->cstring;
    for (; *cursor; ++cursor);
    strcpy(cursor, src);
    dest->length += length;
}

void append_char(String *dest, char ch)
{
    int required_size = dest->length+2;
    if (dest->maxsize < required_size) {
        char *newstring = realloc(dest->cstring, required_size*sizeof(char));
        if (!newstring) return;
        // free(dest->cstring);
        dest->cstring = newstring;
        dest->maxsize = required_size;
    }
    char *cursor = dest->cstring;
    for (; *cursor; ++cursor);
    *cursor++ = ch;
    *cursor = 0;
    ++dest->length;
}

void prepend_cstr(String *dest, const char *src)
{
    int length = strlen(src);
    int required = dest->length+length+1;
    if (dest->maxsize < required) {
        char *newstring = realloc(dest->cstring, required*sizeof(char));
        if (!newstring) return;
        // free(dest->cstring);
        dest->cstring = newstring;
        dest->maxsize = required;
    }
    // move or shift str2 towards right to accomodate str1
    memmove(dest->cstring+length, dest->cstring, (dest->length+1)*sizeof(char));
    memcpy(dest->cstring, src, length*sizeof(char));
    dest->length += length;
}

void prepend_char(String *dest, char ch)
{
    int required = dest->length+2;
    if (dest->maxsize < required) {
        char *newstring = realloc(dest->cstring, required*sizeof(char));
        if (!newstring) return;
        // free(dest->cstring);
        dest->cstring = newstring;
        dest->maxsize = required;
    }
    // move or shift str2 towards right to accomodate str1
    memmove(dest->cstring+1, dest->cstring, (dest->length+1)*sizeof(char));
    dest->cstring[0] = ch;
    ++dest->length;
}

void assign_cstr(String *old, const char *new)
{
    int length = strlen(new);
    if (old->maxsize < length+1) {
        char *newstring = realloc(old->cstring, (length+1)*sizeof(char));
        if (!newstring) return;
        old->cstring = newstring;
    }
    strcpy(old->cstring, new);
}
