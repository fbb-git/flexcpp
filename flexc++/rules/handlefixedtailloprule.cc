#include "rules.ih"

void Rules::handleFixedTailLopRule(Rule &rule)
{
    auto const &block = rule.block();
    auto const &pattern = rule.pattern();

                                        // change the LOP rule's action into 
                                        // calling lop_f, passing it the 
                                        // lop's tail length
    Block workBlock(block.lineNr(), block.filename());
    workBlock += "lopf_(" + to_string(pattern.lopTailLength()) + ");" ;
    workBlock += "\n";                  // new line, and
    workBlock.addContents(block);       // add the LOP rule's action block

    rule.assignBlock(workBlock);
}







