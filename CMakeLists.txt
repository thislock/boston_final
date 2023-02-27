cmake_minimum_required(VERSION 3.0.0)
project(spies_purgitory VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(spies_purgitory 

src/gameplay/heart/heart.cpp
src/rendering/rendering.cpp
src/gameplay/scout/scout.cpp
src/gameplay/box/box.cpp
src/gameplay/box/box_text.cpp
src/gameplay/buttons/button.cpp
src/features/collide.cpp
src/rendering/font/font.cpp

main.cpp

)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(spies_purgitory ${SDL2_LIBRARIES})