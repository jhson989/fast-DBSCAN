#include <iostream>
#include "fastDBSCAN.hpp"

void fastDBSCAN(double* data, size_t num_data, double eps, double min_samples) {
    
    for (int i=0; i<num_data*2; i++) {
        data[i] = data[i]*0.1;
    }

    return ;
}