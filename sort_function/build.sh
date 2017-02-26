set -x

g++ -std=c++11 -o stdsort-REL -O3 main.cpp PlayerSorting.cpp
g++ -std=c++11 -o stdsort-DBG -O0 main.cpp PlayerSorting.cpp
