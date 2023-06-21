project(NamesHistory)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp)

enable_testing()

add_executable(
        names_test
        test.cpp
)
target_link_libraries(
        names_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(names_test)
