#include <iostream>
#include "fastDBSCAN.hpp"

void fastDBSCAN(double* data, int* label, size_t num_data, double eps, double min_samples) {
    
    for (size_t i=0; i<num_data; i++) {
        label[i] = std::rand()%10;
    }

}