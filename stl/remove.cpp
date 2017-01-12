// remove algorithm example

#include <algorithm>    // std::remove
#include <iostream>     // std::cout

int main()
{
    int my_ints[] = {10, 20, 30, 30, 20, 10, 10, 20};

    // bounds of range:
    int* pbegin = my_ints;                                // ^
    int* pend = my_ints + sizeof(my_ints)/sizeof(int);    // ^

    pend = std::remove(pbegin, pend, 20); // 10 30 30 10 10 ? ? ?
                                          // ^              ^
    std::cout << "range contains: ";
    for (int* p = pbegin; p != pend; ++p)
    {
        std::cout << *p;
    }
    std::cout << std::endl;
    return 0;
}
