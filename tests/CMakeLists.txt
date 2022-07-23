add_executable(
    qccomplex_test
    qccomplex_test.cpp
)

target_include_directories(qccomplex_test PRIVATE ../src/)
target_compile_options(qccomplex_test PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(
    qccomplex_test
    gtest_main
    qccomplex
)

include(GoogleTest)
gtest_discover_tests(qccomplex_test)
