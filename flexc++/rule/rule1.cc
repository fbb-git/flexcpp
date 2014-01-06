#include "rule.ih"

Rule::Rule(States &states, bool bol, Pattern const &pattern,
           Block const &block)
:
    d_block(block),
    d_bol(bol),
    d_viable(false)
{
    if (not pattern.isLopPattern())
    {
        d_lop = 0;
        d_pair = pattern.pair();
        return;
    }


    d_lop = new LopData;                    // LOP-pattern below

                                            // Duplicate the lhs
    Pattern lhs(pattern.duplicate(states));

    d_lop->lhs = lhs.pair();                    // store the dup's indices

    d_lop->mid = pattern.rhs().pair().first;    // 1st state or the rhs

                 
    Pattern concat(                         // comcatenate lhs-rhs
                Pattern::concatenate(states, pattern, pattern.rhs())
            );

    d_pair = concat.pair();
}

