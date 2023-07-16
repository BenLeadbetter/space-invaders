find_package(Eigen3 REQUIRED)
add_library(
    space-invaders-game
    src/Game.cpp
    inc/Game.h
    inc/Input.h
    inc/Metrics.h
    inc/Object.h
    inc/Rect.h
    src/Rect.cpp)
target_link_libraries(space-invaders-game PUBLIC Eigen3::Eigen)
target_include_directories(space-invaders-game PUBLIC inc)
target_include_directories(space-invaders-game PRIVATE src)

if(SPACE_INVADERS_TESTS)
    add_subdirectory(test)
endif()
