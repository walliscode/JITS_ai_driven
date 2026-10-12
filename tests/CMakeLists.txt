add_executable(test_startup test_startup.cpp)
target_link_libraries(test_startup PRIVATE jits_core Qt6::Test)
add_test(NAME startup COMMAND test_startup)

add_executable(test_main_window test_main_window.cpp)
target_link_libraries(test_main_window PRIVATE jits_core Qt6::Test)
add_test(NAME main_window COMMAND test_main_window)

set_tests_properties(startup main_window PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
