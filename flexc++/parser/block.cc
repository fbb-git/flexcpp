#include "parser.ih"

void Parser::block()
{
    d_block.open(d_scanner.lineNr(), d_scanner.filename());

cout << "PARSER::BLOCK: STARTING A BLOCK\n"    ;

    while (true)
    {
        int token = d_scanner.lex();

        switch (token)
        {
            case 0:
            return;
            
            case '{':
                d_block.open(d_scanner.lineNr(), d_scanner.filename());
            break;
            
            case '}':
                d_block.close();
            break;
    
            case '\n':
                d_block += d_matched;

                if (d_block.level() == 1)
                {
                    d_block.close();
                    d_scanner.accept(0);        // rescan the \n
                    d_scanner.blockEnds();
                    cout << "RETURNING BLOCK:\n" << d_block << "\n";
                    return;
                }

                d_block.indent();
            break;
                
            default:
                d_block += d_matched;
            break;
        }
    }
}

