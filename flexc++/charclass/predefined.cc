#include "charclass.ih"

CharClass CharClass::predefined(string const &predef)
{
    CharClass ret(CharRange::predefined(predef));

//        cout << "PREDEFINED: `" << predef << "'\n" <<
//                            downCast<CharClass>(*ret).str() << '\n';
    return ret;
}
