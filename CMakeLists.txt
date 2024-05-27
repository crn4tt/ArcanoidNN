cmake_minimum_required(VERSION 3.22)
project(Arkanoid LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(FONTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fonts")
set(TEXTURES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/textures")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

configure_file("${FONTS_DIR}/PionerSans-Bold.ttf" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/PionerSans-Bold.ttf" COPYONLY)

file(GLOB TEXTURES "${TEXTURES_DIR}/*.png")
foreach(TEXTURE ${TEXTURES})
    get_filename_component(TEXTURE_NAME "${TEXTURE}" NAME)
    configure_file("${TEXTURE}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/${TEXTURE_NAME}" COPYONLY)
endforeach()

if(WIN32)
    add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${CMAKE_PROJECT_NAME})
