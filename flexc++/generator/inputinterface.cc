#include "generator.ih"

void Generator::inputInterface(std::ostream &out) const
{
    string const &interface = d_options.inputInterface();

    key(out);

    if (not interface.empty())
        out << "#include \"" << interface << "\"\n";
    else
        out <<
R"(
    class Input
    {
        std::deque<unsigned char> d_deque;  // pending input chars
        std::istream *d_in;                 // ptr for easy streamswitching
        size_t d_lineNr;                    // line count

        public:
            Input();
                                       // iStream: dynamically allocated
            Input(std::istream *iStream, size_t lineNr = 1);
            size_t get();                   // the next range
            void reRead(size_t ch);         // push back 'ch' (if < 0x100)
                                            // push back str from idx 'fmIdx'
            void reRead(std::string const &str, size_t fmIdx);
            size_t lineNr() const
            {
                return d_lineNr;
            }
            size_t nPending() const
            {
                return d_deque.size();
            }
            void setPending(size_t size)
            {
                d_deque.erase(d_deque.begin(), d_deque.end() - size);
            }
            void close()                    // force closing the stream
            {
                delete d_in;
                d_in = 0;                   // switchStreams also closes
            }

        private:
            size_t next();                  // obtain the next character
    };
)";     
// >>>> R"( section ends <<<<

}
