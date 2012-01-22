#include "semunion.ih"

SemUnion::~SemUnion()
{
    switch (d_index.first)
    {
        case STRING:
            d_str.second.~string();
        break;

        case PATTERNVAL:
            d_patternVal.second.~PatternVal();
        break;

        default:
        break;
    }
}
