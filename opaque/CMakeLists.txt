cmake_minimum_required(VERSION 3.10)

project(opaque_pattern
  VERSION
    1.0
  DESCRIPTION
    "Opaque pattern in C"
  LANGUAGES
    C
)

add_executable(opaque_pattern.out main.c circle.c)

