#include<iostream>
#include<vector>

template<typename iterator>
class IterRange
{
    public:
    IterRange()
    :first_(nullptr), curr_(nullptr), last_(nullptr)
    {

    }

    IterRange(iterator first, iterator last)
    : first_(first), curr_(first), last_(last)
    {
    
    }

    iterator first_;
    iterator curr_;
    iterator last_;

    iterator begin()
    {
        return first_;
    }
    iterator end()
    {
        return last_;
    }
};

template<typename iter, typename callable>
class filter
{
    public:
    filter(IterRange iter_range, callable fn)
    : fn_(fn)
    {
        iter_range_ = iter_range;
    }

    iter& operator++()
    {
        while (iter_range_.curr_ != iter_range_.end())
        {
            if (fn_(*iter_range_.curr_))
            {
                return iter_range_.curr_;
            }
            ++iter_range_.curr_;
        }
        return iter_range_.end();
    }

    IterRange iter_range_();
    callable fn_;

};

int is_even(int x)
{
    if (x % 2 == 0) {
        return 1;
    }
    
    return 0;
}

int main()
{
    std::vector<int> v1{1,2,3,4,5,6,7,8,9};

    IterRange i1(v1.begin(), v1.end());

    std::cout << *i1.begin();

    filter f1(i1, is_even);


}