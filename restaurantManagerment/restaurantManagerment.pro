QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_adddish.cpp \
    dlg_addtable.cpp \
    dlg_line.cpp \
    dlg_queue.cpp \
    dlg_seat.cpp \
    main.cpp \
    mainwindow.cpp \
    menusql.cpp \
    page_login.cpp

HEADERS += \
    dlg_adddish.h \
    dlg_addtable.h \
    dlg_line.h \
    dlg_queue.h \
    dlg_seat.h \
    mainwindow.h \
    menusql.h \
    page_login.h

FORMS += \
    dlg_adddish.ui \
    dlg_addtable.ui \
    dlg_line.ui \
    dlg_queue.ui \
    dlg_seat.ui \
    mainwindow.ui \
    page_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
