#ifndef CHECKARRAYSORTFUNC_HPP
#define CHECKARRAYSORTFUNC_HPP

#include <libuniq/Array.hpp>

#include <functional>

//! \file checkArraySortFunc.hpp

/*! \fn void checkArraySortFunc(std::function<void(Arr &)>)
 *	\brief Check if Arr::checkSum() and Arr::runNumber() criterias passed.
 *
 *  Checks on random array with 1000 elements ( Arr::fillRand() is
 *  used) if check sums are equal and Arr::runNumber() is equal to 1 after
 *  sorting.
 */
void checkArraySortFunc(std::function<void(Arr &)>);

#endif // #ifndef CHECKARRAYSORTFUNC_HPP
