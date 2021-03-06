#include <libuniq/Array.hpp>

#include <cassert>
#include <iostream>
#include <random>

Arr::Arr() : m_length(0), m_array(nullptr) {}

Arr::~Arr()
{
    delete[] m_array;
}

Arr::Arr(int length) : m_length(length)
{
    allocateMemory(length);
}

Arr::Arr(const std::initializer_list<int> &list) : Arr(list.size())
{
    int count = 0;
    for (const auto &element : list)
        m_array[count++] = element;
}

void Arr::allocateMemory(int length)
{
    assert(length > 0);
    m_array = new int[length];
    assert(m_array != NULL);
}

void Arr::setRange(int min, int max)
{
    assert(min <= max);
    m_rangeMin = min;
    m_rangeMax = max;
}

void Arr::fillRand(int length)
{
    if (m_array != nullptr)
        reset();
    allocateMemory(length);
    m_length = length;
    for (int i = 0; i < length; i++) {
        // check if range was manually set
        if (m_rangeMax == m_rangeMin)
            m_array[i] = rand() % (2 * length);
        else
            m_array[i] = rand() % (m_rangeMax - m_rangeMin) + m_rangeMin;
    }
}

void Arr::fillInc(int length)
{
    if (m_array != nullptr)
        reset();
    allocateMemory(length);
    m_length = length;
    for (int i = 0; i < length; ++i)
        m_array[i] = i + 1;
}

void Arr::fillDec(int length)
{
    if (m_array != nullptr)
        reset();
    allocateMemory(length);
    m_length = length;
    for (int i = 0; i < length; ++i)
        m_array[i] = length - i;
}

void Arr::erase()
{
    delete[] m_array;
    m_array = nullptr;
    m_length = 0;
}

void Arr::reset()
{
    erase();
    m_rangeMin = 0;
    m_rangeMax = 0;
}

void Arr::print()
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_array[i] << " ";
    std::cout << std::endl;
}

int Arr::checkSum(bool print)
{
    int checkSum = 0;
    for (int i = 0; i < m_length; ++i)
        checkSum += m_array[i];
    if (print)
        std::cout << "checkSum:  " << checkSum << std::endl;
    return checkSum;
}

int Arr::runNumber(bool print)
{
    if (m_array == nullptr)
        return 0;
    int count = 1;
    for (int i = 1; i < m_length; ++i)
        if (m_array[i] < m_array[i - 1])
            ++count;
    if (print)
        std::cout << "runNumber: " << count << std::endl;
    return count;
}

void Arr::swap(int index1, int index2)
{
    assert(0 <= index1 && index1 < m_length);
    assert(0 <= index2 && index2 < m_length);
    int temp = m_array[index1];
    m_array[index1] = m_array[index2];
    m_array[index2] = temp;
}

int Arr::length()
{
    return m_length;
}

int &Arr::operator[](const int index)
{
    assert(0 <= index && index < m_length);
    return m_array[index];
}

void Arr::reallocate(int newLength)
{
    erase();

    assert(newLength > 0);

    allocateMemory(newLength);
    m_length = newLength;
}

void Arr::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0) {
        erase();
        return;
    }

    int *data = new int[newLength];

    if (m_length > 0) {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        for (int i = 0; i < elementsToCopy; ++i)
            data[i] = m_array[i];
    }

    delete[] m_array;

    m_array = data;
    m_length = newLength;
}
