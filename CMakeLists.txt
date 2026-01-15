cmake_minimum_required(VERSION 3.15)
project(WXDev LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WX_DIR "C:/wxWidgets-3.3.1")
set(WX_INC "${WX_DIR}/include")
set(WX_LIB_DIR "${WX_DIR}/lib/gcc_dll")

include_directories(
${WX_INC} 
)

add_subdirectory(services)
add_subdirectory(app)
add_subdirectory(ui)

add_definitions(
    -DUNICODE
    -D_UNICODE
    -D__WXMSW__
)

set(WIN_LIBS
    comctl32
    rpcrt4
    winmm
    shlwapi
)



add_executable(${PROJECT_NAME} main.cpp )
#add_definitions(-DwxUSE_NEW_COMMONCONTROLS=1 -D_WIN32_IE=0x0600 -DWINVER=0x0600)

target_link_libraries(${PROJECT_NAME}
    ui_module
)
if(WIN32)
   add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/mt.exe"
    -manifest ${CMAKE_SOURCE_DIR}/build/app.manifest
    -outputresource:$<TARGET_FILE:${PROJECT_NAME}>;
   )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)