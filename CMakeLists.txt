cmake_minimum_required(VERSION 3.10)

#Set up project
project(
    pyoro 
    VERSION 1.0
)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Application.cpp
    src/SpriteSheet.cpp

    src/Util/Keyboard.cpp
    src/Util/Profiler.cpp
    src/Util/Util.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
  	target_compile_options(${PROJECT_NAME} PRIVATE 
    	/W4)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		
endif()

find_package(SFML COMPONENTS system audio network window graphics CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-audio sfml-network sfml-graphics sfml-window
)
