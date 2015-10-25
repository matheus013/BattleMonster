#include "gamedata.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
GameData::GameData(){}

void GameData::newSkill(QString name, int power, int accuracy, Type type){
    Skill *skill = new Skill();
    skill->setProperty("name",name);
    skill->setProperty("type",type);
    skill->setProperty("power",power);
    skill->setProperty("accuracy",accuracy);
    m_dataSkill.append(skill);
}

void GameData::newMonster(QString name, int attack, int mAttack, int defense, int mDefense, int speed, int hp){
    Monster *monster = new Monster(name,attack,mAttack,defense,mDefense,speed,hp);
    m_dataMonster.append(monster);
}

void GameData::newTrainer(QString name, QString sex, int monsterId){

}

void GameData::loadSkill(QString path){
    QFile in(path);
    QJsonDocument doc;
    if(in.open(QIODevice::ReadOnly)){
        doc = QJsonDocument::fromJson(in.readAll());
        QJsonArray json = doc.array();
        for (int var = 0; var < json.size(); ++var){
            //            if(QJsonDocument(json.at(var)).isObject()){
            //                Skill aux(QJsonDocument(json.at(var)).object());
            //                skillData.insert(QJsonDocument(json.at(var)).object().value("name"),aux);
            //            }
        }
    }
}

void GameData::loadMonster(QString path){

}

void GameData::saveMonster(QString path){
    QJsonArray json;
    for (int var = 0; var < m_dataMonster.size(); ++var) {
        json.append(m_dataMonster.at(var)->toJson());
    }
    QJsonDocument dataDoc(json);
    QFile out(path);
    if(out.open(QIODevice::WriteOnly)){
        out.write(dataDoc.toJson());
    }
}

void GameData::loadTrainer(QString dir){

}

void GameData::saveTrainer(QString dir){

}

QList<Skill *> GameData::dataSkill() const
{
    return m_dataSkill;
}

QList<Monster *> GameData::dataMonster() const
{
    return m_dataMonster;
}

Trainer *GameData::player() const
{
    return m_player;
}

void GameData::setDataSkill(QList<Skill *> dataSkill)
{
    if (m_dataSkill == dataSkill)
        return;

    m_dataSkill = dataSkill;
    emit dataSkillChanged(dataSkill);
}

void GameData::setDataMonster(QList<Monster *> dataMonster)
{
    if (m_dataMonster == dataMonster)
        return;

    m_dataMonster = dataMonster;
    emit dataMonsterChanged(dataMonster);
}

void GameData::setPlayer(Trainer *player)
{
    if (m_player == player)
        return;

    m_player = player;
    emit playerChanged(player);
}
