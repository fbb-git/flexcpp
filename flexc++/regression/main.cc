#include "main.ih"

int main(int argc, char **argv)
try
{
    ifstream infile(argv[1]);

    Scanner scanner(infile);

    scanner.setDebug(argc <=  2);

    while (int token = scanner.lex())
    {
        cout << "Line: " << scanner.lineNr() << " returns " << token << ". "
                "matched `" << scanner.match() << "'.";

        if (scanner.pattern().size())
            cout << "\t\t(@ `" << scanner.pattern() << "')";
        
        cout << '\n';

        scanner.clearPattern();
    }
    cout << '\n';
}

catch (...)
{
    return 1;
}
