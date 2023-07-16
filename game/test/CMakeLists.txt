add_executable(space-invaders-game-test Rect.cpp)
target_link_libraries(space-invaders-game-test PRIVATE catch2_with_main
                                                       space-invaders-game)
add_test(NAME space-invaders-game-test COMMAND space-invaders-game-test)
