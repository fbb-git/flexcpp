#include "pattern.ih"

Pattern Pattern::dot(States &states)
{
    CharClass charClass;
    charClass.append(vector<string>(1, CharClass::predefined(".")));

    Pattern ret = characterClass(states, charClass);
    ret.d_length = 1;
    return ret;
}
