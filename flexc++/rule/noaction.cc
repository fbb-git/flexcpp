#include "rule.ih"

void Rule::noAction()
{
    d_block.clear();

cerr << "block line nr was " << d_block.lineNr() << '\n';    
    d_block.setLineNr(d_block.lineNr() - 1);    // didn't see a block, but
                                                // the \n following the regex
                                                // already has been read.
cerr << "block line is was " << d_block.lineNr() << '\n';    
}
