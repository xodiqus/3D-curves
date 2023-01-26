cmake_minimum_required(VERSION 3.5)

project(test-exercise-3D-curves LANGUAGES CXX)

file(GLOB HEADERS *.h)

add_executable(${PROJECT_NAME} ${HEADERS} main.cpp)

add_library(${PROJECT_NAME}-lib SHARED # 7)
    ${HEADERS}
    curve.cpp
    circle.cpp
    point.cpp
    ellipse.cpp
    helix.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)

target_compile_features(${PROJECT_NAME} 		PRIVATE cxx_std_20)
target_compile_features("${PROJECT_NAME}-lib" 		PRIVATE cxx_std_20)
