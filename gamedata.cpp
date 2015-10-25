#include "gamedata.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
GameData::GameData(){}

void GameData::newSkill(QString name, int power, int accuracy, Type type){
    Skill skill;
    skill.setProperty("name",name);
    skill.setProperty("type",type);
    skill.setProperty("power",power);
    skill.setProperty("accuracy",accuracy);
    //m_skillData.append(skill);
    //saveSkill();

}

void GameData::newMonster(QString name, int attack, int mAttack, int defense, int mDefense, int speed, int hp){
    Monster monster(name,attack,mAttack,defense,mDefense,speed,hp);
    //m_monsterData.append(monster);
    saveMonster();
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

}

void GameData::loadTrainer(QString dir){

}

void GameData::saveTrainer(QString dir){

}
