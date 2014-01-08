#include "parser.ih"

void Parser::addLopStartConditions()
{
    cerr << d_rules.startConditions().size() << " " << d_lopStartCondition << '\n';
    for (
        size_t nr = d_rules.startConditions().size();
            nr != d_lopStartCondition;
                ++nr
    )
        d_rules.addStartCondition("_" + to_string(nr) + "__", true);
}
