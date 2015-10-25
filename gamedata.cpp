#include "gamedata.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
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
    m_player = new Trainer(name,sex,monsterId);
    saveTrainer();
}

void GameData::loadSkill(QString path){
    QFile in(path);
    QJsonDocument doc;
    if(in.open(QIODevice::ReadOnly)){
        doc = QJsonDocument::fromJson(in.readAll());
        QJsonArray json = doc.array();
        for (int var = 0; var < json.size(); ++var){
            Skill *aux = new Skill(json.at(var).toObject());
            m_dataSkill.append(aux);
        }
    }
}

void GameData::loadMonster(QString path){
    QFile read(path);
    QJsonDocument doc;
    if(read.open(QIODevice::ReadOnly)){
        doc = QJsonDocument::fromJson(read.readAll());
        QJsonArray json = doc.array();
        //        qDebug() << json;
        for (int var = 0; var < json.size(); ++var) {
            Monster* monster = new Monster(QJsonObject(json.at(var).toObject()));
            m_dataMonster.append(monster);
        }
    }
}

void GameData::saveMonster(QString path){
    QJsonArray json;
    for (int var = 0; var < m_dataMonster.size(); ++var) {
        json.append(m_dataMonster.at(var)->toJson());
    }
    QJsonDocument dataDoc(json);
    //    qDebug() << path;
    QFile out(path);
    if(out.open(QIODevice::WriteOnly | QIODevice::Text)){
        out.write(dataDoc.toJson());
    }else{
        qDebug() << Q_FUNC_INFO << "error";
    }
}

void GameData::loadTrainer(QString path){
    QFile read(path);
    QJsonDocument doc;
    if(read.open(QIODevice::ReadOnly)){
        doc = QJsonDocument::fromJson(read.readAll());
        QJsonObject json = doc.object();
        m_player = new Trainer(json);
    }
}

void GameData::saveTrainer(QString path){
    QFile out(path);
    QJsonObject json;
    QJsonArray list;
    json.insert("name",m_player->name());
    json.insert("sex",m_player->sex());
    for (int var = 0; var < m_player->team().size(); ++var) {
        QJsonObject aux;
        //        qDebug() << Q_FUNC_INFO << m_player->team().at(var)->property("name").toInt();
        aux.insert("id",m_player->team().at(var)->property("name").toInt());
        aux.insert("level",m_player->team().at(var)->level());
        list.append(aux);
    }
    json.insert("monsterList",list);
    QJsonDocument doc(json);
    if(out.open(QIODevice::WriteOnly)){
        out.write(doc.toJson());
    }
}

Monster *GameData::atMonster(int id) const{
    //    qDebug() << Q_FUNC_INFO << id;
    return dataMonster().at(id);
}

QList<Skill *> GameData::dataSkill() const{
    return m_dataSkill;
}

QList<Monster *> GameData::dataMonster() const{
    return m_dataMonster;
}

Trainer *GameData::player() const{
    return m_player;
}

void GameData::setDataSkill(QList<Skill *> dataSkill){
    if (m_dataSkill == dataSkill)
        return;
    m_dataSkill = dataSkill;
    emit dataSkillChanged(dataSkill);
}

void GameData::setDataMonster(QList<Monster *> dataMonster){
    if (m_dataMonster == dataMonster)
        return;
    m_dataMonster = dataMonster;
    emit dataMonsterChanged(dataMonster);
}

void GameData::setPlayer(Trainer *player){
    if (m_player == player)
        return;
    m_player = player;
    emit playerChanged(player);
}
