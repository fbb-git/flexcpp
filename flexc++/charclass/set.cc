#include "charclass.ih"

set<char> CharClass::set()
{
    std::set<char> dest;

    if (d_str.empty())
        return dest;

    handleMinusAndEscape();

//cerr << "# tags: " << d_tag.size() << " 1st: " << d_tag.front() << " last " 
//<< d_tag.back() << '\n';

    size_t from = 0;
    for (auto iter = d_tag.begin(), end = d_tag.end(); iter != end; ++iter)
    {
        if (not validRange(iter))               // Error pattern a-b-c or 
            return dest;                        // bordering predefined

        addChars(dest, from, *iter - 1);        // add fm 'from' to 'idx - 1'
        addRange(dest, *iter);                  // add the range of chars
        from = *iter + 2;
    }

    addChars(dest, from, d_str.size());         // add the remaining chars

    return dest;
}





