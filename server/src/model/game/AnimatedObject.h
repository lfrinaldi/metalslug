//
// Created by leandro on 31/10/16.
//

#ifndef SERVER_ANIMATEDOBJECT_H
#define SERVER_ANIMATEDOBJECT_H


#include "GameObject.h"
#include "Weapon.h"

class AnimatedObject : public GameObject {
protected:
    int health;
    Weapon *weapon;
    int direccionX;
    int direccionY;
    int fsalto;
    Postura postura;
public:
    Postura getPostura() {
        return postura;
    }

    void setPostura(Postura postura) {
        AnimatedObject::postura = postura;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int health) {
        AnimatedObject::health = health;
    }

    int getDireccionX() {
        return direccionX;
    }

    void setDireccionX(int direccionX) {
        AnimatedObject::direccionX = direccionX;
    }

    int getDireccionY() {
        return direccionY;
    }

    void setDireccionY(int direccionY) {
        if (this->direccionY == direccionY) {
            return;
        }
        this->fsalto = 150;
        this->direccionY = direccionY;
    }

    void receiveDamage(int damage) {
        if (health >= damage) {
            health -= damage;
        } else {
            health = 0;
        }
    }

    Weapon *getWeapon() {
        return weapon;
    }

    void setWeapon(Weapon *weapon) {
        AnimatedObject::weapon = weapon;
    }

    virtual ~AnimatedObject() {
        //delete this->weapon;
    }
};


#endif //SERVER_ANIMATEDOBJECT_H
