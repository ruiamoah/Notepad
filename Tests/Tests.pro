QT += testlib         #Include QtTest to use SignalSpy, QTest::mouseClick, etc
QT += core gui printsupport
TARGET = Tests
TEMPLATE = app
QT += uitools

CONFIG += c++11
CONFIG += testcase    #Creates 'check' target in Makefile.
CONFIG -= debug_and_release
CONFIG += cmdline

include(../GoogleTest/GoogleTest.pri)

SOURCES += \
    finddialog.cpp \
    findform.cpp \
    findreplacedialog.cpp \
    findreplaceform.cpp \
    goto.cpp \
    main.cpp \
    notepad.cpp \


HEADERS += \
    finddialog.h \
    findform.h \
    findreplacedialog.h \
    findreplaceform.h \
    goto.h \
    notepad.h \
    tst_notepadtestcase.h \
    ui_notepad.h

FORMS += \
    findreplacedialog.ui \
    findreplaceform.ui \
    goto.ui \
    notepad.ui

## Default rules for deployment.
## qnx: target.path = /tmp/$${TARGET}/bin
## else: unix:!android: target.path = /opt/$${TARGET}/bin
## !isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \


