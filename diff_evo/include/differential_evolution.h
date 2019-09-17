#pragma once

#include <random>


namespace de {

template <typename T>
class differential_evolution;


// functor, inherit and implement operator()
// function is expected to return a value convertible to double
template <typename T>
struct cost {
    virtual T operator() ();
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
template <typename T>
class differential_evolution {
private:

    de::cost<T>  _target;           // the function to minimize/maximize
    de::mode     _mode;             // minimize / maximize
    unsigned int _nb_params;        // number of parameters of the function
    unsigned int _max_iter;         // maximum iterations
    int          _pop_size;         // population size
    T            _min_delta;        // if changes are lower than min delta, algorithm stops
    float        _init_mut_prob;    // initial mutation probability                               (P)
    float        _mut_prob_decay;   // mutation probability decay, at each step: mp *= mp_decay


public:

    /*
        default parameters
    */
    differential_evolution(de::cost<T>  target,
                           de::mode     op_mode,
                           unsigned int nb_params,
                           double       param_min,
                           double       param_max);


    /*
        user-supplied parameters
    */
    differential_evolution(de::cost<T>  target,
                           de::mode     op_mode,
                           unsigned int nb_params,
                           double       param_min,
                           double       param_max,
                           double       min_delta,
                           float        pert_weight);


    /*
        returns number of iterations run
    */
    unsigned int run(int max_iters);


};