//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-12.
//

#ifndef I04_STR_UTIL_H
#define I04_STR_UTIL_H

int str_cmp(const char *a, const char *b);

unsigned int str_len_limited(const char *txt, unsigned int maxLen);

unsigned int str_len(const char *txt);

int str_split(char *str, char **output, unsigned int outputSize);

int str_to_i32(const char *src, int *out);

int str_to_u32(const char *src, unsigned int *out);

#endif // I04_STR_UTIL_H
