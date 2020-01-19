#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <functional>
#include <limits>


namespace de {

    class diff_evo;

    using dvec = std::vector<double>;

    enum opt_mode {
        MINIMIZE,
        MAXIMIZE
    };

    const double DEFAULT_CR         = 0.8;
    const double DEFAULT_F          = 0.9;
    const double DEFAULT_DITHER_MIN = 0.5;
    const double DEFAULT_DITHER_MAX = 1.0;
    const double DEFAULT_DELTA      = 1e-4;
    const size_t DEFAULT_MAX_ITER   = 100000;

}


class de::diff_evo {

private:

    size_t             num_params;
    dvec               param_min;
    dvec               param_max;
    std::vector<dvec>  population;    // [agent][parameter]
    size_t             pop_size;
    double             crossover_prob;
    double             diff_weight;
    bool               dither;
    double             dither_min;
    double             dither_max;


public:

    diff_evo(size_t   num_params,
             dvec     param_min,
             dvec     param_max,
             size_t   np         = 0,
             double   cr         = de::DEFAULT_CR,
             double   f          = de::DEFAULT_F,
             bool     dither     = true,
             double   dither_min = de::DEFAULT_DITHER_MIN,
             double   dither_max = de::DEFAULT_DITHER_MAX);


    dvec optimize(std::function<double(dvec)>  obj,
                  de::opt_mode                 mode     = de::MINIMIZE,
                  double                       delta    = de::DEFAULT_DELTA,
                  size_t                       max_iter = de::DEFAULT_MAX_ITER);

};