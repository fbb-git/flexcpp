#include "semunion.ih"

SemUnion::SemUnion(SemUnion const &other)
{
    switch (other.d_index.first)
    {
        case STRING:
            new (&d_str) std::pair<int, std::string>(other.d_str);
        break;

        case PATTERNVAL:
            new (&d_patternVal) 
                            std::pair<int, PatternVal>(other.d_patternVal);
        break;

        default:
            d_index = other.d_index;
        break;
    }
}
