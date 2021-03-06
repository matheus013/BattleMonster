TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    skill.cpp \
    monster.cpp \
    gamedata.cpp \
    datacreate.cpp \
    trainer.cpp \
    battle.cpp

RESOURCES += qml.qrc \
    images.qrc

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
    trainer.h \
    battle.h

OTHER_FILES += ../build-BattleMonster/data/player/player.json \
               ../build-BattleMonster/data/json/monster.json

DISTFILES +=

