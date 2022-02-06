
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#include "fastDBSCAN.hpp"

void fastDBSCAN(double* data, int* data_label, size_t num_data, double eps, double min_samples) {
    
    for (size_t idx=0; idx<num_data; idx++) data_label[idx] = UNCHECKED;


    DBSCAN_sequential(data, data_label, num_data, eps, min_samples);

}