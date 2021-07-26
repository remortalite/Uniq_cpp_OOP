#include <libuniq/Array.hpp>

#include <cassert>
#include <functional>
#include <iostream>

void checkArraySortFunc(std::function<void(Arr &)> sortFunction)
{
    Arr array;
    array.fillRand(1000);

    int checksum = array.checkSum();

    sortFunction(array);

    assert(checksum == array.checkSum());
    assert(1 == array.runNumber());

    std::cout << "All checks passed." << std::endl;
}
