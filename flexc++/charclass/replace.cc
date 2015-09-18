#include "charclass.hh"

void CharClass::replace(string newStr, TypeVector::iterator iter, size_t end)
{
    size_t orgLen = end - iter->first;

    if (orgLen == newStr.length())
        return;

    d_str.replace(iter->first, orgLen, newStr); // replace the original str 
                                                // by the unescaped str.

    size_t reduction = orgLen - newStr.length();

    for (++iter; iter != d_type.end(); ++iter)
        iter->first -= reduction;
}
