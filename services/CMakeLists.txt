add_library(
    service_module STATIC 
    OpenSSLService.cpp
    OpenSSLService.h
)

target_include_directories(
    service_module PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}
)
set(OPENSSL_LIB "C:/msys64/mingw64/lib/libcrypto.dll.a")
target_link_libraries(
    service_module PUBLIC 
    ${OPENSSL_LIB}
)