#include "options.ih"

std::string Options::implementationHeaderName() const
{
    size_t pos = d_implementationHeader.rfind('/');

    return pos == string::npos ? 
                        d_implementationHeader
                    :
                        d_implementationHeader.substr(pos + 1);
}
