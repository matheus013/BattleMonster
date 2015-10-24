#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "skill.hpp"
#include <QDebug>
#include <QVariant>

int main(int argc, char *argv[]){
   QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QGuiApplication::setApplicationName("Battle Monster");
    QGuiApplication::setApplicationVersion("1.0");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    Skill skill(&app);
//    skill.setProperty("name","Dragon Punch");
//    skill.setProperty("type",Dragon);
//    skill.setProperty("power",10000);
//    skill.setProperty("accuracy",100);
//    qDebug() << qPrintable(skill.toJson());
    return app.exec();

}

