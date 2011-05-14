//#include "generator.ih"
//
//void Generator::finAcs(ostream &out) const
//{
//    string const &className = d_options.className();
//
//    out << 
//        "int const " << className << "Base::s_finAc[][4] =\n"
//        "{\n"
//        "//     R  F  T  I\n";
//
//    size_t idx = 0;
//    for_each(d_finacs.begin(), d_finacs.end(), 
//                                        FnWrap::unary(outFinAc, out, idx));
//    out << "};";
//}
