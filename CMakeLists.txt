cmake_minimum_required(VERSION 3.10.0)
project(app VERSION 0.1.0 LANGUAGES C CXX)

set(wxWidgets_ROOT_DIR "C:/Libraries/wxwidgets")
set(wxWidgets_LIB_DIR "C:/Libraries/wxwidgets/lib/gcc1510_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_SOURCES
    src/*.cpp
)

add_executable(app ${project_SOURCES})

target_link_libraries(app ${wxWidgets_LIBRARIES})
target_include_directories(app PRIVATE ${wxWidgets_INCLUDE_DIRS})