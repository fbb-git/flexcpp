#include "semunion.ih"

SemUnion::SemUnion(SemUnion const &other)
{
    switch (d_index = other.d_index)
    {
        case TEXT:
            new (&d_str) std::string(other.d_str);
        break;

        case PATTERN:
            new (&d_pattern) Pattern(other.d_pattern);
        break;

        case CHARCLASS:
            new (&d_charClass) CharClass(other.d_charClass);
        break;

        case INTERVAL:
            new (&d_interval) Interval(other.d_interval);
        break;

        default:
        break;
    }
}
