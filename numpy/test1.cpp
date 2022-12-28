#include <algorithm>
#include <iostream>
#include <vector>

int argmax(const std::vector<int> &values)
{
    if (values.empty()) {return -1;}
    return std::distance(values.begin(), std::max_element(values.begin(), values.end()));
}

int main()
{
    printf("%d \n", argmax({1,43,52,17}));
    return 0;
}