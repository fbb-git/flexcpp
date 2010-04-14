#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

class DFARow
{
    size_t d_finalRule;
    
    public:
        DFARow(States const &states );

        void transitions(std::vector<std::set<size_t>> &stateSet, 
                         std::set<size_t> const &rowSet,
                         size_t nRanges)
    private:
        static void transit(size_t stateIdx,
                            DFARow &dfaRow, 
                            std::vector<std::set<size_t>> &stateSet,
                            std::set<size_t> const &rowSet,
                            size_t nRanges);

};
        
#endif
