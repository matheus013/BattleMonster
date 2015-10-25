#include "trainer.h"
#include <QJsonObject>
#include <QJsonArray>
#include "gamedata.h"
#include <QDebug>

Trainer::Trainer(QJsonObject json){
    GameData data;
    data.loadMonster();
    m_name =  json.value("name").toString();
    m_sex = json.value("sex").toString();
    QJsonArray aux = json.value("monsterList").toArray();
    for (int var = 0; var < aux.size(); ++var) {
        Monster * monster = data.atMonster(aux.at(var).toObject().value("id").toInt());
        monster->setLevel(aux.at(var).toObject().value("level").toInt());
        m_team.append(monster);
    }
}

Trainer::Trainer(QString name, QString sex, int initial){
    m_name = name;
    m_sex = sex;
    GameData data;
    data.loadMonster();
    m_team.append(data.atMonster(initial));

    qDebug() << Q_FUNC_INFO << data.atMonster(initial)->property("name").toInt();
}

QString Trainer::sex() const{
    return m_sex;
}

QString Trainer::name() const{
    return m_name;
}

QList<Monster*> Trainer::team() const{
    return m_team;
}

QList<Monster *> Trainer::box() const{
    return m_box;
}

void Trainer::setSex(QString sex){
    if (m_sex == sex)
        return;
    m_sex = sex;
    emit sexChanged(sex);
}

void Trainer::setName(QString name){
    if (m_name == name)
        return;
    m_name = name;
    emit nameChanged(name);
}

void Trainer::setTeam(QList<Monster *> team){
    if (m_team == team)
        return;
    m_team = team;
    emit teamChanged(team);
}

void Trainer::setBox(QList<Monster *> box){
    if (m_box == box)
        return;
    m_box = box;
    emit boxChanged(box);
}

