# - Find SDL2
# This module defines:
#   SDL2_INCLUDE_DIRS - where to find SDL.h
#   SDL2_LIBRARIES    - the libraries to link against
#   SDL2_FOUND        - if SDL2 is found

find_path(SDL2_INCLUDE_DIR SDL.h
        PATH_SUFFIXES SDL2
        PATHS
        ${SDL2_DIR}
        $ENV{SDL2_DIR}
        /usr/include
        /usr/local/include
        /opt/local/include
        /opt/homebrew/include
)

find_library(SDL2_LIBRARY
        NAMES SDL2 SDL2-2.0
        PATHS
        ${SDL2_DIR}
        $ENV{SDL2_DIR}
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        /opt/homebrew/lib
)

set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
set(SDL2_LIBRARIES ${SDL2_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 REQUIRED_VARS SDL2_INCLUDE_DIR SDL2_LIBRARY)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY)
