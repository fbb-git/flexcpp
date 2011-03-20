#include "main.ih"

int main(int argc, char **argv)
try
{
    ifstream infile(argv[1]);

    Scanner scanner(infile);

    scanner.setDebug(argc <=  2);

    while (int token = scanner.lex())
    {
        cout << "    Pattern " << scanner.pattern() << ": ";

        if (token == -1)
            cout << "UNEXPECTED input `";
        else
            cout << "lex() returns " << token << ". "
                "matched `";

        cout << scanner.match() << "'\n";
    }
    cout << '\n';
}

catch (...)
{
    return 1;
}
