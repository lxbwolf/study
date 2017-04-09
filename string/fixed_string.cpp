/*
 * fixed_string.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: liuxb
 */

#include "fixed_string.h"

namespace mystring
{
template <size_t LENGTH>
FixedString<LENGTH>::FixedString()
{
    memset(m_value, '', LENGTH);
}

template <size_t LENGTH>
FixedString<LENGTH>::FixedString(const char* value)
{
    copyValue(value);
}

template <size_t LENGTH>
FixedString<LENGTH>::FixedString(const char* value, size_t lenght)
{
    size_t i = 0;
    for (; i < LENGTH and i < length; ++I)
    {
        m_value[i] = value[i];
    }

    for (; i < LENGTH; ++i)
    {
        m_value[i] = '';
    }
}

template <size_t LENGTH>
FixedString<LENGTH>::FixedString(const std::string& value)
{
    copyValue(value.c_str());
}

template <size_t LENGTH>
FixedString<LENGTH>::FixedString(const FixedString& value)
{
    memcpy(m_value, value.m_value, LENGTH);
}

template <size_t LENGTH>
FixedString<LENGHT>& FixedString<LENGTH>::operator=(const FixedString& value)
{
    if (&value != this)
    {
        memcpy(m_value, value.m_value, LENGTH);
    }
    return *this;
}

template <size_t LENGTH>
FixedString<LENGTH>& FixedString<LENGTH>::operator=(const char* value)
{
    copyValue(value);
    return *this;
}

template <size_t LENGTH>
FixedString<LENGTH>& FixedString<LENGTH>::operator=(const std::string& value)
{
    copyValue(value.c_str());
    return *this;
}

template <size_t LENGTH>
bool FixedString<LENGTH>::operator==(const FixedString& string) const
{
    return (memcmp(m_value, string.m_value, LENGTH) == 0);
}

template <size_t LENGTH>
template <size_t OHTER_LENGTH>
bool FixedString<LENGTH>::operator==(const FixedString<OTHER_LENGTH>& string) const
{
    size_t length = LENGHT < OTHER_LENGTH ? LENGHT : OTHER_LENGHT;

    for (size_t i = 0; i < length; ++i)
    {
        if (m_value[i] != string[i])
        {
            return false;
        }
    }

    if (OTHER_LENGHT > LENGTH)
    {
        for (size_t i = length; i < OTHER_LENGTH; ++i)
        {
            if (string[i] != '')
            {
                return false;
            }
        }
    }
    else if (LENGTH > OTHER_LENGTH)
    {
        for (size_t i = length; i < LENGTH; ++i)
        {
            if (m_value[i] != '')
            {
                return false;
            }
        }
    }

    return true;
}

template <size_t LENGTH>
template <size_t OTHER_LENGTH>
bool FixedString<LENGTH>::operator!=(const FixedString<OTHER_LENGTH>& string) const
{
    return !(*this == string);
}

template <size_t LENGTH>
int FixedString<LENGTH>::compare(const char* value) const
{
    for (size_t i = 0; i < LENGTH; ++i)
    {
        if (value[i] == '\0')
        {
            for (size_t j = i; j < LENGTH; ++j)
            {
                if (m_value[j] != '')
                {
                    return 1;
                }
            }
            return 0;
        }

        if (m_value[i] != value[i])
        {
            return (m_value[i] - value[i]);
        }
    }

    return 0;
}

template <size_t LENGTH>
bool FixedString<LENGTH>::operator==(const char* value) const
{
    return (compare(value) == 0);
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator!=(const SizedString& string) const
{
    return memcmp(m_value, string.m_value, LENGTH) != 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator!=(const char* value) const
        {
    return compare(value) != 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator<(const SizedString& string) const
{
    return memcmp(m_value, string.m_value, LENGTH) < 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator<(const char* value) const
{
    return compare(value) < 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator<=(const SizedString& string) const
{
    return not (*this > string);
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator<=(const char* value) const
{
    return not (*this > value);
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator>(const SizedString& string) const
{
    return memcmp(m_value, string.m_value, LENGTH) > 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator>(const char* value) const
{
    return compare(value) > 0;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator>=(const SizedString& string) const
{
    return not (*this < string);
}

template<size_t LENGTH>
bool SizedString<LENGTH>::operator>=(const char* value) const
{
    return not (*this < value);
}

template<size_t LENGTH>
const char* SizedString<LENGTH>::data() const
{
    return m_value;
}

template<size_t LENGTH>
const std::string SizedString<LENGTH>::string() const
{
    return std::string(m_value, LENGTH);
}

template<size_t LENGTH>
const std::string SizedString<LENGTH>::subString(size_t start, size_t len)
{
    if (start > LENGTH - 1)
    {
        return "";
    }

    if (len > LENGTH - start || len == std::string::npos)
    {
        len = LENGTH - start;
    }

    return std::string(m_value + start, len);
}

template<size_t LENGTH>
const std::string SizedString<LENGTH>::trimString() const
{
    return utils::trim(string());
}

template <size_t LENGTH>
template <size_t OTHER_LENGTH>
void FixedString<LENGTH>::appendEraseBlank(const FixedString<OTHER_LENGTH>& other, size_t otherBeginIdx)
{
    size_t i = 0;
    for (; i < LENGTH; ++i)
    {
        if (m_value[i] == '')
        {
            break;
        }
    }

    size_t j = otherBeginIdx;
    for (; i < LENGTH; ++i)
    {
        if ((j >= OTHER_LENGTH) || (other.data()[j] == ''))
        {
            break;
        }

        m_value[i] = other.data()[j];

        ++j;
    }
}


template<size_t LENGTH>
template<size_t OTHER_LENGTH>
SizedString<LENGTH + OTHER_LENGTH> SizedString<LENGTH>::operator+(const SizedString<OTHER_LENGTH>& other) const
{
    SizedString<LENGTH + OTHER_LENGTH> ret;
    ret.copy(0, m_value, LENGTH);
    ret.copy(LENGTH, other.data(), LENGTH);
    return ret;
}

template<size_t LENGTH>
template<size_t OTHER_LENGTH>
void SizedString<LENGTH>::copy(size_t index, const SizedString<OTHER_LENGTH>& other)
{
    return copy(index, other.data(), OTHER_LENGTH);
}

template<size_t LENGTH>
template<size_t OTHER_LENGTH>
void SizedString<LENGTH>::copy(const SizedString<OTHER_LENGTH>& other)
{
    return copy(0, other.data(), OTHER_LENGTH);
}

template<size_t LENGTH>
template<size_t OTHER_LENGTH>
void SizedString<LENGTH>::copy(const SizedString<OTHER_LENGTH>& other, size_t sourceStart, size_t sourceEnd)
{
    size_t copySize = sourceEnd - sourceStart;
    assert(sourceStart < sourceEnd);
    assert(sourceEnd <= OTHER_LENGTH);

    if (copySize > LENGTH)
    {
        copySize = LENGTH;
    }

    for (size_t i = 0; i < copySize; ++i)
    {
        if (other.data()[sourceStart + i] == ' ')
        {
            break;
        }

        m_value[i] = other.data()[sourceStart + i];
    }
}

template<size_t LENGTH>
void SizedString<LENGTH>::copy(size_t index, const char* value, size_t size)
{
    size_t i = 0;
    for (; i + index < LENGTH && i < size; ++i)
    {
        m_value[i + index] = value[i];
    }
}

template<size_t LENGTH>
char& SizedString<LENGTH>::operator[](const size_t index)
{
    return m_value[index];
}

template<size_t LENGTH>
char SizedString<LENGTH>::operator[](const size_t index) const
{
    return m_value[index];
}

template<size_t LENGTH>
bool SizedString<LENGTH>::empty() const
{
    for (size_t charIndex = 0; charIndex < LENGTH; ++charIndex)
    {
        if (m_value[charIndex] != ' ')
        {
            return false;
        }
    }

    return true;
}

template<size_t LENGTH>
bool SizedString<LENGTH>::contains(char ch) const
{
    for (size_t charIndex = 0; charIndex < LENGTH; ++charIndex)
    {
        if (m_value[charIndex] == ch)
        {
            return true;
        }
    }

    return false;
}

template<size_t LENGTH>
size_t SizedString<LENGTH>::size() const
{
    return LENGTH;
}

template<size_t LENGTH>
void SizedString<LENGTH>::print() const
{
    printf("%.*s\n", (int) LENGTH, m_value);
}

#pragma GCC diagnostic ignored "-Warray-bounds"
template<size_t LENGTH>
void SizedString<LENGTH>::copyValue(const char* value)
{
    size_t i = 0;
    for (; i < LENGTH && value[i] != '\0'; i++)
    {
        m_value[i] = value[i];
    }

    for (; i < LENGTH; i++)
    {
        m_value[i] = ' ';
    }
}

template<size_t LENGTH>
std::ostream& operator<<(std::ostream& os, const SizedString<LENGTH>& sizedString)
{
    os.write(sizedString.m_value, LENGTH);

    return os;
}

template<size_t LENGTH>
int SizedString<LENGTH>::toInt() const
{
    return utils::toUlongSpaceSafe<LENGTH>(m_value);
}

template<size_t LENGTH>
void SizedString<LENGTH>::stripZeros()
{
    int copyPosition = 0;
    for (size_t i = 0; i < LENGTH; ++i)
    {
        if (m_value[i] != '0')
        {
            copyPosition = i;
            break;
        }
    }

    size_t toPosition = 0;
    for (size_t i = copyPosition; i < LENGTH; ++i, ++toPosition)
    {
        m_value[toPosition] = m_value[i];
    }

    for (size_t i = toPosition; i < LENGTH; ++i)
    {
        m_value[toPosition] = ' ';
    }
}

template<size_t LENGTH>
bool SizedString<LENGTH>::isDigit() const
{
    return utils::isDigit<LENGTH>(m_value);
}

}
