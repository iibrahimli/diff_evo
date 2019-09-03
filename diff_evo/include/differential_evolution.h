#pragma once

#include <random>


namespace de {

template <typename T>
class differential_evolution;


// functor, inherit and implement operator()
// function is expected to return a value convertible to double
template <typename T>
struct func {
    virtual T operator() ();
};


// operation mode
enum mode {
    MINIMIZE,
    MAXIMIZE
};


// default values
const int    DEFAULT_MAX_ITER       = 1000;
const int    DEFAULT_POP_MULT       = 8;
const double DEFAULT_MIN_DELTA      = 0.0001;
const float  DEFAULT_INIT_MUT_PROB  = 0.95;
const float  DEFAULT_MUT_PROB_DECAY = 0.99;


}    // namespace de


/*
    algo
*/
template <typename T>
class differential_evolution {
private:

    de::func     _target;           // the functor to minimize/maximize
    de::mode     _mode;             // minimize / maximize
    int          _nb_params;        // number of parameters of the function
    int          _max_iter;         // maximum iterations
    int          _pop_mult;         // population size is (this) * (# of params)                  (Q)
    int          _pop_size;         // population size
    T            _min_delta;        // if changes are lower than min delta, algorithm stops
    float        _init_mut_prob;    // initial mutation probability                               (P)
    float        _mut_prob_decay;   // mutation probability decay, at each step: mp *= mp_decay


public:

    /*
        default parameters
    */
    differential_evolution(de::func  target,
                           de::mode  op_mode,
                           int       nb_params,
                           double    param_min,
                           double    param_max);


    /*
        user-supplied parameters
    */
    differential_evolution(de::func  target,
                           de::mode  op_mode,
                           int       nb_params,
                           double    param_min,
                           double    param_max,
                           int       pop_mult,
                           double    min_delta,
                           float     pert_weight);


    /*
        returns number of iterations run
    */
    int run(int max_iters);


};