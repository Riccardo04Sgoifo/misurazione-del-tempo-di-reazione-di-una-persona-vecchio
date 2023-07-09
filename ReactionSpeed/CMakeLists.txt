cmake_minimum_required(VERSION 3.16)

project(ReactionSpeed VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

add_subdirectory(Basic)



set (SOURCES
    main.cpp
    mainlogic.cpp
    mainlogicworker.cpp
)

set (HEADERS
    mainlogic.h
    mainlogicworker.h
)

qt_add_executable(appReactionSpeed
    ${SOURCES}
    ${HEADERS}
)

qt_add_qml_module(appReactionSpeed
    URI ReactionSpeed
    VERSION 1.0
    QML_FILES
        Main.qml
        LightCanvas.qml
)

target_include_directories(appReactionSpeed PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(appReactionSpeed PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appReactionSpeed
    PRIVATE Qt6::Quick BasicLibplugin
)

set (_QML_IMPORT_PATH "")

list (
    APPEND _QML_IMPORT_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set (QML_IMPORT_PATH ${_QML_IMPORT_PATH}
    CACHE STRING "Qt Creator extra qml import paths"
    FORCE
)

list(REMOVE_DUPLICATES QML_IMPORT_PATH)

install(TARGETS appReactionSpeed
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
