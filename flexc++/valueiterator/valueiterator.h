#ifndef INCLUDED_VALUEITERATOR_
#define INCLUDED_VALUEITERATOR_

#include <iterator>
#include <limits>

template <typename Type>
class ValueIterator: public std::iterator<std::input_iterator_tag, Type>
{
    Type d_value;
    public:
        ValueIterator(Type const &value);

        ValueIterator<Type> &operator++();
        ValueIterator<Type> operator++(int);
        bool operator==(ValueIterator const &other) const;
        bool operator!=(ValueIterator const &other) const;
        Type const &operator*() const;

        static ValueIterator<Type> min();
        static ValueIterator<Type> max();
};

template <typename Type>
inline ValueIterator<Type> ValueIterator<Type>::min()
{
    return ValueIterator<Type>(numeric_limits<Type>::min());
}

template <typename Type>
inline ValueIterator<Type> ValueIterator<Type>::max()
{
    return ValueIterator<Type>(numeric_limits<Type>::max());
}

template <typename Type>
inline ValueIterator<Type>::ValueIterator(Type const &value)
:
    d_value(value)
{}
 
template <typename Type>
inline ValueIterator<Type> &ValueIterator<Type>::operator++()
{
    ++d_value;
    return *this;
}
       
template <typename Type>
inline ValueIterator<Type> ValueIterator<Type>::operator++(int)
{
    ValueIterator<Type> tmp(d_value++);
    return tmp;
}
       
template <typename Type>
inline bool ValueIterator<Type>::operator==(ValueIterator const &rhs) const
{
    return d_value == rhs.d_value;
}

template <typename Type>
inline bool ValueIterator<Type>::operator!=(ValueIterator const &rhs) const
{
    return d_value != rhs.d_value;
}

template <typename Type>
inline Type const &ValueIterator<Type>::operator*() const
{
    return d_value;
}

#endif






