#include "scanner.ih"

int Scanner::execute(bool *cycle)
{
    switch (ruleAction())
    {
#include "../../tmp/bin/ACTIONS"
    }
    *cycle = true;
    return -1;                  // irrelevant return due to true cycle
}                               // in lookup
