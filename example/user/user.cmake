include_directories(${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/tinyusb/src/portable/st/stm32_fsdev) #将stm32相关的驱动头文件添加到包含路径

add_library(tinyusb_config INTERFACE)  #添加tinyusb配置库

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/tinyusb/src) #将tinyusb作为子文件夹添加进项目

file(GLOB user_inc "${CMAKE_CURRENT_SOURCE_DIR}/user/source/inc" "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/inc")

file(GLOB user_src "${CMAKE_CURRENT_SOURCE_DIR}/user/source/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/user/source/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/*/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/user/libraries/tinyusb/src/portable/st/stm32_fsdev/dcd_stm32_fsdev.c") #将stm32相关的驱动头源码添加到项目

target_sources(${PROJECT_NAME}.elf PRIVATE ${user_src})

target_include_directories(${PROJECT_NAME}.elf PRIVATE ${user_inc})

add_tinyusb(${PROJECT_NAME}.elf) #调用tinyusb子文件夹中定义的函数将tinyusb添加到项目