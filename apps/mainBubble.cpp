#include <libuniq/Array.hpp>
#include <libuniq/bubbleSort.hpp>
#include <libuniq/checkArraySortFunc.hpp>

#include <iostream>

int main()
{
    Arr array;
    array.fillRand(10);
    array.print();

    bubbleSort(array);

    array.print();

    checkArraySortFunc(bubbleSort);

    return 0;
}
