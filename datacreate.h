#ifndef DATACREATE_H
#define DATACREATE_H
#include <QObject>
#include "gamedata.h"
class DataCreate : public QObject {
    Q_OBJECT
    GameData data;
public:
    DataCreate();
    Q_INVOKABLE void buildMonster();
    int random(int a = 300,int b = 400);

signals:

};

#endif // DATACREATE_H
