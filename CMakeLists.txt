cmake_minimum_required(VERSION 3.2)

project(Main C CXX)

add_subdirectory(base)
add_subdirectory(test)

add_executable(Main 
  main.c 
)
target_link_libraries(Main PRIVATE base test)

