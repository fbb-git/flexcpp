#include "generator.ih"

void Generator::inputInterface(std::ostream &out) const
{
    string const &interface = d_options.inputInterface();

    key(out);

    if (not interface.empty())
        out << "#include \"" << interface << "\"\n";
    else
        out <<
"    class Input\n"
"    {\n"
"        std::deque<unsigned char> d_deque;  // pending input chars\n"
"        std::istream *d_in;                 // ptr for easy streamswitching\n"
"        size_t d_lineNr;                    // line count\n"
"\n"
"        public:\n"
"            Input();\n"
"            Input(std::istream *iStream);   // iStream: dynamically "
                                                                "allocated\n"
"            size_t get();                   // the next range\n"
"            void reRead(size_t ch);         // push back 'ch' (if < 0x100)\n"
"                                            // push back str from idx "
                                                                "'fmIdx'\n"
"            void reRead(std::string const &str, size_t fmIdx);\n"
"            size_t lineNr() const\n"
"            {\n"
"                return d_lineNr;\n"
"            }\n"
"            void close()                    // force closing the stream\n"
"            {\n"
"                delete d_in;\n"
"                d_in = 0;                   // switchStreams also closes\n"
"            }\n"
"\n"
"        private:\n"
"            size_t next();                  // obtain the next character\n"
"    };\n";

}
