#include "Enemy.h"
#include "Game.h"

#include <QDebug>

extern Game* game;

Enemy::Enemy()
{
    // Donne une position aléatoire à notre ennemi
    // On veut que notre ennemi ne soit pas instancié en dehors de la largeur de l'écran donc on réduit à environ 100 pixels
    int random_num = rand() % 700;
    setPos(random_num,0);

    // Création de notre ennemi rectangulaire
    setRect(0,0,100,100);

    // Connexion à QT
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); // Toute les 50 millisecondes l'enemi va bouger
}

void Enemy::move()
{
    // Déplacer l'ennemi vers le bas
    setPos(x(),y()+5);
    // Si l'ennemi commence à sortir de la "Scene view" alors il est supprimé pour libérer de la mémoire
    if(pos().y() + rect().height() > 600){
        // On perd 1 PV
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
