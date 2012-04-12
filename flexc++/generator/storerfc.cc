#include "generator.ih"

// called from dfarfcs.cc

void Generator::storeRFC(TailCount const &tailCount, 
                         pair<size_t, size_t> &final,
                         vector<RuleFlagCount> &rfcs)
{
    size_t rule = tailCount.rule();

    RuleFlagCount rfc {rule, 0, tailCount.tailCount()};

    TailCount::Type type = tailCount.type();

    rfc.d_flag = 
        type & TailCount::COUNT        ? COUNT :
        type & TailCount::INCREMENTING ? INCREMENTING : 
                                        0;

    if (final.first == rule)
    {
        final.first = numeric_limits<size_t>::max();
        rfc.d_flag |= FINAL | BOL;
    }

    if (final.second == rule)
    {
        final.second = numeric_limits<size_t>::max();
        rfc.d_flag |= FINAL;
    }

    if (rfc.d_flag != 0)
        rfcs.push_back(rfc);
}


