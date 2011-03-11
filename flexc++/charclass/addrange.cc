#include "charclass.ih"

void CharClass::addRange(char from, char to)
{
    if (from > to)
        emsg << '`' << from << "' beyond `" << to << "' in character set" << 
                                                                        endl;
    else
    {
        for (; from <= to; ++from)
            d_set.insert(from);
    }

    d_last.erase();
}
