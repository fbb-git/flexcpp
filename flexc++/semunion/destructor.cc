#include "semunion.ih"

SemUnion::~SemUnion()
{
    switch (d_index.first)
    {
        case DataType::TEXT:
            d_str.second.~string();
        break;

        case DataType::PATTERN:
            d_patternVal.second.~Pattern();
        break;

        case DataType::CHARCLASS:
            d_charClass.second.~CharClass();
        break;

        // Interval does not allocate memory. Destructor call not needed.

        default:
        break;
    }
}
