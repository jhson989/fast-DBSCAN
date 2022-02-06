set (
    CPP_FILES
    fastDBSCAN.cpp
)

set (
    CYTHON_FILE 
    fastDBSCAN.pyx
)

add_library(FastDBSCAN SHARED ${CPP_FILES})


file(COPY ${PROJECT_SOURCE_DIR}/setup.py
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${CYTHON_FILE}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(
    cython ALL
    DEPENDS FastDBSCAN
    COMMAND python setup.py build_ext --inplace
)
