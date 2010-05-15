#include "rule.ih"

int Rule::maxAccept(States const &states) const
{
    size_t maxState = *max_element(d_postAstates.begin(), d_postAstates.end(),
                                   FnWrap::binary(cmpAccept, states));

    return states[maxState].accept();
}
