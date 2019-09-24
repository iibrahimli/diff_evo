#include "differential_evolution.h"

/*
    default parameters
*/
template <typename arg_t, typename ret_t>
differential_evolution::differential_evolution(de::cost<arg_t, ret_t>  target,
                        de::mode                op_mode,
                        unsigned int            nb_params);


/*
    user-supplied parameters
*/
differential_evolution(de::cost<arg_t, ret_t>  target,
                        de::mode                op_mode,
                        unsigned int            nb_params,
                        arg_t                   param_min,
                        arg_t                   param_max,
                        ret_t                   min_delta);


/*
    initializes internal parameters
*/
void init_internal_params();


/*
    setters
*/

void set_param_min(arg_t param_min);


void set_param_max(arg_t param_max);


void set_min_delta(ret_t min_delta);


/*
    returns number of iterations run
*/
unsigned int run(unsigned int   max_iters,
                    bool           verbose = false);