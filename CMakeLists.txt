cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_RELGPQUIRED ON)
add_compile_options(-Wall)
# add_compile_options(-O2)
add_compile_options(-Wl,--stack=256000000)

# add_executable(tmp Luogu/P5435.cpp)
add_executable(tmp Codeforces/2153F.cpp)
# add_executable(tmp tmp.cpp)
# add_executable(main main.cpp)