#include "patternval.ih"

spSemVal PatternVal::str(States &states, string const &rawStr)
{
    string &&str = String::unescape(rawStr);
    size_t length = str.length();

    States::Pair pair;
    spSemVal ret;

    if (length == 0)            // pathological case: string without contents
    {
        pair = states.next2();
        states[pair.first] = State::factory(State::EMPTY, pair.second, 0);

        ret.reset(new PatternVal(pair));
        return ret;
    }

    size_t *indices = states.next(length + 1);
    pair = States::Pair(*indices, indices[length]);

    for (size_t idx = 0; idx != length; ++idx)
        states[indices[idx]] = State::factory(str[idx], indices[idx + 1]);

    delete [] indices;

    ret.reset(new PatternVal(pair));
    return ret;
}
