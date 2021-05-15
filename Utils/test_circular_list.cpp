#include "circular_list.hpp"
#include <iostream>

int main()
{
    CircularList<int> circular_list;
    for(int i=0;i<100;i++)
        circular_list.push_back(i);

    return 0;
}

