#include "finacinfo.ih"

ostream &operator<<(ostream &out, FinAcInfo const &la)
{
    if (la.d_accept >= 0)
    {
        out << "accept: " << la.d_accept;
        if (la.d_info & FinAcInfo::FINAL_STATE)
        {
            out << ", final";
            if (la.d_info & FinAcInfo::INCREMENTING)
                out << ", inc";
        }
        out << ' ';
    }
    return out;

        //"Rule: " << la.d_rule << ", "
}

