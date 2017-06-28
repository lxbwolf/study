
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main()
{
	std::set<double> input;
    input.insert(5);
    input.insert(6);
    
    std::vector<double> output(2); // Must be with a size.
    std::copy(input.begin(), input.end(), output.begin());
    
    // If size is not assigned in intialization, back_inserter is also available.
    std::copy(input.begin(), input.end(), std::back_inserter(output));
    
	return 0;
}
