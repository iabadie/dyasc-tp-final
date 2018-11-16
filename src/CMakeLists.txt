
add_library(baliza "")

target_sources(
    baliza

    PRIVATE
        Sensor.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/LEDManager.h
        ${CMAKE_CURRENT_LIST_DIR}/Sensor.h
        ${CMAKE_CURRENT_LIST_DIR}/WifiConnector.h
        ~/Arduino/hardware/espressif/ESP32/libraries/WiFi/src/WiFi.h
        ~/Arduino/hardware/espressif/ESP32/libraries/HTTPClient./src/HTTPClient..h
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
