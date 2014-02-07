#include "charclass.ih"

void CharClass::handleMinusAndEscape()
{
    if (d_state == RAW)
        d_type.push_back({d_str.length(), END});

    for (
        auto &begin = d_type.begin(), end = d_type.end();
            begin != end; 
                ++begin
    )
        inspect(begin);

    if (d_tag.size() && d_tag.front() == 0) // 1st char is not a range op.
        d_tag.pop_front();
    
                                            // last char is not a range op.
    if (d_tag.size() && d_tag.back() == d_str.length() - 1) 
        d_tag.pop_front();                  
}
