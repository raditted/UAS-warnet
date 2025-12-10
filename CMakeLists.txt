cmake_minimum_required(VERSION 4.0)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled
        main.c
        jam.c
        date.c
)

add_executable(date_test
        main_date.c
        date.c
)
