#ifndef CHECKARRAYSORTFUNC_HPP
#define CHECKARRAYSORTFUNC_HPP

#include <libuniq/Array.hpp>

#include <functional>

/*!
 *	\brief Check if checkSum and runNumber criterias passed.
 *
 *  Checks on random array with 1000 elements (array.fillRand(1000) is used)
 *  if checkSums are equal and runNumber is equal to 1 after sorting.
 */
void checkArraySortFunc(std::function<void(Arr &)>);

#endif // #ifndef CHECKARRAYSORTFUNC_HPP
