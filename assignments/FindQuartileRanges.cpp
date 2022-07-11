#include<iostream>
#include<vector>


template <typename iterator>
void FindQuartileRanges(iterator first, iterator last)
{
    int size = last - first;
    int range = size / 4;
    std::cout << "First Quartile Range:" << "\n";
    int i;
    for(i = 0; i < range ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nSecond Quartile Range:" << "\n";
    range += size / 4;
     for(; i < range ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nThird Quartile Range:" << "\n";
    range += size / 4;
     for(; i < range ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\nFourth Quartile Range:" << "\n";
    range += size / 4;
     for(; i < range ; ++i)
    {
        std::cout << *first << " ";
        ++first;
    }
}

int main()
{
    std::vector<int> v1;
    for (int i = 16; i < 101; ++i)
    {
        v1.push_back(i);
    }

    FindQuartileRanges(v1.begin(), v1.end());
}