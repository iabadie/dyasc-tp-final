
add_library(baliza "")

target_sources(
    baliza

    PRIVATE
        Brain.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/LEDManagerInterface.h
        ${CMAKE_CURRENT_LIST_DIR}/SensorInterface.h
        ${CMAKE_CURRENT_LIST_DIR}/WifiConnectorInterface.h
        ${CMAKE_CURRENT_LIST_DIR}/Brain.h
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
