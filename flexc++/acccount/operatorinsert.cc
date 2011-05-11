#include "acccount.ih"

ostream &operator<<(ostream &out, AccCount const &accCount)
{
    out << "Rule: " << accCount.d_rule << ", ";

    if (accCount.d_type & AccCount::COUNT)
        out << "COUNT ";

    if (accCount.d_type & AccCount::INCREMENTING)
        out << "INCREMENTING ";

    if (accCount.d_type & AccCount::PRE)
        out << "PRE ";

    if (accCount.d_type & AccCount::ACCEPT)
        out << "ACCEPT ";

    if (accCount.d_type & AccCount::POST)
        out << "POST ";

    if (accCount.d_type & AccCount::PROCESSED)
        out << "PROCESSED ";

    out << "count = " << accCount.d_accCount;

    return out;
}






