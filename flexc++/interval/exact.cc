#include "interval.ih"

Interval Interval::exact(std::string const &text)
{
    size_t value = A2x(text);

cout << "EXACT VALUE: " << text << " " << value << '\n';

    Interval ret(value, value);
    return ret;
}
