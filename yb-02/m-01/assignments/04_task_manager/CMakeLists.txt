PROJECT(task_manager)


add_executable(${PROJECT_NAME} 04_task_manager.cc TaskManager.h)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
        tests_task_manager
        tests_task_manager.cpp
        TaskManager.h
)
target_link_libraries(tests_task_manager gtest_main)