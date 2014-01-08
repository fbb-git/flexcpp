#include "parser.ih"

void Parser::addLopStartConditions()
{
    for (
        size_t nr = d_rules.startConditions().size();
            nr != d_lopStartCondition;
                ++nr
    )
        d_rules.addStartCondition("_" + to_string(nr) + "__", true);
}
