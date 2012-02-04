#include "scanner.ih"

int Scanner::handleDecimal()
{
    cout << "in charclass: " << boolalpha << d_inCharClass <<
            ", acceptIdentifier: " << d_acceptIdentifier << '\n';

    if (d_inBlock || d_inCharClass || d_acceptIdentifier)
        return Parser::DECIMAL;

    accept(1);
    return Parser::CHAR;
}
