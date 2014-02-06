#include "charclass.ih"

set<char> CharClass::set() const
{
    std::set<char> dest;

cerr << "SET IN\n";
for (auto pair: d_chars)
    if (isprint(pair.first))
        cout << pair.first << " (" << pair.second << ") ";
cout << ' ';
for (auto pair: d_chars)
    if (not isprint(pair.first))
        cout << (int)pair.first << " (" << pair.second << ") ";
cout << '\n';


    if (d_chars.empty())
        return dest;

    if (d_chars.front().second == MINUS)        // first/last chars are never
        d_chars.front().second = CHAR;          // RANGE minuses.

    if (d_chars.back().second == MINUS)
        d_chars.back().second = CHAR;

    size_t start = 1;
    while (size_t idx = findRange(start))       // find the next RANGE 
    {
        if (not validRange(idx))                // Error pattern a-b-c or 
            return dest;                        // bordering predefined

        addChars(dest, start, idx - 1);         // add fm 'start' to 'idx - 1'
        addRange(dest, idx);                    // add the range of chars

        start = min(d_chars.size(), idx + 2);   // continue beyond the range
    }
    addChars(dest, start, d_chars.size());      // add the remaining chars

    cout << "SET OUT\n";
    for (char ch: dest)
        if (isprint(ch))
            cout << ch;
    cout << ' ';
    for (char ch: dest)
        if (not isprint(ch))
            cout << (int)ch;
    cout << '\n';

    return dest;
}





