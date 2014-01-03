#include "pattern.ih"

    // text without (d)quotes, accepted as-is
Pattern Pattern::rawText(States &states, std::string const &str)
{
    size_t length = str.length();

    Pattern ret;

    if (length == 0)            // pathological case: string without contents
    {
        States::Pair pair = states.next2();
        states[pair.first] = State::factory(EMPTY, pair.second, 0);

        ret = pair;
        return ret;
    }

    size_t *indices = states.next(length + 1);
    States::Pair pair = States::Pair(*indices, indices[length]);

    for (size_t idx = 0; idx != length; ++idx)
        states[indices[idx]] = State::factory(str[idx], indices[idx + 1]);

    delete [] indices;

    ret = pair;
    return ret;
}





