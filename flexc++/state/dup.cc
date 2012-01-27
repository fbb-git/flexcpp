#include "state.ih"

void State::dup(State const &src, size_t next1, size_t next2)
{
    d_data.reset(src.data().dup());
    d_data->set(next1, next2);

    d_type = src.d_type;
    d_flag = src.d_flag;
    d_rule = src.d_rule;
}
