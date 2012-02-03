#include "semunion.ih"

SemUnion::~SemUnion()
{
    switch (d_index)
    {
        case TEXT:
            d_str.~string();
        break;

        case PATTERN:
            d_pattern.~Pattern();
        break;

        case CHARCLASS:
            d_charClass.~CharClass();
        break;

        case INTERVAL:
            d_interval.~Interval();
        break;

        default:
        break;
    }
}
