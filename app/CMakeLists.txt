set(SSL_SERVICE_DIR "C:/Users/Victor GM/wxdev/services")

include_directories(${SSL_SERVICE_DIR})

add_library(app_module STATIC 
SSLVersion.cpp
SSLVersion.h
)

target_include_directories(
    app_module PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SSL_SERVICE_DIR}
)

target_link_libraries(
    app_module PUBLIC 
    service_module
)