#include "scanner.hh"

int Scanner::execute(bool *done)
{
    switch (ruleIndex())
    {
#include "../../tmp/bin/ACTIONS"
    }
    *done = false;
    return -1;                  // irrelevant return due to true cycle
}                               // in lookup
