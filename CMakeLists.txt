cmake_minimum_required(VERSION 3.31)

set(NAME app-template)
set(NAMESPACE kaycxx)

project(${NAME}
    VERSION 1.0.0
    DESCRIPTION "C++ app template"
    HOMEPAGE_URL "https://github.com/${NAMESPACE}/${NAME}"
    LANGUAGES CXX
)

include(GNUInstallDirs)
include(cmake/CompilerWarnings.cmake)
include(cmake/GitDeps.cmake)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

git_require(kaycxx::library-template v1.1.0)

file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)
list(REMOVE_ITEM MAIN_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
list(SORT MAIN_SOURCES)

add_library(${NAME}-main STATIC
    ${MAIN_SOURCES}
)
target_include_directories(${NAME}-main PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(${NAME}-main PRIVATE
    ${NAMESPACE}::library-template
)

add_executable(${NAME}
    src/main.cpp
)
target_link_libraries(${NAME} PRIVATE
    ${NAME}-main
)

include(cmake/Sandbox.cmake)
include(cmake/GTest.cmake)

install(TARGETS ${NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)
