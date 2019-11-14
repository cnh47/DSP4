#ifndef INSERTSORT_H_INCLUDED
#define INSERTSORT_H_INCLUDED
// From pg 294 of the Book
#include <vector>
using std::vector;
template<typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan);
template <typename Iterator>
void insertionSort(const Iterator & begin, const Iterator & end)
{
    insertionSort(begin,end,std::less<decltype(*begin)>{});
}

template<typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan)
{
    if (begin == end)
        return;

    Iterator j;

    for (Iterator p = begin+1; p != end; ++p)
    {
        auto tmp = std::move(*p);
        for(j=p; j!=begin && lessThan(tmp,*(j-1));--j)
            *j = std::move(*(j-1));
        *j = std::move(tmp);
    }
}


#endif // INSERTSORT_H_INCLUDED
