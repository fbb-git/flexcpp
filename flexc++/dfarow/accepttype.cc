//X#include "dfarow.ih"
//X
//Xstring DFARow::acceptType(size_t rule) const
//X{
//X    string ret = X2a(rule).str()
//X//         + '-' +
//X//        (
//X//            acceptState(rule).accept() == State::VARIABLE_HEADSIZE ?
//X//                'V'
//X//            :
//X//                'F'
//X//        );
//X    ;
//X
//X    return ret;
//X
//X}
