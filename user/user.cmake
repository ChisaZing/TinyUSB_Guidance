file(GLOB user_inc "${CMAKE_CURRENT_SOURCE_DIR}/user/source/inc" "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/inc")

file(GLOB user_src "${CMAKE_CURRENT_SOURCE_DIR}/user/source/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/user/source/*.cpp"
                    "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/*.cpp")

target_sources(${PROJECT_NAME}.elf PRIVATE ${user_src})

target_include_directories(${PROJECT_NAME}.elf PRIVATE ${user_inc})