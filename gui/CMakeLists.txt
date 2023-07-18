find_package(ftxui REQUIRED)
add_library(space-invaders-gui src/gui/Render.cpp)
target_link_libraries(space-invaders-gui PUBLIC space-invaders-game
                                                ftxui::ftxui)
target_include_directories(space-invaders-gui PUBLIC inc)
target_include_directories(space-invaders-gui PRIVATE src)
