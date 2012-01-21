#include "parser.ih"

// called fm lookahead

void Parser::setFlags(size_t idx, State::Flag flag)
{
    if (idx == 0)                   // no (more) states
        return;

    State &state = d_states[idx];   // shorthand for state[idx]

    if (state.flag() == flag)       // already set (next()s can jump back!)
        return;

    state.setFlag(flag);

    setFlags(state.next1(), flag);
    setFlags(state.next2(), flag);
}
