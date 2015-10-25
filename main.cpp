#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "skill.hpp"
#include <QDebug>
#include <QVariant>
#include "gamedata.h"
#include "datacreate.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    DataCreate dataMake;
    GameData data;
    data.loadMonster();
    data.loadSkill();
    data.loadTrainer();
    ctx->setContextProperty("_make",&dataMake);
    ctx->setContextProperty("_data",&data);
    QGuiApplication::setApplicationName("Battle Monster");
    QGuiApplication::setApplicationVersion("1.0");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}

