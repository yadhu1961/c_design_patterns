cmake_minimum_required(VERSION 3.10)

project(c_design_patterns
  VERSION
    1.0
  DESCRIPTION
    "Design patterns in C"
  LANGUAGES
    C
)

add_subdirectory(object)
add_subdirectory(opaque)
add_subdirectory(singleton)
# add_subdirectory(strategy_pattern)

