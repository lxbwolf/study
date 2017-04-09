/*
 * stringtool.h
 *
 *  Created on: Apr 9, 2017
 *      Author: liuxb
 */

#ifndef STRINGTOOL_H_
#define STRINGTOOL_H_

#include <assert.h>
#include <cstddef>
#include <ctype.h>
#include <stdio.h>
#include <string>
#include <vector>

namespace mystring
{
/**
 * Trims leading and trailing whitespace of a string.
 * Whitespace = space + tab by default.
 */
std::string trim(const std::string& str, const std::string& whitespace = "\t");

inline void upperString(std::string& str)
{
    for (std::string::iterator p = str.begin(); p != str.end(); ++p)
    {
        *p = static_cast<char>(toupper(*p));
    }
}

void split(const std::string& s, const std::string& delim, std::vector<std::string>* ret);
void join(const std::vector<std::string>& strings, std::string* result);
void stringReplace(std::string& s1, const std::string& s2, const std::string& s3);

template <typename T>
inline std::string toDouble(T number)
{
    char buf[20];
    sprintf(buf, "%.4lf", double(number));
    return std::string(buf);
}

template <typename T>
inline std::string toHex(const void* address)
{
    size_t number = size_t(address);
    char buf[sizeof(number) * 2 + 1];
    sprintf(buf, "%0*llX", int(sizeof(number) * 2), lluint(number));
    return std::string(buf);
}

template<>
inline std::string toHex(char number)
{
    char buf[sizeof(number) * 2 + 1];
    sprintf(buf, "%0*hhx", int(sizeof(number) * 2), number);
    return std::string(buf);
}

template<> inline std::string toHex(short number)
{
    char buf[sizeof(number) * 2 + 1];
    sprintf(buf, "%0*hX", int(sizeof(number)*2), number);
    return std::string(buf);
}
template<> inline std::string toHex(int number)
{
    char buf[sizeof(number) * 2 + 1];
    sprintf(buf, "%0*X", int(sizeof(number)*2), number);
    return std::string(buf);
}
template<> inline std::string toHex(long number)
{
    char buf[sizeof(number) * 2 + 1];
    sprintf(buf, "%0*lX", int(sizeof(number)*2), number);
    return std::string(buf);
}
template<> inline std::string toHex(unsigned char number)
{
    return toHex(char(number));
}
template<> inline std::string toHex(unsigned short number)
{
    return toHex(short(number));
}
template<> inline std::string toHex(unsigned int number)
{
    return toHex(int(number));
}
template<> inline std::string toHex(unsigned long number)
{
    return toHex(long(number));
}

/**
 * Convert a number to decimal string.
 */
inline std::string toDecimal(int number)
{
    char buf[sizeof(number) * 3 + 1];
    sprintf(buf, "%i", number);
    return std::string(buf);
}

inline std::string toDecimal(unsigned number)
{
    char buf[sizeof(number) * 3 + 1];
    sprintf(buf, "%u", number);
    return std::string(buf);
}

inline std::string toDecimal(long number)
{
    char buf[sizeof(number) * 3 + 1];
    sprintf(buf, "%li", number);
    return std::string(buf);
}

inline std::string toDecimal(unsigned long number)
{
    char buf[sizeof(number) * 3 + 1];
    sprintf(buf, "%lu", number);
    return std::string(buf);
}

/**
 * isBlank
 *
 * Various isBlank variants
 */

// Single character isBlank
inline bool isBlank(const char c)
{
    return ' ' == c;
}

// isBlank for C strings
//
// Scans to the end of a C style string or the first non-blank
inline bool isBlank(const char* s)
{
    while (isBlank(*s))
    {
        ++s;
    }
    return '\0' == *s;
}

// Fixed size char array templated isBlank.
// Will work with strings that are not null terminated.
// Can be used to check a part of a C string.
template<unsigned char SIZE> inline bool isBlank(const char* s)
{
    unsigned char i = SIZE;
    while (isBlank(*s) and i > 0)
    {
        ++s;
        --i;
    }
    return i == 0;
}

// Specialized template for single character array isBlank
template<> inline bool isBlank<1>(const char* s)
{
    return isBlank(*s);
}

// Specialized template for two character array isBlank
template<> inline bool isBlank<2>(const char* s)
{
    return isBlank(s[0]) and isBlank(s[1]);
}

// Specialized template for three character array isBlank
template<> inline bool isBlank<3>(const char* s)
{
    return isBlank(s[0]) and isBlank(s[1]) and isBlank(s[2]);
}

// Specialized template for four character array isBlank
template<> inline bool isBlank<4>(const char* s)
{
    return isBlank(s[0]) and isBlank(s[1]) and isBlank(s[2]) and isBlank(s[3]);
}

/**
 * isDigit
 *
 * Check that all characters are digits ('0' .. '9')
 */

// Check that a single character is a digit ('0' .. '9')
inline bool isDigit(const char c)
{
    return (c >= '0' and c <= '9');
}

// Check that C style string contains only digits ('0' .. '9')
inline bool isDigit(const char* s)
{
    while (isDigit(*s))
    {
        ++s;
    }
    return '\0' == *s;
}

template<unsigned char SIZE> inline bool isDigit(const char* s)
{
    unsigned char i = SIZE;
    while (isDigit(*s) and i > 0)
    {
        ++s;
        --i;
    }
    return i == 0;
}

template<> inline bool isDigit<1>(const char* s)
{
    return isDigit(*s);
}

template<> inline bool isDigit<2>(const char* s)
{
    return isDigit(s[0]) and isDigit(s[1]);
}

template<> inline bool isDigit<3>(const char* s)
{
    return isDigit(s[0]) and isDigit(s[1]) and isDigit(s[2]);
}

template<> inline bool isDigit<4>(const char* s)
{
    return isDigit(s[0]) and isDigit(s[1]) and isDigit(s[2]) and isDigit(s[3]);
}

/**
 * check if input char* is all digit
 *
 * @param [in] const char* buff -- the input char*
 * @param [in] int n -- the length of char*
 * @return bool -- is all digit or not
 * @see    inline bool isAllDigit(const char* buff)
 * @note   none
 */
inline bool isAllDigit(const char* buff, int n)
{
    for (int i = 0; i < n; ++i, ++buff)
    {
        if (not isDigit(*buff))
        {
            return false;
        }
    }
    return true;
}

/**
 * check if input char* is all blank
 *
 * @param [in] const char* buff -- the input char*
 * @param [in] int n -- the length of char*
 * @return bool -- is all blank or not
 * @see    inline bool isAllBlank(const char* buff)
 * @note   none
 */
inline bool isAllBlank(const char* buff, int n)
{
    for (int i = 0; i < n; ++i, ++buff)
    {
        if (not isBlank(*buff))
        {
            return false;
        }
    }
    return true;
}

/**
 * toUlong
 */
inline unsigned char toUlong(const char c)
{
    assert(c >= '0');
    assert(c <= '9');
    return static_cast<unsigned char>(c - '0');
}

inline unsigned long toUlong(const char* s)
{
    unsigned long ret = 0;
    while ('\0' != *s)
    {
        ret *= 10;
        ret += toUlong(*s);
        ++s;
    }
    return ret;
}

inline unsigned long toUlong(const char* s, int len)
{
    unsigned long ret = 0;
    for (; len > 0; --len)
    {
        ret *= 10;
        ret += toUlong(*s);
        ++s;
    }
    return ret;
}

template<unsigned char SIZE> inline unsigned long toUlong(const char* s)
{
    unsigned long ret = 0;
    for (unsigned char i = 0; i < SIZE; ++i)
    {
        if (isBlank(*s))
        {
            ++s;
            continue;
        }

        ret *= 10;
        ret += toUlong(*s);
        ++s;
    }
    return ret;
}

template<unsigned char SIZE> inline unsigned long toUlongSpaceSafe(const char* s)
{
    unsigned long ret = 0;
    for (unsigned char i = 0; i < SIZE; ++i)
    {
        if (*s < '0' || *s > '9')
        {
            ++s;
            continue;
        }

        ret *= 10;
        ret += toUlong(*s);
        ++s;
    }
    return ret;
}

inline unsigned long toUlongSpaceSafe(const char* s)
{
    unsigned long ret = 0;
    for (; *s != '\0'; ++s)
    {
        if (*s < '0' || *s > '9')
        {
            ++s;
            continue;
        }

        ret *= 10;
        ret += toUlong(*s);
    }
    return ret;
}

template<> inline unsigned long toUlong<1>(const char* s)
{
    return toUlong(s[0]);
}

template<> inline unsigned long toUlong<2>(const char* s)
{
    return toUlong(s[0]) * 10 + toUlong(s[1]);
}

template<> inline unsigned long toUlong<3>(const char* s)
{
    return toUlong(s[0]) * 100 + toUlong(s[1]) * 10 + toUlong(s[2]);
}

template<> inline unsigned long toUlong<4>(const char* s)
{
    return toUlong(s[0]) * 1000 + toUlong(s[1]) * 100 + toUlong(s[2]) * 10 + toUlong(s[3]);
}

/**
 * Convert hexdecimal string number to unsigned long int
 */
inline unsigned long hexToUlong(const char c)
{
    assert(c >= '0');
    // 0 - 9
    if (c <= '9')
    {
        return static_cast<unsigned long>(c - '0');
    }
    // A-F
    if (c <= 'F')
    {
        assert(c >= 'A');
        return static_cast<unsigned long>(c - '0' - 7);
    }
    // a-f
    assert(c >= 'a');
    return static_cast<unsigned long>(c - '0' - 39);
}

inline unsigned long hexToUlong(const char* s)
{
    unsigned long ret = 0;
    while ('\0' != *s)
    {
        ret *= 16;
        ret += hexToUlong(*s);
        ++s;
    }
    return ret;
}

template<unsigned char SIZE> inline unsigned long hexToUlong(const char* s)
{
    unsigned long ret = 0;
    for (unsigned char i = 0; i < SIZE; ++i)
    {
        ret *= 16;
        ret += hexToUlong(*s);
        ++s;
    }
    return ret;
}

template<> inline unsigned long hexToUlong<1>(const char* s)
{
    return hexToUlong(s[0]);
}

inline bool endsWith(const std::string& a, const std::string& b)
{
    if (b.size() > a.size())
    {
        return false;
    }
    return a.compare(a.size() - b.size(), b.size(), b) == 0;
}

inline bool startsWith(const std::string& a, const std::string& b)
{
    if (b.size() > a.size())
    {
        return false;
    }
    return a.compare(0, b.size(), b) == 0;
}
} /* namespace mystring */

#endif /* STRINGTOOL_H_ */

