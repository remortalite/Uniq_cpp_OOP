#include <libuniq/Array.hpp>
#include <libuniq/insertSort.hpp>

#include <iostream>

int main()
{
    Arr array = { 5, 6, 788 };

    array.print();
    insertSort(array);
    array.print();

    return 0;
}
