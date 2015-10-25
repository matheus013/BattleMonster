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
    Q_INVOKABLE void newTrainer(QString name,QString sex,int monsterId);
    void loadSkill(QString path = "/home/matheus/build-BattleMonster/data/json/skill.json");
    void saveSkill(QString path = "/home/matheus/build-BattleMonster/data/json/skill.json");
    void loadMonster(QString path = "/home/matheus/build-BattleMonster/data/json/monster.json");
    void saveMonster(QString path = "/home/matheus/build-BattleMonster/data/json/monster.json");
    void loadTrainer(QString path = "/home/matheus/build-BattleMonster/data/player/player.json");
    void saveTrainer(QString path = "/home/matheus/build-BattleMonster/data/player/player.json");

    Monster * atMonster(int id) const;

    QList<Skill *> dataSkill() const;
    QList<Monster *> dataMonster() const;
    Trainer * player() const;

    void setDataSkill(QList<Skill *> dataSkill);
    void setDataMonster(QList<Monster *> dataMonster);
    void setPlayer(Trainer * player);

signals:
    void dataSkillChanged(QList<Skill *> dataSkill);
    void dataMonsterChanged(QList<Monster *> dataMonster);
    void playerChanged(Trainer * player);
};
