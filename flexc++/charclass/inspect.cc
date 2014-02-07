#include "charclass.ih"

void CharClass::inspect(TypeVector::iterator iter)
{
    if (iter->second != CHAR)           // only process CHAR ranges
        return;

    size_t end = (iter + 1)->first;     // the end of this part
    size_t begin = iter->first;         // the begin of this part
    size_t orgLen = end - begin;

    string str;

    size_t nextIdx = begin;
    size_t lengthSoFar = 0;
    size_t idx = nextIdx;
    while ((idx = d_str.find("\\", idx)) < end) // visit all characters
    {
        if (d_str[idx + 1] != '-')      // not a literal minus: continue
        {
            idx += 2;
            continue;
        }

        // at a literal minus

        lengthSoFar = begin + str.length();

                                            // unescape what's before \-
        str += String::unescape(d_str.substr(begin, idx - begin));

                                            // find all - char locations in 
        addMinuses(lengthSoFar, str);       // the just added string

        str += '-';                         // add - as a character

        idx += 2;                           // continue beyond the \-
        nextIdx = idx;
    }

    lengthSoFar = begin + str.length();
                                            // add any trailing chars fm d_str
    str += String::unescape(d_str.substr(nextIdx, end - nextIdx));
    addMinuses(lengthSoFar, str);           // and store their - locations

    size_t reduction = orgLen - str.length();  
    if (reduction > 0)
    {
        d_str.replace(begin, orgLen, str);  // replace the original str by the
                                            // unescaped str.

        for (++iter; iter != d_type.end(); ++iter)
            iter->first -= reduction;
    }
}
