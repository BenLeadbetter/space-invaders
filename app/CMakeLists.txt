find_package(ncurses REQUIRED)
add_executable(space-invaders main.cpp)
target_link_libraries(
    space-invaders PRIVATE space-invaders-game space-invaders-render
                           ncurses::ncurses)
set_target_properties(
    space-invaders
    PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER minesweeper.com
               MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
               MACOSX_BUNDLE_SHORT_VERSION_STRING
               ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
               MACOSX_BUNDLE TRUE)
