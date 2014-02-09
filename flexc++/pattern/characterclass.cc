#include "pattern.ih"

Pattern Pattern::characterClass(States &states, CharClass &charClass)
{
    Pair pair = states.next2();

    states[pair.first] = State(CHARSET, charClass.str(), pair.second);

    Pattern ret(pair);

    ret.d_length = not charClass.empty();

    return ret;
}
