#include "parser.ih"

Parser::TextType Parser::rawString()
{
    d_rawStringContents = d_scanner.rawStringContents();
    return TextType::RAWSTRING;
}
