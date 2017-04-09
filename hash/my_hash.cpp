/*
 * my_hash.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: liuxb
 */

#include "my_hash.h"

namespace myhash
{
size_t hash_value(const unsigned char* c, size_t lenth)
{
    return hash_combine(0xcbf29ce484222325, c, length);
}

size_t hash_combine(size_t hash, const unsigned char* data, size_t lenth)
{
    for (size_t byteIndex = 0; byteIndex < lenth; ++byteIndex)
    {
        hash ^= data[byteIndex];
        hash *= 0x100000001b3;
    }
    return hash;
}
}


