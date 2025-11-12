cmake_minimum_required(VERSION 3.16)

project(ftf VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    libs/qcustomplot.cpp
)

# Указываем путь к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/libs)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ftf
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(ftf
        ${PROJECT_SOURCES}
        simpson.cpp
        simpson.h
        dtf.h
        dtf.cpp
        fft.h
        fft.cpp
    )
endif()

target_link_libraries(ftf PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

include(GNUInstallDirs)
install(TARGETS ftf
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ftf)
endif()
