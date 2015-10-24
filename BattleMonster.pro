TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    skill.cpp \
    monster.cpp \
    gamedata.cpp \
    datacreate.cpp \
    trainer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    skill.hpp \
    monster.hpp \
    enum.h \
    gamedata.h \
    datacreate.h \
    trainer.h

