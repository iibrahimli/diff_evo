#include "differential_evolution.h"

/*
    default parameters
*/
template <typename arg_t, typename ret_t>
differential_evolution<arg_t, ret_t>(cost<arg_t, ret_t>  target,
                                     mode                op_mode,
                                     unsigned int        nb_params)
    :   _target(target)
{}


/*
    user-supplied parameters
*/
template <typename arg_t, typename ret_t>
differential_evolution<arg_t, ret_t>(cost<arg_t, ret_t>  target,
                                     mode                op_mode,
                                     unsigned int        nb_params,
                                     arg_t               param_min,
                                     arg_t               param_max,
                                     ret_t               min_delta);


/*
    initializes internal parameters
*/
template <typename arg_t, typename ret_t>
void differential_evolution<arg_t, ret_t>::
init_internal_params()
{
    _min_delta = de::DEFAULT_MIN_DELTA;
}


/*
    setters
*/

template <typename arg_t, typename ret_t>
void differential_evolution<arg_t, ret_t>::
set_param_min(arg_t param_min)
{

}


template <typename arg_t, typename ret_t>
void differential_evolution<arg_t, ret_t>::
set_param_max(arg_t param_max)
{

}


template <typename arg_t, typename ret_t>
void differential_evolution<arg_t, ret_t>::
set_min_delta(ret_t min_delta)
{

}


/*
    returns number of iterations run
*/
template <typename arg_t, typename ret_t>
unsigned int differential_evolution<arg_t, ret_t>::
run(unsigned int   max_iters,
    bool           verbose = false)
{

}