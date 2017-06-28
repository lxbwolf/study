
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main()
{
	std::vector<std::string> orig;
    orig.push_back("first");
    orig.push_back("second);
    
    std::vector<std::string> v;
    
    v = orig;
    v.insert(v.end(), v.begin(), v.end());
    // Now v contains: {"first", "second", "first", "second"}
    
    v = orig;
    std::copy(v.begin(), v.end(), std::back_inserter(v));

	return 0;
}
