#ifndef INCLUDED_TEMPLATES_
#define INCLUDED_TEMPLATES_

#include <limits>

template <typename Type>
inline Type max()
{
    return std::numeric_limits<Type>::max();
}

#endif
