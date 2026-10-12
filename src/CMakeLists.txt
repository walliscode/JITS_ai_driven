add_library(jits_core STATIC
  startup.cpp
  main_window.cpp)

target_include_directories(jits_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(jits_core PUBLIC
  Qt6::Widgets
  directory_paths)

add_executable(jits_scheduler
  main.cpp)

target_link_libraries(jits_scheduler PRIVATE
  jits_core)
