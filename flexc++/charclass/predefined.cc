#include "charclass.ih"

spSemVal CharClass::predefined(string const &predef)
{
    spSemVal ret(new CharClass(CharRange::predefined(predef)));

//        cout << "PREDEFINED: `" << predef << "'\n" <<
//                            downCast<CharClass>(*ret).str() << '\n';
    return ret;
}
