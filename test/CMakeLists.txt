add_executable(
    unit_tests
    BalizaTest.cpp
    MockLEDManager.cpp
    MockWifiConnector.cpp
    MockSensor.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    gmock_main
    baliza
    )

add_test(
    NAME
      unit
    COMMAND
      ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
    )
