find_package(Catch2 REQUIRED)
add_library(catch2_with_main catch2_main.cpp)
target_link_libraries(catch2_with_main PUBLIC Catch2::Catch2)
