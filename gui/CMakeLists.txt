find_package(ftxui REQUIRED)

add_library(space-invaders-gui)
target_link_libraries(space-invaders-gui PUBLIC ftxui::ftxui)
