#include "charclass.hh"

    // got a pattern 'a-b', idx at '-'
bool CharClass::validRange(TagIter iter) const 
{
    return not
        (
            predefinedBefore(*iter) || predefinedAfter(*iter) ||
            rangeAfterRange(iter)  || inversedRange(*iter)
        );
}




