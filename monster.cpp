#include "monster.hpp"

Monster::Monster(QString name, int attack, int mAttack, int defense, int mDefense, int speed, int hp){
    m_attack = attack;
    m_name = name;
    m_defense = defense;
    m_mAttack = mAttack;
    m_mDefense = mDefense;
    m_speed = speed;
    m_hp = hp;

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
    return m_attack;
}

int Monster::mAttack() const{
    return m_mAttack;
}

int Monster::defense() const{
    return m_defense;
}

int Monster::mDefense() const{
    return m_mDefense;
}

int Monster::speed() const{
    return m_speed;
}

int Monster::hp() const{
    return m_hp;
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

