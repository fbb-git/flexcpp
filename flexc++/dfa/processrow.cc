#include "dfa.ih"

void DFA::processRow(LARule &laRule, size_t rule, std::vector<DFARow> &rows,
                                  size_t rowIdx, bool parentFinal, 
                                  int acceptCount)
{
    if (laRule.rule() != rule)      // stop if laRule is not for this rule
        return;

    DFARow &thisRow = rows[rowIdx];
    int final = laRule.final();

    if (thisRow.hasPostAstates(rule))  // got post A states for this rule
    {
        if (laRule.accept() == 0)           // it is the first accept state
        {
            if (final == LARule::FINAL_NOT_SET)
                laRule.setFinal(0);
        }
        else
        {
            if (final == LARule::FINAL_NOT_SET && parentFinal)
                laRule.setFinal(acceptCount - 1);
            else if 
            (
                final == LARule::FINAL_NOT_SET 
                ||
                final > acceptCount
            )
                laRule.setFinal(acceptCount);
        }
        if (not laRule.inc() && not thisRow.hasPreAstates(rule))
        {
            laRule.setAccept(thisRow.maxAccept(rule));
            laRule.setInc();
            return;
        }
    }
    for_each(thisRow.map().begin(), thisRow.map().end(),
            FnWrap::unary(inspect, rowIdx, rule, rows, 
                          laRule.final() != LARule::NOT_FINAL, 
                          acceptCount + 1));
}
