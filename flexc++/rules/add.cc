#include "rules.ih"

void Rules::add(bool bol, Pattern const &patternVal, 
                bool usesLOP, Pattern const &lhs, Pattern const &rhs,
                Block const &block)
{
    if (usesLOP)
    {
        Pair const &pair = patternVal.pair();

        // tailBlock: call scanner's 'lopRedo' function, switching to the
        // new lop-1 mini scanner
//        d_rules.push_back( { d_states, bol, pair, tailBlock() } );
    
        size_t ruleIdx = d_rules.size() - 1;
    
        d_finalToRule[pair.second] = ruleIdx;
    
        setRule(pair.first, ruleIdx);
    
        d_startConditions.add(ruleIdx);

        // create new lop-1 ms, add to that ms a rule matching the rhs
        // in that rule's action: if matched, then push the lhs and start the 
        // lop-2 ms. Als add a .|\n rule to lop-1. If that rule matches, add
        // one more character from ab's matched text to the input and return,
        // thus trying to match a longer tail.
        // the lop-2 ms matches a from a/b's rule. It matches, then add the
        // tail of the ab matched text to the scanner's input, and return to
        // the original ms. Finally execute the rule's action block, provided
        // by the user.

        return;
    }


    Pair const &pair = patternVal.pair();

    d_rules.push_back( { d_states, bol, pair, block } );

    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
