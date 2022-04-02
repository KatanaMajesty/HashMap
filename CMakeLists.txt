cmake_minimum_required(VERSION 3.2)
project(HashMap CXX)

file(GLOB_RECURSE
    SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_compile_options("-DCMAKE_BUILD_TYPE=Debug")

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)