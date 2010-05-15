#include "larule.ih"

ostream &operator<<(ostream &out, LARule const &la)
{
    if (la.d_accept >= 0)
    {
        out << "accept: " << la.d_accept;
        if (la.d_final >= 0)
        {
            out << ", final: " << la.d_final;
            if (la.d_inc)
                out << ", inc: " << boolalpha << la.d_inc << noboolalpha;
        }
    }
    return out;

        //"Rule: " << la.d_rule << ", "
}

