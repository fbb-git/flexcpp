#include "charclass.ih"

void CharClass::inspect(vector <size_t> &tag, TypeVector::iterator iter)
{
    if (iter->second != CHAR)
        return;

    size_t length = (iter + 1)->first - iter->first;
    
    while ((idx = d_str.find("\\", idx)) != string::npos)
    {
        if (match[idx + 1] != '-')
        {
            idx += 2;
            continue;
        }
                                            // at idx: \-

                                            // unescape what's before \-
        size_t lengthBefore = str
        str += String::unescape(match.substr(begin, idx - begin));

                                            // find all - char locations in 
        addMinuses(tag, length, str);       // the just added string

        str += '-';                         // add - as a character
        length = str.length();              // update length

        idx += 2;                           // continue beyond the \-
        begin = idx;
    }

}
