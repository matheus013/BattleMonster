#include "trainer.h"
#include <QJsonObject>

Trainer::Trainer(QJsonObject json){

}

QString Trainer::sex() const
{
    return m_sex;
}

QString Trainer::name() const
{
    return m_name;
}

QList<Monster*> Trainer::team() const
{
    return m_team;
}

QList<Monster *> Trainer::box() const
{
    return m_box;
}

void Trainer::setSex(QString sex)
{
    if (m_sex == sex)
        return;

    m_sex = sex;
    emit sexChanged(sex);
}

void Trainer::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

void Trainer::setTeam(QList<Monster *> team)
{
    if (m_team == team)
        return;

    m_team = team;
    emit teamChanged(team);
}

void Trainer::setBox(QList<Monster *> box)
{
    if (m_box == box)
        return;

    m_box = box;
    emit boxChanged(box);
}

