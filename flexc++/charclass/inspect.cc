#include "charclass.hh"

    // begin = *iter is the index of the 1st char in the current section of
    //               d_str 
    // end = *(iter + 1) is the index of the 1st char in the next section
    // from idx = begin until reaching (or passing) end:
    // find minusIdx: find a \-, or end
    // destLen = destStr.length(), append unescape from idx to minusIdx, 
    // tag minuses in destStr from destLen
    // if minusIdx == end: done
    // add - to destStr
    
void CharClass::inspect(TypeVector::iterator iter)
{
    if (iter->second != CHAR)           // only process CHAR ranges
        return;


    size_t begin = iter->first;         // the begin of this part
    size_t end = (iter + 1)->first;     // the end of this part

    string destStr;
    size_t minusIdx = begin;
    size_t subStrBegin = begin;

    while (true)
    {
        minusIdx = min(end, d_str.find("\\", minusIdx));

                                        // not a literal minus: continue
        if (minusIdx != end && d_str[minusIdx + 1] != '-')
        {
            minusIdx += 2;
            continue;
        }

        size_t destLen = destStr.length();

        destStr += String::unescape(d_str.substr(subStrBegin, 
                                                 minusIdx - subStrBegin));

        tagMinuses(begin, destStr, destLen);

        if (minusIdx == end)
            break;

        destStr += '-';

        subStrBegin = minusIdx += 2;
    }

    replace(destStr, iter, end);
}





