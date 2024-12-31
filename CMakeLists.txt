cmake_minimum_required(VERSION 3.19)
project(gtk)

set(CMAKE_C_COMPILER "D:/msys64/mingw64/bin/gcc")
set(CMAKE_CXX_COMPILER "D:/msys64/mingw64/bin/g++")

set(CMAKE_CXX_STANDARD 11)

#pacman -S mingw-w64-x86_64-gtk3
#pacman -S mingw-w64-x86_64-toolchain base-devel
#pacman -S mingw-w64-x86_64-glade
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
link_libraries(${GTK3_LINK_LIBRARIES})

add_executable(gtk main.c)
#target_link_options(gtk PRIVATE -mwindows)
