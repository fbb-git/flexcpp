#include "ranges.ih"

#include <iostream>
#include <iomanip>
#include <cctype>

void Ranges::display(char const *hdr) const
{
    cout << hdr << "\n"
            "Nsubsets: " << d_subsets << '\n';

    for (size_t idx = 0, last = UINT_MAX, count = 0; idx < 256; ++idx)
    {
        if (d_ranges[idx] != last)
        {
            last = d_ranges[idx];

            if (idx != 0)
            {
                cout << " - ";
    
                cout << setw(3) << idx - 1;
                if (isprint(idx - 1))
                    cout << "('" << static_cast<char>(idx - 1) << "')";
                else
                    cout << "     ";
                cout << '\n';
            }

            cout << setw(2) << ++count << ": " << setw(3) << idx;
            if (isprint(idx))
                cout << "('" << static_cast<char>(idx) << "')";
            else
                cout << "     ";
        }
    }

    cout << " - 255\n";
}

