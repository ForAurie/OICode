cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_RELGPQUIRED ON)
add_compile_options(-Wall)
# add_compile_options(-O2)
add_compile_options(-Wl,--stack=256000000)

add_executable(tmp Luogu/P4719.cpp)
# add_executable(tmp Codeforces/Contest/2149/G.cpp)
# add_executable(tmp StarContest/2025/10/21/card.cpp)
# add_executable(tmp HeTao/HT-083-Div.2/P10800.cpp)
