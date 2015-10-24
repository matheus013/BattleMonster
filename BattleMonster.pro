TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    treiner.cpp \
    skill.cpp \
    monster.cpp \
    gamedata.cpp \
    datacreate.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    treiner.hpp \
    skill.hpp \
    monster.hpp \
    enum.h \
    gamedata.h \
    datacreate.h

DISTFILES +=

