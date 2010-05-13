#include "rule.ih"

int Rule::maxAccept() const
{
    return *max(d_postAstates.begin(), d_postAstates.end());
}
