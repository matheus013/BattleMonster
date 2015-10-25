#ifndef TRAINER_H
#define TRAINER_H
#include "monster.hpp"
#include <QObject>

class Trainer : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString sex READ sex WRITE setSex NOTIFY sexChanged)
    Q_PROPERTY(QList<Monster*> team READ team WRITE setTeam NOTIFY teamChanged)
    Q_PROPERTY(QList<Monster*> box READ box WRITE setBox NOTIFY boxChanged)
    QString m_sex;
    QString m_name;
    QList<Monster*> m_team;
    QList<Monster*> m_box;

public:
    Trainer(QJsonObject json);
    Trainer(QString name,QString sex,int initial);

    QString sex() const;
    QString name() const;

    QList<Monster*> team() const;
    QList<Monster*> box() const;
    void setSex(QString sex);
    void setName(QString name);
    void setTeam(QList<Monster*> team);
    void setBox(QList<Monster*> box);

signals:
    void sexChanged(QString sex);
    void nameChanged(QString name);
    void teamChanged(QList<Monster*> team);
    void boxChanged(QList<Monster*> box);
};

#endif // TRAINER_H
