#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <initializer_list>

/*!
 * Main array-like class with necessary functions for
 * exercices with sorts and searches.
 */
class Arr
{
public:
    Arr();

    ~Arr();

    /*!
     *  \param[in] length Length of the array
     */
    Arr(int length);

    Arr(const std::initializer_list<int> &list);

    //! Deallocate memory of the array, set length to zero
    void erase();

    //! Erase and set range to defaults
    void reset();

    //! Print the array
    void print();

    //! Get length of the array
    int length();

    /*! Erase data and reallocate
     *
     *  \param[in] length Length of the array
     */
    void reallocate(int length);

    /*! Save data and change size (slow).
     *
     *  \param[in] length Length of the array.
     */
    void resize(int length);

    /*! Set range of random generation.
     *
     *  \param[in] min Minimal generating number.
     *  \param[in] max Maximal generating number.
     */
    void setRange(int min, int max);

    /*! \brief Fill Array with random numbers.
     *
     * Use range from min to max, if it was set manually by setRange
     * (if min != max). Otherwise, using min = 0 and max = length*2.
     *
     * \param[in] length Length of the array.
     */
    void fillRand(int length);

    /*! \brief Fill Array with decreasing numbers.
     *
     * Numbers from (length) to 1.
     *
     * \param[in] length Length of the array.
     */
    void fillDec(int length);

    /*! \brief Fill Array with increasing numbers.
     *
     * Numbers from 1 to (length).
     *
     * \param[in] length Length of the array.
     */
    void fillInc(int length);

    /*! \brief Count check sum of the array
     *
     *  \param[in] print=false If is true, print the check sum
     *
     *  \return Sum of all elements in the array
     */
    int checkSum(bool print = false);

    /*! \brief Count number of runs
     *
     *  Count number of non-decreasing subsequence of the array.
     *
     *  \param[in] print=false If is true, print the number of runs.
     *
     *  \return Number of runs.
     */
    int runNumber(bool print = false);

    /*! \brief Swap two elements in the array
     *
     *  \param[in] index1 Index of the first element to swap
     *  \param[in] index2 Index of the second element to swap
     */
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
