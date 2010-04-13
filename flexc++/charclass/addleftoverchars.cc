#include "charclass.ih"

spSemVal &CharClass::addLeftoverChars(spSemVal &cClass)
{
    CharClass &charClass = downCast<CharClass>(*cClass);
    
    charClass.addSet(charClass.d_last);
    charClass.d_last.clear();

    return cClass;
}
