#include "pattern.hh"

    // text without (d)quotes, accepted as-is
Pattern Pattern::rawText(States &states, std::string const &str)
{
    size_t length = str.length();

    Pattern ret;

    ret.d_length = length;

    if (length == 0)            // pathological case: string without contents
    {
        Pair pair = states.next2();
        states[pair.first] = State(EMPTY, pair.second, 0);

        ret = pair;
        return ret;
    }

    size_t *indices = states.next(length + 1);
    Pair pair = Pair(*indices, indices[length]);

    for (size_t idx = 0; idx != length; ++idx)
        states[indices[idx]] = State(str[idx], indices[idx + 1]);

    delete [] indices;

    ret = pair;
    return ret;
}





