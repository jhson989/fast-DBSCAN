#include <memory.h>
#include <iostream>
#include "fastDBSCAN.hpp"

void fastDBSCAN(double* data, int* label, size_t num_data, double eps, double min_samples) {
    
    memset(label, 0, num_data*sizeof(int));

}