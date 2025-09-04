
find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appchess_client
    main.cpp
    appstartup.h
    appstartup.cpp
)

qt_add_qml_module(appchess_client
    URI chess_client
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        QML_FILES qml/Login.qml
        QML_FILES qml/MainPage.qml
        QML_FILES qml/MainPageTopNav.qml
        QML_FILES qml/Register.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appchess_client PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appchess_client
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appchess_client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_subdirectory(LoginServer)
add_subdirectory(DbServer)
add_subdirectory(WebsocketClient)
add_subdirectory(Utils)
add_subdirectory(HttpClient)

target_link_libraries(appchess_client
    PRIVATE Qt6::Quick
    LoginServer
    DbServer
    WebsocketClient
    Utils
    HttpClient
    Qt6::QuickControls2
)




