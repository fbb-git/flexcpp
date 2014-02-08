#include "charclass.ih"

    // got a pattern 'a-b', idx at '-'
bool CharClass::validRange(TagIter iter) const 
{
//cerr << "VR: minus at " << *iter << '\n';

    return not
        (
            predefinedBefore(*iter) || predefinedAfter(*iter) ||
            rangeAfterRange(iter)  || inversedRange(*iter)
        );
}




