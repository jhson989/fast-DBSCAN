set (INSTALL_PATH /home/jhson/lib/)

set (
    CPP_FILES
    ${PKG_NAME}.cpp
)

set (
    CYTHON_FILE 
    ${PKG_NAME}.pyx
)

add_library(${PKG_NAME} SHARED ${CPP_FILES})


file(COPY ${PROJECT_SOURCE_DIR}/setup.py
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${CYTHON_FILE}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(
    cython ALL
    DEPENDS ${PKG_NAME}
    COMMAND python setup.py build_ext --inplace
    COMMAND python setup.py install --user
)

install(
    TARGETS ${PKG_NAME} 
    LIBRARY DESTINATION ${INSTALL_PATH}
    )