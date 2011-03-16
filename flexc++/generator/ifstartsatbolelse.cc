//#include "generator.ih"
//
//// SUPERFLUOUS
//
//void Generator::ifStartsAtBOLelse(ostream &out) const
//{
//    if (d_useBOL)
//    {
//        key(out);
//        out <<
//            "        if (d_startsAtBOL)  // ignore the BOL, push_front ch\n"
//            "        {\n"
//            "            d_input.push_front(ch);\n"
//            "            d_startsAtBOL = false;\n"
//            "        }\n"
//            "        else\n";
//    }
//}
