#include "generator.ih"

// called from dfarfs.cc

void Generator::storeRF(TailCount const &tailCount, 
                         pair<size_t, size_t> &final,
                         vector<RuleFlag> &rf)
{
    size_t rule = tailCount.rule();

    RuleFlag rf {rule, 0};

    rf.d_flag = 0;

    if (final.first == rule)
    {
        final.first = numeric_limits<size_t>::max();
        rf.d_flag |= FINAL | BOL;
    }

    if (final.second == rule)
    {
        final.second = numeric_limits<size_t>::max();
        rf.d_flag |= FINAL;
    }

    if (rf.d_flag != 0)
        rfs.push_back(rf);
}


