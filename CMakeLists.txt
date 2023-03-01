cmake_minimum_required(VERSION 3.0.0)
project(spies_purgitory VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(spies_purgitory 

# player
src/gameplay/heart/heart.cpp
# my rendering lib
src/rendering/rendering.cpp
# scout/fought
src/gameplay/scout/scout.cpp
# box prossessing
src/gameplay/box/box.cpp
src/gameplay/box/box_text.cpp
# buttons
src/gameplay/buttons/button.cpp
# colide maths
src/features/collide.cpp
# font rendering
src/rendering/font/font.cpp
# attacks
src/gameplay/attacks/attack.cpp
src/gameplay/attacks/attacks.cpp

main.cpp

)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(spies_purgitory ${SDL2_LIBRARIES})