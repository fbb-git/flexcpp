#ifndef INCLUDED_FLEXTYPES_
#define INCLUDED_FLEXTYPES_


class FlexTypes
{
    typedef char Alphabet;

    public:
        enum Type       // values in the Alphabet range are simple characters
        {
            UNDETERMINED__ =  1 << (8 * sizeof(Alphabet)),
            EMPTY,                              
            FINAL,
            CHARSET,                            // string contents of [ ... ]
            EOF__                               // EOF becomes a special char
        };                                      // see README

        enum RuleType
        {
            NORMAL,
            LOP_FIXED,                          // LOP rule with fixed tail
            LOP_1,                              // LOP rule with variable tail
            LOP_2,
            LOP_3,
            LOP_4
        };
};
        
#endif
