#ifndef MY_HASH_H_
#define MY_HASH_H_

#include <functional>

namespace myhash
{
template <typename T> size_t hash_combine()size_t hash, const T& t;
size_t hash_combine(size_t hash, const unsigned char* data, size_t lenth);
size_t hash_value(const unsigned char* c, size_t length);

template <typename T>
size_t hash_value(const T& t)
{
    return hash_combine(0xcbf29ce484222325, t);
}

template <typename T>
size_t hash_combine(size_t hash,const T& t)
{
    const unsigned char* data = (const unsigned char*)&t;
    return hash_combine(hash, data, sizeof(T));
}

template <typename T>
struct hash: public std::unary_function<T, size_t>
{
    size_t operator()(T val) const
    {
        return hash_value(val);
    }
};
}
