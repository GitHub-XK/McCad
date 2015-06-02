cmake_minimum_required(VERSION 2.6)
cmake_policy(VERSION 2.6)

PROJECT (McCad)
SET (MCCAD_VERSION_MAJOR 0)
SET (MCCAD_VERSION_MINOR 4)
SET (MCCAD_VERSION_PATCH 1)

SET(MCCAD_VERSION ${MCCAD_VERSION_MAJOR}.${MCCAD_VERSION_MINOR}.${MCCAD_VERSION_PATCH})

#
#  McCad is a CAD interface program for the Monte Carlo Particle Transport Codes MCNP and TRIPOLI
#
# McCad uses the cmake for installation. Please download cmake from www.cmake.org and follow the installation
# instructions.
#
# Software requirements for McCad :
# -	OpenCASCADE >= 6.5 (www.opencascade.org)
# -	Qt >= 4.1 (qt.nokia.com)
#
# Installing McCad :
# cd /my/path/to/McCad
# mkdir build
# cd build
# cmake ../
# make
#
# Any problems? --> please contact dennis.grosse@kit.edu, ulrich.fischer@kit.edu
#

# general configuration file
# ----------------------------------------------------
configure_file (
        "${PROJECT_SOURCE_DIR}/inc/McCadConfig.h.in"
        "${PROJECT_SOURCE_DIR}/inc/McCadConfig.h"
)
# -----------------------------------------------------

set( BUILD_TO_DIR  ${McCad_SOURCE_DIR} )
include_directories( ${McCad_SOURCE_DIR}/inc )

#
# Check for Qt-4
#
 FIND_PACKAGE(Qt4 REQUIRED)

 IF(QT4_FOUND)
        MESSAGE ("-- Using Qt-Libraries in: ${QT_LIBRARY_DIR}")
 ELSE(QT4_FOUND)
        MESSAGE (FATAL_ERROR "Couldn't find QT4: please set shell var QTDIR to your QT4 dir")
 ENDIF(QT4_FOUND)

 ADD_DEFINITIONS(${QT_DEFINITIONS})

 # SET (QT_USE_QTASSISTANT true)
 SET (QT_USE_QTOPENGL true)
 SET (QT_USE_QTNETWORK true)
 SET (QT_USE_QTXML true)
 INCLUDE(${QT_USE_FILE})



#
# Check for OpenCASCADE Libraries
#
find_package(OCE)
if(OCE_FOUND)
    message(STATUS "Found OCE version ${OCE_VERSION}")
    # Include files reside in ${OCE_INCLUDE_DIRS};
    include_directories(${OCE_INCLUDE_DIRS})
else(OCE_FOUND)
    # OCE not found; either it is not found and user
    # has to set OCE_DIR to the directory containing
    # OCEConfig.cmake, or OCE is not installed and we
    # try to find OpenCascade files.
    if(DEFINED ENV{CASROOT})
        if(NOT DEFINED OCC_INCLUDE_PATH)
            set(OCC_INCLUDE_PATH "$ENV{CASROOT}/inc")
        endif()
        if(NOT DEFINED OCC_LIB_PATH)
            set(OCC_LIB_PATH "$ENV{CASROOT}/lin/lib")
        endif(NOT DEFINED OCC_LIB_PATH)
    else(DEFINED ENV{CASROOT})
        if(NOT DEFINED OCC_INCLUDE_PATH OR NOT DEFINED OCC_LIB_PATH)
            message(FATAL_ERROR "To specify paths of OpenCascade files, you may either define the CASROOT environment variable, or set both OCC_INCLUDE_PATH and OCC_LIB_PATH variables.")
        endif(NOT DEFINED OCC_INCLUDE_PATH OR NOT DEFINED OCC_LIB_PATH)
    endif(DEFINED ENV{CASROOT})
    if(DEFINED OCC_INCLUDE_PATH)
        message(STATUS "OCC search path for include files: OCC_INCLUDE_PATH=${OCC_INCLUDE_PATH}")
        include_directories(${OCC_INCLUDE_PATH})
    endif(DEFINED OCC_INCLUDE_PATH)
    if(DEFINED OCC_LIB_PATH)
        message(STATUS "OCC search path for libraries: OCC_LIB_PATH=${OCC_LIB_PATH}")
        link_directories(${OCC_LIB_PATH})
    endif(DEFINED OCC_LIB_PATH)
