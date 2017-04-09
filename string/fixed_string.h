/*
 * fixed_string.h
 *
 *  Created on: Apr 8, 2017
 *      Author: liuxb
 */

#ifndef FIXED_STRING_H_
#define FIXED_STRING_H_

#include <cstring>
#include <string>
#include <ostream>

namespace mystring
{
template <size_t LENGTH> class FixedString;
template <size_t LENGTH> std::ostream& operator<<(std::ostream& os, const FixedString<LENGTH> FixedString);

template <size_t LENGTH>
class FixedString
{
public:
    FixedString();
    explicit FixedString(const char* value);
    FixedString(const char* value, size_t length);
    FixedString(const std::string& value);
    FixedString(const FixedString& value);

    int compare(const char* value) const;

    FixedString& operator=(const FixedString& value);
    FixedString& operator=(const char* value);
    FixedString& operator=(const std::string& value);

    bool operator==(const FixedString& string) const;
    bool operator==(const char* value) const;

    template <size_t OTHER_LENGTH>
    bool operator==(const FixedString<OTHER_LENGTH>& string) const;

    template <size_t OTHER_LENGTH>
    bool operator!=(const FixedString<OTHER_LENGTH>& string) const;

    bool operator!=(const FixedString& string) const;
    bool opeartor!=(const char* value) const;

    bool opeartor<(const FixedString& string) const;
    bool operator<(const char* value) const;

    bool operator<=(const FixedString& string) const;
    bool operator<=(const char* value) const;

    bool operator>=(const FixedString& string) const;
    bool operator>=(const char* value) const;

    template <size_t OTHER_LENGTH>
    void appendEraseBlank(const FixedString<OTHER_LENGTH>& other, size_t otherBeginIndex);

    template <size_t OTHER_LENGTH>
    FixedString<LENGTH + OTHER_LENGTH> operator+(const FixedString<OTHER_LENGTH>& other) const;

    template <size_t OTHER_LENGTH>
    void copy(size_t index, const FixedString<OTHER_LENGTH>& other);

    template <size_t OTHER_LENGTH>
    void copy(const FixedString<OTHER_LENGTH>& other);

    template <size_t OTHER_LENGTH>
    void copy(const FixedString<OTHER_LENGTH>& other, size_t sourceStart, size_t sourceEnd);

    void copy(size_t index, const char* value, size_t size);

    bool contains(char ch) const;

    char& operator[](const size_t index);
    char operator[](const size_t) const;

    const char* data() const;
    const std::string string() const;
    const std::string subString(size_t start, size_t len = std::string::npos);
    const std::string trimString() const;

    bool empty() const;
    size_t size() const;

    friend std::ostream& operator<<<LENGTH>(std::ostream& os, const FixedString<LENGTH>& fixedString);
    void print() const;
    int toInt() const;
    bool isDigit() const;
    void stripZeros();

private:
    void copyValue(const char* value);

private:
    char m_value[LENGTH];
}__attribute__((__packed));
}
#endif /* FIXED_STRING_H_ */
