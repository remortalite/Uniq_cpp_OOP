#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <initializer_list>

class Arr
{
public:
    Arr();

    ~Arr();

    // create empty array
    Arr(int length);

    Arr(const std::initializer_list<int> &list);

    // deallocate memory of an array, set length to zero
    void erase();
    // erase and set range to defaults
    void reset();

    void print();

    int length();

    // erase data and reallocate
    void reallocate(int length);
    // save data and change size (slow)
    void resize(int length);

    void setRange(int min, int max);

    void fillRand(int length);
    void fillDec(int length);
    void fillInc(int length);

    int checkSum(bool print = false);
    int runNumber(bool print = false);

    void swap(int index1, int index2);

    int &operator[](const int index);

private:
    int *m_array;
    int m_length;

    int m_rangeMin = 0;
    int m_rangeMax = 0;

    void allocateMemory(int length);
};

#endif // #ifndef ARRAY_HPP
