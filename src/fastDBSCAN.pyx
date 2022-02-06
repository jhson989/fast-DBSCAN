
#cython: language_level=3

cdef extern from "fastDBSCAN.hpp":
    double fastDBSCAN(double eps, double num_samples)

def fastDBSCAN(eps=0.3, min_samples=6):
    return fastDBSCAN(eps, min_samples)
