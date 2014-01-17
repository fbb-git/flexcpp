#include "rules.ih"

void Rules::handleFixedTailLopRule(Rule &rule)
{
    d_usesFixedLOPtails = true;

    auto const &block = rule.block();
    auto const &pattern = rule.pattern();

                                        // change the LOP rule's action into 
                                        // calling lop__f, passing it the 
                                        // lop's tail length
    Block workBlock(block.lineNr() - 1, block.filename());
    workBlock += "lopf__(" + to_string(pattern.lopTailLength()) + ");" ;
    workBlock += "\n";                  // new line, and
    workBlock.addContents(block);       // add the LOP rule's action block

    rule.assignBlock(workBlock);
}







