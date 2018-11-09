
add_library(baliza "")

target_sources(
    baliza

    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/LEDManager.h
        ${CMAKE_CURRENT_LIST_DIR}/Sensor.h
        ${CMAKE_CURRENT_LIST_DIR}/WifiConnector.h
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
