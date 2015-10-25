#pragma once
#include <QObject>
#include <QVector>
#include "skill.hpp"


class Monster : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int attack READ attack WRITE setAttack NOTIFY attackChanged)
    Q_PROPERTY(int mAttack READ mAttack WRITE setMAttack NOTIFY mAttackChanged)
    Q_PROPERTY(int defense READ defense WRITE setDefense NOTIFY defenseChanged)
    Q_PROPERTY(int mDefense READ mDefense WRITE setMDefense NOTIFY mDefenseChanged)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int hp READ hp WRITE setHp NOTIFY hpChanged)

    QVector<Skill> skill;
    QString m_name;
    int m_attack;
    int m_mAttack;
    int m_defense;
    int m_mDefense;
    int m_speed;
    int m_hp;

public:
    Monster(QString name,int attack,int mAttack, int defense,int mDefense,int speed,int hp);

    QString name() const;
    void setName(QString name);
    int attack() const;
    int mAttack() const;
    int defense() const;
    int mDefense() const;
    int speed() const;
    int hp() const;
    void setAttack(int attack);
    void setMAttack(int mAttack);
    void setDefense(int defense);
    void setMDefense(int mDefense);
    void setSpeed(int speed);
    void setHp(int hp);

signals:
    void nameChanged(QString name);
    void attackChanged(int attack);
    void mAttackChanged(int mAttack);
    void defenseChanged(int defense);
    void mDefenseChanged(int mDefense);
    void speedChanged(int speed);
    void hpChanged(int hp);
};
