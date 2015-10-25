#ifndef BATTLE_H
#define BATTLE_H
#include <QObject>
#include "trainer.h"
class Battle : public QObject{
    Q_OBJECT
    Q_PROPERTY(Trainer * player READ player WRITE setPlayer NOTIFY playerChanged)
    Q_PROPERTY(Monster * enemy READ enemy WRITE setEnemy NOTIFY enemyChanged)
    Q_PROPERTY(int playerHp READ playerHp WRITE setPlayerHp NOTIFY playerHpChanged)
    Q_PROPERTY(int enemyHp READ enemyHp WRITE setEnemyHp NOTIFY enemyHpChanged)
    Trainer* m_player;
    Monster* m_enemy;
    int m_playerHp;
    int m_enemyHp;

public:
    Battle();



    int playerHp() const;
    int enemyHp() const;
    Trainer * player() const;
    Monster * enemy() const;
    void setPlayerHp(int playerHp);
    void setEnemyHp(int enemyHp);
    void setPlayer(Trainer * player);
    void setEnemy(Monster * enemy);

signals:
    void playerHpChanged(int playerHp);
    void enemyHpChanged(int enemyHp);
    void playerChanged(Trainer * player);
    void enemyChanged(Monster * enemy);


};

#endif // BATTLE_H