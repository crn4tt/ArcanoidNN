cmake_minimum_required(VERSION 3.17.0)
project(ArcanoidNN)

set(wxWidgets_ROOT_DIR "C:/wxwidgets")
set(wxWidgets_LIB_DIR "C:/wxwidgets/lib/vc14x_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_GLOB
    src/*
)
add_executable(ArcanoidNN ${project_GLOB})

target_link_libraries(ArcanoidNN ${wxWidgets_LIBRARIES})
target_include_directories(ArcanoidNN PRIVATE ${wxWidgets_INCLUDE_DIRS})