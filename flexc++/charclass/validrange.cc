#include "charclass.ih"

    // got a pattern 'a-b', idx at '-'
bool CharClass::validRange(TagIter iter) const 
{
    return not
        (
            predefinedBefore(*iter - 1) || predefinedAfter(*iter + 1) ||
            rangeAfterRange(iter)  || inversedRange(*iter)
        );
}




