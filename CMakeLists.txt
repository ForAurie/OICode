cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_RELGPQUIRED ON)
add_compile_options(-Wall)
add_compile_options(-O2)
add_compile_options(-Wl,--stack=2560000F00)


include_directories(${PROJECT_SOURCE_DIR}/SomeGoodTemplate)

# add_executable(tmp checker.cpp)

# add_executable(main YunDou/2025/11/18/T1.cpp)
# add_executable(chk YunDou/2025/11/18/T1chk.cpp)
# add_executable(gen YunDou/2025/11/18/T1gen.cpp)

add_executable(tmp YunDou/2025/11/18/T2.cpp)
# add_executable(tmp Splay.cpp)
# add_executable(tmp Luogu/P5537.cpp)
# add_executable(tmp Codeforces/Contest/2048/E.cpp)
# add_executable(tmp StarContest/2025/11/03/T4.cpp)
# add_executable(tmp HeTao/HT-085-Div.2/T1.cpp)
# add_executable(tmp atcoder/abc432/F.cpp)