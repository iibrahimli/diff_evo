#pragma once

#include <random>


namespace de {

template <typename arg_t, typename ret_t>
class differential_evolution;


// functor, inherit and implement calc()
template <typename arg_t, typename ret_t>
struct cost
{
    virtual ret_t calc(unsigned int size, arg_t *vec);
};


// operation mode
enum mode {
    MINIMIZE,
    MAXIMIZE
};


// default values
const int    DEFAULT_MAX_ITER       = 1000;
const double DEFAULT_MIN_DELTA      = 0.0001;
const float  DEFAULT_INIT_MUT_PROB  = 0.95;
const float  DEFAULT_MUT_PROB_DECAY = 0.99;


}    // namespace de


/*
    the class
*/
template <typename arg_t, typename ret_t>
class differential_evolution
{
private:

// TODO implement param min/max vectors

    de::cost<arg_t, ret_t>  _target;           // the function to minimize/maximize
    de::mode                _mode;             // minimize / maximize
    unsigned int            _nb_params;        // number of parameters of the function
    unsigned int            _max_iter;         // maximum iterations
    arg_t                   _param_min;        // minimum parameter value
    arg_t                   _param_max;        // maximum parameter value
    ret_t                   _min_delta;        // if changes are lower than min delta, algorithm stops
    unsigned int            _pop_size;         // population size
    float                   _init_mut_prob;    // initial mutation probability                               (P)
    float                   _mut_prob_decay;   // mutation probability decay, at each step: mp *= mp_decay


public:

    /*
        default parameters
    */
    differential_evolution(de::cost<arg_t, ret_t>  target,
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


};


#include "../src/differential_evolution.cpp"