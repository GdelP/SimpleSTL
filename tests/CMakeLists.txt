project(Tests)

file(GLOB Tests_SOURCE ./*.cpp)
file(GLOB Tests_HEADERS ./*.hpp)

add_executable(Tests ${Tests_SOURCE} ${Tests_HEADERS})
