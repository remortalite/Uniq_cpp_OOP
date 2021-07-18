#include <libuniq/Array.hpp>
#include <libuniq/checkArraySortFunc.hpp>
#include <libuniq/insertSort.hpp>

#include <iostream>

int main()
{
    Arr array = { 5, 4, 3, 2, 1, 1, 2, 3, 4 };

    array.print();
    insertSort(array);
    array.print();

    checkArraySortFunc(insertSort);

    return 0;
}
