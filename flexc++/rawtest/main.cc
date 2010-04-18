#include "main.ih"

int main(int argc, char **argv)
try
{
    Scanner scanner;

    while (scanner.lex() != -1)
        ;

}
catch (...)
{
    return 1;
}
