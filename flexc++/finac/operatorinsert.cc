#include "finac.ih"

ostream &operator<<(ostream &out, FinAc const &la)
{
    if (la.d_accept >= 0)
    {
        out << "accept: " << la.d_accept;
        if (la.d_info & FinAc::FINAL_STATE)
        {
            out << ", final";
            if (la.d_info & FinAc::INCREMENTING)
                out << ", inc";
        }
        out << ' ';
    }
    return out;

        //"Rule: " << la.d_rule << ", "
}

