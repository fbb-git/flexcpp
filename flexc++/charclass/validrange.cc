#include "charclass.ih"

    // got a pattern 'a-b', idx at '-'
bool CharClass::validRange(size_t idx) const 
{
    return not
        (
            predefinedBefore(idx) || predefinedAfter(idx) ||
            rangeAfterRange(idx)  || inversedRange(idx)
        );
}




