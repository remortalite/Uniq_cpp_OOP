#include "Array.hpp"

#include <ctime>
#include <iostream>

int main()
{

    srand(time(0));

    Arr array;
    array.fillRand(10);
    array.print();

    array.fillInc(10);
    array.print();

    array.fillDec(10);
    array.print();

    array.setRange(10, 15);
    array.fillRand(10);
    array.print();

    Arr array2 = { 1, 2, 3, 4, -5, -6, -7, -8 };
    array2.print();

    return 0;
}
