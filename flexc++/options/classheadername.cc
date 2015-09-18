#include "options.hh"

std::string Options::classHeaderName() const
{
    size_t pos = d_classHeader.rfind('/');

    return pos == string::npos ? 
                        d_classHeader 
                    :
                        d_classHeader.substr(pos + 1);
}
