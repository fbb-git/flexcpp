#include "generator.ih"

void Generator::storeRFC(AccCount const &accCount, 
                         pair<size_t, size_t> const &final,
                         vector<RuleFlagCount> &rfcs)
{
    RuleFlagCount rfc {accCount.rule(), 0, accCount.accCount()};

    AccCount::Type type = accCount.type();

    rfc.d_flag = 
        type & AccCount::COUNT        ? COUNT :
        type & AccCount::INCREMENTING ? INCREMENTING : 
                                        0;

    rfc.d_flag |= 
        rfc.d_rule == final.first   ? FINAL | BOL :
        rfc.d_rule == final.second  ? FINAL :
                                      0;

    if (rfc.d_flag != 0)
        rfcs.push_back(rfc);
}
