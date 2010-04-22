// #include "scannerbase.ih"
// 
// bool ScannerBase::callExecute()
// {
//     updateAcceptCounts();
// 
//     if (plainChar())
//     {
//         if (transition())
//         {
//             msg(2) << "Adding char to match\n";
//             d_match += d_char;
//         }
//         else
//         {
//             msg(2) << "Pusing char on to the queue for reprocessing\n";
//             d_deque.push_front(d_char);
//         }
//     }
// 
//     atEndOfRule();
// 
//     bool call = ruleAvailable() && (interactiveReturn() || noTransition());
// 
//     if (!call)
//         msg(2) << "Not calling execute\n";
//     else
//         msg(1) << "Calling execute for rule " << d_ruleIndex << 
//                     ". LAsize = " << d_accept[d_ruleIndex].LAsize << 
//                     ", Matched: '" << d_match << "'\n";
// 
//     return call;
// }
