#include "Array.hpp"

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
    assert(min < max);
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

void Arr::reset()
{
    delete[] m_array;
    m_array = nullptr;
    m_length = 0;
}

void Arr::print()
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_array[i] << " ";
    std::cout << std::endl;
}

int Arr::checkSum()
{
    int checkSum = 0;
    for (int i = 0; i < m_length; ++i)
        checkSum += m_array[i];
    std::cout << "checkSum:  " << checkSum << std::endl;
    return checkSum;
}

int Arr::runNumber()
{
    int count = 1;
    for (int i = 1; i < m_length; ++i)
        if (m_array[i] < m_array[i - 1])
            ++count;
    std::cout << "runNumber: " << count << std::endl;
    return count;
}
