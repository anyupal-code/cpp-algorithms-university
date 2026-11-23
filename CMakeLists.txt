cmake_minimum_required(VERSION 3.10)
project(cpp_algorithms_university)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем подпапки с уроками
add_subdirectory(lesson-01-big-o)
add_subdirectory(lesson-02-vector)
add_subdirectory(lesson-03-linked-list)
add_subdirectory(lesson-04-stack-queue)
add_subdirectory(lesson-05-hash-table)
add_subdirectory(lesson-06-bst)
add_subdirectory(lesson-07-heap)
add_subdirectory(lesson-08-avl)
add_subdirectory(lesson-09-sorting)
add_subdirectory(lesson-10-graphs)
add_subdirectory(lesson-11-dijkstra)
add_subdirectory(lesson-12-dp)