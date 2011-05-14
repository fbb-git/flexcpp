#include "generator.ih"

void Generator::dfaRFCs(DFARow const &row, ostream &out, 
                        vector<RuleFlagCount> &rfc)
{
    out << setw(2) << rfc.size() << ',';        // begin index in s_rfc

    for_each(row.accCounts().begin(), row.accCounts().end(), 
             FnWrap::unary(storeRFC, row.final(), rfc));

    out << setw(2) << rfc.size();               // end index in s_rfc
}







