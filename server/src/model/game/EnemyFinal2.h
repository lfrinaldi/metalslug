
#ifndef SERVER_ENEMY_F2_H
#define SERVER_ENEMY_F2_H

#include "Enemy.h"

class EnemyFinal2 : public Enemy {
    private:
    int gravity;

    public:

    EnemyFinal2(int number, int spawnX, int spawnY);

    virtual ~EnemyFinal2();

    virtual void avanzar(vector<GameObject *> gameObjects);

    virtual void updatePosition(vector<GameObject *> game_objects);
};

#endif
