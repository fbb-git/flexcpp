#include "pattern.ih"

Pattern Pattern::duplicate(States &states) const
{
    Map indexMap;
    Pair pair;

    pair.first = dup(indexMap, states, d_pair.first);
    pair.second = indexMap[d_pair.second];

    return Pattern(pair);
}
