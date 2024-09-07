cmake_minimum_required(VERSION 3.10)

project(object_pattern
  VERSION
    1.0
  DESCRIPTION
    "Object in C"
  LANGUAGES
    C
)

add_executable(object_pattern main.c circle.c)

