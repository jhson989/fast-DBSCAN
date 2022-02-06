
#cython: language_level=3

from libc.stdlib cimport malloc, free

cdef extern from "fastDBSCAN.hpp":
    void fastDBSCAN(double* data, int* label, int num_points, double eps, double min_samples)

cdef points_to_array(double * data, points, num_points):
    cdef int i
    for i in range(num_points):
        data[2*i] = points[i][0] #y
        data[2*i+1] = points[i][1] #x


def run(points, eps=0.3, min_samples=6):

    cdef size_t num_points = len(points)
    cdef double *data = <double*> malloc(2 * num_points * sizeof(double))
    cdef int *label = <int*> malloc(num_points * sizeof(int))

    try:
        points_to_array(data, points, num_points)
        fastDBSCAN(data, label, num_points, eps, min_samples)
        points_label = [l for l in label[:num_points]]
    finally:
        free(data)
        free(label)

    return points_label
    

