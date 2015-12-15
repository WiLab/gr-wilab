INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_WILAB wilab)

FIND_PATH(
    WILAB_INCLUDE_DIRS
    NAMES wilab/api.h
    HINTS $ENV{WILAB_DIR}/include
        ${PC_WILAB_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    WILAB_LIBRARIES
    NAMES gnuradio-wilab
    HINTS $ENV{WILAB_DIR}/lib
        ${PC_WILAB_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(WILAB DEFAULT_MSG WILAB_LIBRARIES WILAB_INCLUDE_DIRS)
MARK_AS_ADVANCED(WILAB_LIBRARIES WILAB_INCLUDE_DIRS)

