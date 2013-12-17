int main()
{
    ScannerStreambuf buf(cin);
    istream in(&buf);

    string line;

    Scanner scanner(in);                // define a Scanner object

    while (int token = scanner.lex())   // get all tokens
    {
        string const &text = scanner.matched();
        switch (token)
        {
            case IDENTIFIER:
                cout << "identifier: " << text << '\n';
            break;

            case NUMBER:
                cout << "number: " << text << '\n';
            break;

            case SIGNAL:
            {
                cout << 
                        '\n' <<
                        scanner.line() << 
                        setw(scanner.column()) << '^' << "\n"
                        "Line " << scanner.lineNr() << ", column " <<
                        scanner.column() << 
                                ": saw `" << scanner.matched() << "'\n\n";
            }
            break;

            default:
                cout << "char. token: `" << text << "'\n";
            break;
        }
    }
}

