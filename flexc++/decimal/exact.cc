#include "decimal.ih"

spSemVal Decimal::exact(std::string const &text)
{
    size_t value = A2x(text);

    spSemVal ret {new Decimal(value, value)};
    return ret;
}
