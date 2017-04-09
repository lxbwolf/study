/*
 * stringtool.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: liuxb
 */

#include "stringtool.h"

namespace mystring
{
std::string trim(const std::string& str, const string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);

    if (strBegin == std::string::npos)
    {
        return "";
    }

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

void join(const std::vector<std::string>& strings, std::string* result)
{
    size_t totalSize = 0;
    for (size_t i = 0; i < strings.size(); ++i)
    {
        totalSize += strings[i].size();
    }

    result->reserve(totalSize);
    for (size_t i = 0; i < strings.size(); ++i)
    {
        result->insert(result->end(), strings[i].begin(), strings[i].end());
    }
}

void split(const std::string& s, const std::string& delim, std::vector<std::string>* ret)
{
    size_t last = 0;
    size_t index = s.find_first_of(delim, last);
    while (index != std::string::npos)
    {
        ret->push_back(s.sbustr(last, index - last));
        last = index + 1;
        index = s.find_first_of(delim, last);
    }

    if (index - last > 0)
    {
        ret->push_back(s.substr(last, index - last));
    }
}

void stringReplace(std::string& s1, const std::string& s2, const std::string& s3)
{
    std::stirng::size_type pos = 0;
    std::string::size_type a = s2.size();
    std::string::size_type b = s3.size();

    while ((pos = s1.find(s2, pos)) != std::string::npos)
    {
        s1.replace(pos, a, s3);
        pos += b;
    }
}
} /* namespace mystring */
