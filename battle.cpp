#include "battle.h"

Battle::Battle(){

}

int Battle::playerHp() const
{
    return m_playerHp;
}

int Battle::enemyHp() const
{
    return m_enemyHp;
}

Trainer *Battle::player() const
{
    return m_player;
}

Monster *Battle::enemy() const
{
    return m_enemy;
}

void Battle::setPlayerHp(int playerHp)
{
    if (m_playerHp == playerHp)
        return;

    m_playerHp = playerHp;
    emit playerHpChanged(playerHp);
}

void Battle::setEnemyHp(int enemyHp)
{
    if (m_enemyHp == enemyHp)
        return;

    m_enemyHp = enemyHp;
    emit enemyHpChanged(enemyHp);
}

void Battle::setPlayer(Trainer *player)
{
    if (m_player == player)
        return;

    m_player = player;
    emit playerChanged(player);
}

void Battle::setEnemy(Monster *enemy)
{
    if (m_enemy == enemy)
        return;

    m_enemy = enemy;
    emit enemyChanged(enemy);
}

