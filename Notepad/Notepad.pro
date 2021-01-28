QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = notepad.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    finddialog.cpp \
    findform.cpp \
    findreplacedialog.cpp \
    findreplaceform.cpp \
    goto.cpp \
    main.cpp \
    notepad.cpp

HEADERS += \
    finddialog.h \
    findform.h \
    findreplacedialog.h \
    findreplaceform.h \
    goto.h \
    notepad.h

FORMS += \
    findreplacedialog.ui \
    findreplaceform.ui \
    goto.ui \
    notepad.ui

# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \






