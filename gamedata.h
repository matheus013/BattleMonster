#pragma once
#include <QVariant>
#include <QObject>
#include <QList>
#include "monster.hpp"
#include "trainer.h"
#include "skill.hpp"


class GameData : public QObject{
    Q_OBJECT
    Q_PROPERTY(QList<Skill *> dataSkill READ dataSkill WRITE setDataSkill NOTIFY dataSkillChanged)
    Q_PROPERTY(QList<Monster *> dataMonster READ dataMonster WRITE setDataMonster NOTIFY dataMonsterChanged)
    Q_PROPERTY(Trainer * player READ player WRITE setPlayer NOTIFY playerChanged)

    QList<Monster *> m_dataMonster;

    QList<Skill *> m_dataSkill;

    Trainer * m_player;

public:
    GameData();

    void newSkill(QString name, int power, int accuracy, Type type);
    void newMonster(QString name,int attack,int mAttack, int defense,int mDefense,int speed,int hp);

    void loadSkill(QString path = "data/json/skill.json");
    void saveSkill(QString path = "data/json/skill.json");

    void loadMonster(QString path = "data/json/monster.json");
    void saveMonster(QString path = "data/json/monster.json");

    void loadTrainer(QString dir = "data/player");
    void saveTrainer(QString dir = "data/player");

    QList<Skill *> dataSkill() const
    {
        return m_dataSkill;
    }
    QList<Monster *> dataMonster() const
    {
        return m_dataMonster;
    }

    Trainer * player() const
    {
        return m_player;
    }

public slots:
    void setDataSkill(QList<Skill *> dataSkill)
    {
        if (m_dataSkill == dataSkill)
            return;

        m_dataSkill = dataSkill;
        emit dataSkillChanged(dataSkill);
    }

    void setDataMonster(QList<Monster *> dataMonster)
    {
        if (m_dataMonster == dataMonster)
            return;

        m_dataMonster = dataMonster;
        emit dataMonsterChanged(dataMonster);
    }

    void setPlayer(Trainer * player)
    {
        if (m_player == player)
            return;

        m_player = player;
        emit playerChanged(player);
    }

signals:
    void dataSkillChanged(QList<Skill *> dataSkill);
    void dataMonsterChanged(QList<Monster *> dataMonster);
    void playerChanged(Trainer * player);
};
