project( coretime )
cmake_minimum_required( VERSION 3.16 )

set( PROJECT_VERSION 4.4.0 )
set( PROJECT_VERSION_MAJOR 4 )
set( PROJECT_VERSION_MINOR 4 )
set( PROJECT_VERSION_PATCH 0 )

set( PROJECT_VERSION_MAJOR_MINOR ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} )
add_compile_definitions(VERSION_TEXT="${PROJECT_VERSION}")

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_BUILD_TYPE Release )

add_definitions ( -Wall )
if ( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
    set( CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "Location for installing the project" FORCE )
endif()


add_compile_definitions(AUDIO_RESOURCE_FOLDER="${CMAKE_INSTALL_PREFIX}/share/coreapps/resource/")

find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Multimedia REQUIRED )
find_package( Qt5Network REQUIRED )

include_directories( src/ )

set( coretime_HDRS
		src/commonfunc.h
		src/settings.h
		src/weatherdata.h
		src/weathericon.h
)

set( coretime_SRCS
		src/alarmitemwidget.cpp
		src/alarmwidget.cpp
		src/apirequest.cpp
		src/astroinfo.cpp
		src/calendarmanage.cpp
		src/commonfunc.cpp
		src/coretime.cpp
		src/currentschedule.cpp
		src/locationinfo.cpp
		src/main.cpp
		src/reminderitemwidget.cpp
		src/reminderwidget.cpp
		src/schedulequeue.cpp
		src/settings.cpp
		src/stopwatch.cpp
		src/weatherdata.cpp
		src/weathericon.cpp
		src/weatherinfo.cpp
		src/weatherview.cpp
)

set( coretime_MOCS
		src/alarmitemwidget.h
		src/alarmwidget.h
		src/apirequest.h
		src/astroinfo.h
		src/calendarmanage.h
		src/coretime.h
		src/currentschedule.h
		src/locationinfo.h
		src/reminderitemwidget.h
		src/reminderwidget.h
		src/schedulequeue.h
		src/stopwatch.h
		src/weatherinfo.h
		src/weatherview.h
)
QT5_WRAP_CPP( MOCS ${coretime_MOCS} )

set( coretime_UIS
		src/alarmitemwidget.ui
		src/alarmwidget.ui
		src/coretime.ui
		src/currentschedule.ui
		src/reminderitemwidget.ui
		src/reminderwidget.ui
		src/weatherview.ui
)
QT5_WRAP_UI( UIS ${coretime_UIS} )

add_executable( coretime ${coretime_SRCS} ${UIS} ${RSCS} ${MOCS} )
target_link_libraries ( coretime  Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Multimedia cprime-widgets cprime-core )

install( TARGETS coretime DESTINATION bin )
install( FILES org.cubocore.CoreTime.desktop DESTINATION share/applications )
install( FILES org.cubocore.CoreTime.svg DESTINATION share/icons/hicolor/scalable/apps/ )
install( FILES resource/sound.ogg DESTINATION share/coreapps/resource/ )
