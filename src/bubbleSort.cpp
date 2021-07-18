#include <libuniq/bubbleSort.hpp>

#include <libuniq/Array.hpp>

void bubbleSort(Arr &array) {
	int length = array.length();
	for (int i = 0; i < length; ++i)
		for (int j = length-1; j > i; --j)
			if (array[j] < array[j-1])
				array.swap(j - 1, j);
}
