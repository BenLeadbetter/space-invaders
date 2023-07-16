find_package(Eigen3 REQUIRED)
add_library(space-invaders-game src/Game.cpp inc/Game.h inc/Input.h
                                inc/Object.h inc/Rect.h)
target_link_libraries(space-invaders-game PRIVATE Eigen3::Eigen)
target_include_directories(space-invaders-game PUBLIC inc)
target_include_directories(space-invaders-game PRIVATE src)
