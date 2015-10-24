#pragma once
#include <QVariant>
#include <QObject>
#include <QList>
#include "monster.hpp"
#include "treiner.hpp"
#include "skill.hpp"


class GameData : public QObject{
    Q_OBJECT
    Q_PROPERTY(QList<Skill> dataSkill READ dataSkill WRITE setDataSkill NOTIFY dataSkillChanged)
    Q_PROPERTY(QList<Monster> dataMonster READ dataMonster WRITE setDataMonster NOTIFY dataMonsterChanged)
    Q_PROPERTY(Treiner player READ player WRITE setPlayer NOTIFY playerChanged)
    Treiner m_player;
    QList<Monster> m_dataMonster;
    QList<Skill> m_dataSkill;

public:
    GameData();

    void newSkill(QString name, int power, int accuracy, Type type);
    void newMonster(QString name,int attack,int mAttack, int defense,int mDefense,int speed,int hp);

    void loadSkill(QString path = "data/json/skill.json");
    void saveSkill(QString path = "data/json/skill.json");

    void loadMonster(QString path = "data/json/monster.json");
    void saveMonster(QString path = "data/json/monster.json");

    void loadTreiner(QString dir = "data/player");
    void saveTrainer(QString dir = "data/player");

    Treiner player() const;
    QList<Monster> dataMonster() const;
    QList<Skill> dataSkill() const;

    void setPlayer(Treiner player);
    void setDataMonster(QList<Monster> dataMonster);
    void setDataSkill(QList<Skill> dataSkill);

signals:
    void playerChanged(Treiner player);
    void dataMonsterChanged(QList<Monster> dataMonster);
    void dataSkillChanged(QList<Skill> dataSkill);
};
