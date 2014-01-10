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
            LOP_1,                          // LOP rule
            LOP_2,
            LOP_3,
            LOP_4
        };
};
        
#endif