endif(OCE_FOUND)

#
# set build parameter
#
 include(CheckCXXCompilerFlag)
 SET(LIBRARY_OUTPUT_PATH   ${McCad_SOURCE_DIR}/lib )
 SET(EXECUTABLE_OUTPUT_PATH   ${McCad_SOURCE_DIR}/bin )

SET(CMAKE_CXX_FLAGS "-fPIC -funsigned-char -Wall -fmessage-length=0 -DNO_CXX_EXCEPTION -MD -DHAVE_LIMITS_H -DHAVE_IOSTREAM -DHAVE_CONFIG_H -fpermissive -pthread -fopenmp " )

if(DEFINED OCC650)
  add_definitions( -DOCC650 )
endif()

 if (CMAKE_SIZEOF_VOID_P MATCHES "8") # x86_64
    SET(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -m64 -D_OCC64" )
    set(BIT 64)
 else()
    set(BIT 32)
 endif()

if(DEBUG EQUAL true)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O1" )
else()
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3" )
endif()


 CHECK_CXX_COMPILER_FLAG("-ffriend-injection" compiler_accepts_-ffriend-injection_FLAG)
 IF(compiler_accepts_-ffriend-injection_FLAG)
        SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffriend-injection")
 ENDIF(compiler_accepts_-ffriend-injection_FLAG)


 OPTION (BUILD_SHARED_LIBS "build all libs as SHARED" ON ) #build all libraries as SHARED

#
# prepare McCad shell script to set up environment before
#
configure_file( ${PROJECT_SOURCE_DIR}/src/McCad.template
                ${PROJECT_SOURCE_DIR}/bin/McCad )


#
# settings for CPack debian package generator
#
set(CPACK_SET_DESTDIR true )
SET(CPACK_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX} )
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "McCad - a CAD interface for Monte Carlo particle transport codes")

SET(CPACK_PACKAGE_VERSION_MAJOR ${MCCAD_VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${MCCAD_VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${MCCAD_VERSION_PATCH})
SET(CPACK_PACKAGE_NAME ${PROJECT_NAME} )

SET(CPACK_PACKAGE_CONTACT "Ulrich Fischer <ulrich.fischer@kit.edu>")

SET(CPACK_GENERATOR "DEB")
if( CPACK_GENERATOR MATCHES ".*DEB.*" )

        if( ${CMAKE_VERSION} STREQUAL "2.8.2" )
                # bug http://vtk.org/Bug/view.php?id=11020
                message( WARNING "CMake/CPack version 2.8.2 will not create working .deb packages!")
        endif()
        set(CPACK_DEBIAN_PACKAGE_SECTION "science")
        # debian source packages aren't yet supported by cmake, but the following list will help anyone who is trying to figure out what to apt-get install before building.
        set(CPACK_DEBIAN_PACKAGE_BUILDS_DEPENDS "cmake (>= 2.8), libtool,
                libx11-dev, libxmu-dev, libxext-dev,
                libgl1-mesa-dev | libgl-dev, libglu1-mesa-dev | libglu-dev,
                libftgl-dev, libgl2ps-dev")
#	set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3), libfreetype6 (>= 2.2.1), libftgl2 (>= 2.1.3~rc5),
#		libgcc1 (>= 1:4.1.1), libgl1-mesa-glx, libglu1-mesa,
#		libgomp1 (>= 4.2.1), libstdc++6 (>= 4.4.0), libx11-6, libxext6,
#		libxmu6, libxt6, tcl8.5 (>= 8.5.0), tk8.5 (>= 8.5.0)")
        set(CPACK_DEBIAN_PACKAGE_PROVIDES "libmccad")
        if( BIT EQUAL 64 )
                set( CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64" )
        else()
                set( CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386" )
        endif()
        string( TOLOWER "${CPACK_PACKAGE_NAME}-${MCCAD_VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}" CPACK_PACKAGE_FILE_NAME )
endif()
# after 'cmake ..' and 'make' you can run cpack to generate a debian package when you
# uncomment the following line
include(CPack)


#
# enter build directory and run build script
#
 add_subdirectory(src)
# add_subdirectory(test)

