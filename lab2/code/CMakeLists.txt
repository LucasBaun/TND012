cmake_minimum_required(VERSION 3.13.0...3.27.3)
project(TND012-Lab-2 VERSION 1.0.0 DESCRIPTION "TND012 Lab 2" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
target_compile_options(${target} PUBLIC 
$<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
$<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra>
)
endfunction()

add_executable(uppgift1 uppgift1.cpp)
add_executable(uppgift2 uppgift2.cpp)
add_executable(uppgift3 uppgift3.cpp)
add_executable(uppgift4 uppgift4.cpp)

enable_warnings(uppgift1)
enable_warnings(uppgift2)
enable_warnings(uppgift3)
enable_warnings(uppgift4)
