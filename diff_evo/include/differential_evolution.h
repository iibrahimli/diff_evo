#pragma once


namespace de {

class differential_evolution;

// distributions to sample initial population from
enum distribution {
    RANDOM_GAUSSIAN,
    RANDOM_UNIFORM
};


// default values
const int DEFAULT_MAX_ITER        = 1000;
const int DEFAULT_POPULATION_SIZE = 1000;


}    // namespace de


class differential_evolution {
private:

    int _max_iter;          // maximum iterations
    int _pop_size;          // population size
    

public:

    /*
        default parameters
    */
    differential_evolution();


};