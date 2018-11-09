
add_executable(
    LEDManager.cpp
    Sensor.cpp
    WifiConnector.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    gmock_main
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
