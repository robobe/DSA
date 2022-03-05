cmake_minimum_required(VERSION 3.0.0)
project(DSA VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(CTest)
enable_testing()

add_executable(DSA main.cpp)

include(GoogleTest)

file(GLOB_RECURSE test_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

file(GLOB_RECURSE src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set (SOURCES
    ${test_sources}
    ${src}
)
add_executable(tests ${SOURCES})
target_link_libraries(tests gtest gtest_main pthread)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
gtest_discover_tests(tests)


# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
