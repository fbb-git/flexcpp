#include "scanner.hh"

int Scanner::block()
{
//    cout << "   SCANNER::BLOCK SEES `" << matched() << "'\n";

    accept(matched().find_first_not_of(" \t")); // remove initial blanks
    d_inBlock = true;
    return Parser::BLOCK;
}
