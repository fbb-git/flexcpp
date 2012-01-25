#include "semunion.ih"

SemUnion::SemUnion(SemUnion const &other)
{
    switch (other.d_index.first)
    {
        case DataType::TEXT:
            new (&d_str) std::pair<int, std::string>(other.d_str);
        break;

        case DataType::PATTERNVAL:
            new (&d_patternVal) 
                            std::pair<int, PatternVal>(other.d_patternVal);
        break;

        case DataType::CHARCLASS:
            new (&d_charClass) std::pair<int, CharClass>(other.d_charClass);
        break;

        case DataType::INTERVAL:
            new (&d_interval) std::pair<int, Interval>(other.d_interval);
        break;

        default:
            d_index = other.d_index;
        break;
    }
}
