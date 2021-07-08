#include "lib/insertSort.hpp"

#include <ctime>
#include <iostream>

int main(int argc, char *argv[])
{
    srand(time(0));
    Arr array = { 5, 3, 7, 2, 1, 0 };
    array.print();
    insertSort(array);
    array.print();

    std::cout << "---------" << std::endl;

    array.fillRand(10000);
    array.checkSum();
    array.runNumber();
    insertSort(array);
    array.checkSum();
    array.runNumber();

    return 0;
}
