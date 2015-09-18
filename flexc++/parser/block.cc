#include "parser.hh"

void Parser::block()
{
    bool warnMissingEoln = false;

    d_block.open(d_scanner.lineNr(), d_scanner.filename());

    while (true)
    {
        int token = d_scanner.lex();

        switch (token)
        {
            case 0:
                if (not warnMissingEoln)
                {
                    warnMissingEoln = true;
                    wmsg << "missing newline: improperly ending action" <<
                            endl; 
                }
                while (d_block.close()) 
                    ;                       // append lacking closing braces
                d_block += "\n";
                d_scanner.blockEnds();
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
    // cout << "\nRETURNING BLOCK:\n" << d_block << "\n";
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
