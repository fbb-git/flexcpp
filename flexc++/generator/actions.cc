//#include "generator.ih"
//
//void Generator::actions(ostream &out) const
//{
//    key(out);
//
//    size_t idx = 0;
//    for_each(d_rules.ruleBegin(), d_rules.ruleEnd(),
//             FnWrap::unary(ruleAction, out, idx, d_lineDirectives));
//}
