#include "monster.hpp"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

Monster::Monster(QString name, int attack, int mAttack, int defense, int mDefense, int speed, int hp){
    m_attack = attack;
    m_name = name;
    m_defense = defense;
    m_mAttack = mAttack;
    m_mDefense = mDefense;
    m_speed = speed;
    m_hp = hp;
    m_level = 1;
}

Monster::Monster(QJsonObject json){
    m_name = json.value("name").toString();
    m_attack = json.value("attack").toInt();
    m_mAttack = json.value("mAttack").toInt();
    m_defense = json.value("defense").toInt();
    m_mDefense = json.value("mDefense").toInt();
    m_speed = json.value("speed").toInt();
    m_hp = json.value("hp").toInt();
}

void Monster::levelUp(){
    m_level++;
}

QJsonObject Monster::toJson(){
    QJsonObject json;
    json.insert("name",m_name);
    json.insert("attack",m_attack);
    json.insert("mAttack",m_mAttack);
    json.insert("defense",m_defense);
    json.insert("mDefense",m_mDefense);
    json.insert("speed",m_speed);
    json.insert("hp",m_hp);
    //    if(json.value("type") == m_type)
    //        qDebug() << Q_FUNC_INFO << "enum: ok";
    return json;

}

QString Monster::name() const{
    return m_name;
}

void Monster::setName(QString name){
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

int Monster::attack() const{
    return m_attack*(m_level/100);
}

int Monster::mAttack() const{
    return m_mAttack*(m_level/100);
}

int Monster::defense() const{
    return m_defense*(m_level/100);
}

int Monster::mDefense() const{
    return m_mDefense*(m_level/100);
}

int Monster::speed() const{
    return m_speed*(m_level/100);
}

double Monster::hp() const{
    return m_hp*(m_level*(0.01));
}

void Monster::setAttack(int attack){
    if (m_attack == attack)
        return;

    m_attack = attack;
    emit attackChanged(attack);
}

void Monster::setMAttack(int mAttack){
    if (m_mAttack == mAttack)
        return;

    m_mAttack = mAttack;
    emit mAttackChanged(mAttack);
}

void Monster::setDefense(int defense){
    if (m_defense == defense)
        return;

    m_defense = defense;
    emit defenseChanged(defense);
}

void Monster::setMDefense(int mDefense){
    if (m_mDefense == mDefense)
        return;

    m_mDefense = mDefense;
    emit mDefenseChanged(mDefense);
}

void Monster::setSpeed(int speed){
    if (m_speed == speed)
        return;

    m_speed = speed;
    emit speedChanged(speed);
}

void Monster::setHp(int hp){
    if (m_hp == hp)
        return;

    m_hp = hp;
    emit hpChanged(hp);
}

int Monster::level() const
{
    return m_level;
}

void Monster::setLevel(int level)
{
    if (m_level == level)
        return;

    m_level = level;
    emit levelChanged(level);
}

QList<QObject *> Monster::skill() const
{
    return m_skill;
}

void Monster::setSkill(QList<QObject *> skill)
{
    if (m_skill == skill)
        return;

    m_skill = skill;
    emit skillChanged(skill);
}

