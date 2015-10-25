#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "skill.hpp"
#include <QDebug>
#include <QVariant>
#include "gamedata.h"
#include "datacreate.h"
#include "battle.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    DataCreate dataMake;
    GameData data;
    Battle battle;
    //Loading game data
    data.loadMonster();
    data.loadSkill();
    data.loadTrainer();
    battle.setPlayer(data.player());
    battle.nextEnemy(100);
    battle.nextFront();
    ctx->setContextProperty("_battle",&battle);
    ctx->setContextProperty("_make",&dataMake);
    ctx->setContextProperty("_data",&data);
    QGuiApplication::setApplicationName("Battle Monster");
    QGuiApplication::setApplicationVersion("1.0");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}

