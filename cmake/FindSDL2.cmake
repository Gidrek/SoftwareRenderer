find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(PC_SDL2 QUIET sdl2)
endif()

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h
        HINTS
        ${PC_SDL2_INCLUDEDIR}
        ${PC_SDL2_INCLUDE_DIRS}
        $ENV{SDL2_DIR}/include
        PATHS
        /usr/include
        /usr/local/include
        /opt/local/include
        /opt/homebrew/include
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_ARCH_HINT lib/x64)
else()
    set(SDL2_ARCH_HINT lib/x86)
endif()

find_library(SDL2_LIBRARY
        NAMES SDL2
        HINTS
        ${PC_SDL2_LIBDIR}
        ${PC_SDL2_LIBRARY_DIRS}
        $ENV{SDL2_DIR}/${SDL2_ARCH_HINT}
        $ENV{SDL2_DIR}/lib
        PATHS
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        /opt/homebrew/lib
)

if(NOT TARGET SDL2::SDL2)
    add_library(SDL2::SDL2 UNKNOWN IMPORTED)
endif()

if(SDL2_INCLUDE_DIR AND SDL2_LIBRARY)
    set_target_properties(SDL2::SDL2 PROPERTIES
            IMPORTED_LOCATION "${SDL2_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIR}"
    )
endif()

if(WIN32)
    find_library(SDL2MAIN_LIBRARY
            NAMES SDL2main
            HINTS
            $ENV{SDL2_DIR}/${SDL2_ARCH_HINT}
            $ENV{SDL2_DIR}/lib
    )
    if(SDL2MAIN_LIBRARY)
        set_property(TARGET SDL2::SDL2 APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${SDL2MAIN_LIBRARY})
    endif()

    find_file(SDL2_DLL_PATH SDL2.dll
            HINTS
            $ENV{SDL2_DIR}/bin
            $ENV{SDL2_DIR}/${SDL2_ARCH_HINT}
    )
    if(SDL2_DLL_PATH)
        set(SDL2_DLL_PATH ${SDL2_DLL_PATH} CACHE FILEPATH "Path to SDL2.dll")
    endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2
        REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR
)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY SDL2MAIN_LIBRARY)