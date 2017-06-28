
#include <algorithm>
#include <iostream>
#include <vector>

int main(int arc, char* argv[])
{
	double darr[10] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
	std::vector<double> vdouble(10); // must be with a size.
    auto it = vdouble.begin();
    std::copy(darr, darr + 10, it);
    
    while (it != vdouble.end())
    {
    	std::cout << *it << std::endl;
        ++ it;
    }

	return 0;
}
