#include <libuniq/insertSort.hpp>

#include <libuniq/Array.hpp>

int insertSort(Arr &array)
{
    int length(array.length());
    for (int i = 1, j; i < length; ++i) {
        int temp = array[i];
        for (j = i; j > 0; --j) {
            if (array[j - 1] > array[j])
                array.swap(j - 1, j);
            else
                break;
        }
        array[j] = temp;
    }
    return 0;
}
