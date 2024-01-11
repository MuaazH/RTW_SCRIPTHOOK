//
// Created by MUAAZ on 2024-01-11.
//

#ifndef C_STR_BUILDER_H
#define C_STR_BUILDER_H

typedef struct StrBuilder StrBuilder;
struct StrBuilder {
    char *buf;
    int last;
    int cur;
};

#define NEW_STRING_BUILDER(buf, capacity) {buf, capacity - 1, 0}

/**
 * starts a new string
 */
void sb_reset(StrBuilder *sb);

/**
 * appends a string
 * @param sb
 * @param txt
 */
void sb_str(StrBuilder *sb, const char *txt);

/**
 * appends s character
 * @param sb
 * @param c
 */
void sb_chr(StrBuilder *sb, char c);

/**
 * appends a boolean
 * @param sb
 * @param val
 */
void sb_bool(StrBuilder *sb, int val);

/**
 * appends a 32 bit signed integer
 * @param sb
 * @param val
 */
void sb_i32(StrBuilder *sb, int val);

/**
 * appends a 32 bit unsigned integer
 * @param sb
 * @param val
 */
void sb_u32(StrBuilder *sb, unsigned int val);

/**
 * appends a 64 bit signed integer
 * @param sb
 * @param val
 */
void sb_i64(StrBuilder *sb, long long int val);

/**
 * appends a 64 bit unsigned integer
 * @param sb
 * @param val
 */
void sb_u64(StrBuilder *sb, unsigned long long int val);

#endif // C_STR_BUILDER_H
