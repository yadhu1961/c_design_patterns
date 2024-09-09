cmake_minimum_required(VERSION 3.10)

project(singleton_pattern
  VERSION
    1.0
  DESCRIPTION
    "Singleton pattern in C"
  LANGUAGES
    C
)

add_executable(singleton_pattern.out main.c logger.c)

target_link_libraries(singleton_pattern.out pthread)

