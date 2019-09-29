#include <iostream>
#include <iomanip>
#include "differential_evolution.h"

using std::cout;
using std::endl;


class func : de::cost<float, float> {

    float calc(size_t size, float vec[]) override {
        // sum of vector components
        float sum = 0;
        for(int i=0; i<size; ++i)
            sum += vec[i];
        return sum;
    }

};


int main(){

    cout << "default initial mutation probability: " << de::DEFAULT_INIT_MUT_PROB << endl;

    auto evo = de::differential_evolution<float, float>(func(), de::MINIMIZE, 3);

    return 0;
}