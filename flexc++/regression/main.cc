#include "main.hh"

int main(int argc, char **argv)
try
{
    ifstream infile(argv[1]);

    Scanner scanner(infile);

    scanner.setDebug(argc <=  2);

    while (int token = scanner.lex())
    {
        cout << "Line: " << scanner.lineNr() << " returns " << token << ". "
                "matched `" << scanner.matched() << '\'';

        if (scanner.pattern().size())
            cout << "\t\t(@ `" << scanner.pattern() << "')";
        
        cout << '\n';

        if (token < 0)
            throw token;

        scanner.clearPattern();
    }
    cout << '\n';
}
catch (...)
{
    cout << "this regression test FAILED\n";
    return 1;
}
