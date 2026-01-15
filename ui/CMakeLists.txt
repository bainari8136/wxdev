
set(WX_DIR "C:/wxWidgets-3.3.1")
set(WX_INC "${WX_DIR}/include")
set(WX_LIB_DIR "${WX_DIR}/lib/gcc_dll")

include_directories(
${WX_INC} 
)

set(WX_LIBS
    "C:/wxWidgets-3.3.1/lib/gcc_dll/libwxbase33u.a"
    "C:/wxWidgets-3.3.1/lib/gcc_dll/libwxmsw33u_core.a"
)

add_library(ui_module STATIC
    Frame.h
    Frame.cpp
)

target_include_directories(
    ui_module PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(ui_module
    app_module
    ${WX_LIBS}
)