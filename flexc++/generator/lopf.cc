#include "generator.ih"

void Generator::lopf(ostream &out) const
{
    out << 
"void " << d_baseclassScope << R"(lopf__(size_t tail)
{
    tail = length() - tail;
    push(d_matched.substr(tail, std::string::npos));
    d_matched.resize(tail);
    d_atBOL = length() && d_matched.back() == '\n';
}
)";     

} // lopf
