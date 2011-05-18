#include "tailcount.ih"

ostream &operator<<(ostream &out, TailCount const &tailCount)
{
    out << "Rule: " << tailCount.d_rule << ", ";

    if (tailCount.d_type & TailCount::COUNT)
        out << "COUNT ";

    if (tailCount.d_type & TailCount::INCREMENTING)
        out << "INCREMENTING ";

    if (tailCount.d_type & TailCount::PRE)
        out << "PRE ";

    if (tailCount.d_type & TailCount::ACCEPT)
        out << "ACCEPT ";

    if (tailCount.d_type & TailCount::POST)
        out << "POST ";

    if (tailCount.d_type & TailCount::PROCESSED)
        out << "PROCESSED ";

    out << "count = " << tailCount.d_tailCount;

    return out;
}






