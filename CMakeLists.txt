cmake_minimum_required(VERSION 3.10.2)

# Project information
project ("FastDBSCAN"
    VERSION 1.0
    DESCRIPTION "Fast DBSCAN clustering algorithm accelerated with SYCL"
    )


include_directories (include)
add_subdirectory(src)