//#include "patternval.ih"
//
//// define a pattern as a BOL pattern unless the pattern already is a
//// bol-pattern, in which case prepend a ^ char to pattern
//
//spSemVal PatternVal::bol(States &states, spSemVal &pattern)
//{
//    if (d_bolPattern)
//        ;   // prefix a ^ to pattern
//
//    d_bolPattern = true;
//
////    States::Pair pair = states.next2();
////
////    states[pair.first] = State::factory(State::BOL, pair.second, 0);
////    
////    PatternVal bolPattern(pair);
////
////    spSemVal ret = concatenate(states, bolPattern, pattern);
////    return ret;
//
//
//    return pattern;
//}
//
//
//
