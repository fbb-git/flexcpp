#include "rule.ih"

int Rule::maxAccept(States const &states) const
{
    return *max_element(d_postAstates.begin(), d_postAstates.end(),
                        FnWrap::binary(cmpAccept, states));
}
