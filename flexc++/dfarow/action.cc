#include "dfarow.ih"

#include <iostream>


std::string const &DFARow::action(size_t idx) const
{
    return (*d_rules)[idx].action();
}
