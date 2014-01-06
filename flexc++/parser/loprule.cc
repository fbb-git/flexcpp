// #include "parser.ih"
// 
// void Parser::lopRule(LopRule &rule)
// {
//         // Keep a copy of the lhs expression, the begin of the rhs expression
//         // and concatenate a/b into ab:
// 
//                     // Save a duplicate of the lhs
//     Pattern lhs(rule.pattern().duplicate(d_states));
// 
//                     // keep the first state of the rhs
//     Pair rhs = rule.pattern().rhs();
// 
//                     // comcatenate lhs-rhs
//     Pattern concat(
//                 Pattern::concatenate(
//                     d_states, 
//                     rule.pattern(), 
//                     Pattern(rule.pattern().rhs())
//                 )
//             );
// 
//                 // define 1st startconditionname
//     string startCond1 = "_" + to_string(d_lopStartCondition++) + "_1__";
//     d_rules.addStartCondition(startCond1, true);    // add a new start
//                                                     // condition name
// 
//                 // define 2nd startconditionname
//     string startCond2 = "_" + to_string(d_lopStartCondition++) + "_2__";
// 
//     // now switch to the 2nd LOP start condition
//     
// //    size_t scNr = 
// //        d_rules.addStartCondition(startCond2, true);    // add a new start
// //                                                        // condition name
// //
// //    rule.block() += "lop1__(" + to_string(scNr) + ");\n";
// //
// //    d_rules.add(false, concat, rule.block()); // add the lop rule's 
// //                                                    // details
// //
//     
// }
// 

