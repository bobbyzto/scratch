add_library(test 
  src/test.c
)
target_include_directories(test PUBLIC include)
target_link_libraries(test PRIVATE base)
