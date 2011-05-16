#include "generator.ih"

// called from dfarfcs.cc

void Generator::storeRFC(AccCount const &accCount, 
                         pair<size_t, size_t> &final,
                         vector<RuleFlagCount> &rfcs)
{
    size_t rule = accCount.rule();

    RuleFlagCount rfc {rule, 0, accCount.accCount()};

    AccCount::Type type = accCount.type();

    rfc.d_flag = 
        type & AccCount::COUNT        ? COUNT :
        type & AccCount::INCREMENTING ? INCREMENTING : 
                                        0;

    if (final.first == rule)
    {
        final.first = UINT_MAX;
        rfc.d_flag |= FINAL | BOL;
    }

    if (final.second == rule)
    {
        final.second = UINT_MAX;
        rfc.d_flag |= FINAL;
    }

    if (rfc.d_flag != 0)
        rfcs.push_back(rfc);
}


