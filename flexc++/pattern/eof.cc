#include "pattern.ih"

Pattern Pattern::eof(States &states)
{
    Pair pair = states.next2();

    states[pair.first] = State(EOF__, pair.second, 0);

    Pattern ret(pair);
    return ret;
}
