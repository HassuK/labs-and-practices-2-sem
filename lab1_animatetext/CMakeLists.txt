cmake_minimum_required(VERSION 3.24)

project(lab1_text)

add_definitions(-DSFML_STATIC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("ext/SFML/include/")
include_directories("inc/")
include_directories("src/")
link_directories("ext/SFML/lib/")

add_executable(lab1_text main.cpp inc/animation.h src/animation.cpp)

target_link_libraries("lab1_text"
        debug sfml-graphics-s-d
        debug sfml-window-s-d
        debug sfml-system-s-d
        debug sfml-audio-s-d)

target_link_libraries("lab1_text"
        optimized sfml-graphics-s
        optimized sfml-window-s
        optimized sfml-system-s
        optimized sfml-audio-s)

target_link_libraries("lab1_text" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)


FILE(COPY "ext/font/HARLOWSI.ttf" DESTINATION "ext/font/")