#include "parser.ih"

void Parser::block()
{
    size_t nested = 0;
    string block;
    
    while (true)
    {
        int token = d_scanner.lex();

cout << "       block lex() reveives: `" << d_scanner.matched() << "'\n";

        switch (token)
        {
            case 0:
            return;
            
            case '{':
                ++nested;
                block += '{';
            break;
            
            case '}':
            {
                --nested;
                size_t lastUsedPos = block.find_last_not_of(' ');
                if (lastUsedPos + 4 <= block.length())
                    block.resize(block.length() - 4);
                block += '}';
                if (nested == 0)
                {
                    d_scanner.blockEnds();
                    cout << "    RETURNING BLOCK:\n" << block << "\n";
                    return;
                }
            }
            break;
    
            case '\n':
                if (nested != 0)
                    block += '\n' + string(4 * nested, ' ');
                else
                {
                    d_scanner.pushEOLN();   // redo the newline
                    d_scanner.blockEnds();
                    cout << "RETURNING BLOCK: " << block << "\n";
                    return;
                }
            break;
                
            default:
                block += d_scanner.matched();
            break;
        }
    }
}

