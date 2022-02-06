#pragma once

#include <iostream>
#include <vector>
#include <queue>

#define UNCHECKED (-1)
#define CHECKING (-2)
#define NOT_INCLUDED (0)

#define check_length(sx, sy, tx, ty, eps) ( (sx-tx)*(sx-tx) + (sy-ty)*(sy-ty) <= eps*eps )



// DBSCAN implementations
void DBSCAN_sequential(double* data, int* data_label, size_t num_data, double eps, double min_samples);

// Main interface
void fastDBSCAN(double*, int*, size_t, double, double);