#include <iostream>
#include <iomanip>
#include "diff_evo.h"

using std::cout;
using std::endl;


double obj(de::dvec x){
    // Beale function
    return pow((1.5 - x[0] + x[0]*x[1]), 2) + pow((2.25 - x[0] + x[0]*x[1]*x[1]), 2) + pow((2.625 - x[0] + x[0]*x[1]*x[1]*x[1]), 2);
}


int main(){

    auto evo = de::diff_evo(
        2,
        {-4.5, -4.5},
        {4.5, 4.5},
        10000
    );

    auto sol = evo.optimize(
        obj,
        de::MINIMIZE,
        1e-14
    );

    cout << "optimal solution:" << endl;
    for(int i=0; i<sol.size(); ++i){
        cout << sol[i] << endl;
    }
    cout << "score: " << obj(sol) << endl;

    return 0;
}