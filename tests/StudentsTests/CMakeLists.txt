include_directories(test/lib/googletest-release-1.8.1/googletest/include)
include_directories(test/lib/googletest-release-1.8.1/googlemock/include)

add_executable(Stud_Test
        stud_test.cpp)

target_link_libraries(Stud_Test gtest gtest_main)
target_link_libraries(Stud_Test src)