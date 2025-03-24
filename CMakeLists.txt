cmake_minimum_required(VERSION 3.2)

project(Main C CXX)

file(GLOB SOURCES
  main.c 
  base/*.c  
  test/*.c 
)

add_executable(Main ${SOURCES})

include_directories(base/include test/include)

