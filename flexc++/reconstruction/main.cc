#include "main.ih"

int main(int argc, char **argv)
try
{
    Parser parser(argc > 1);

    parser.setScannerDebug(argc > 2);

    parser.setDebug(argc > 3);
    
    parser.parse();

    cout << "Parsing Status: " << parser.status() << '\n';
}
catch (exception const &err)
{
    cout << err.what() << '\n';
    return 1;
}

