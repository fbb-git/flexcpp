#include "logic.ih"

spSemVal Logic::value(bool logic)
{
    spSemVal ret { new Logic(logic) };
    return ret;
}
