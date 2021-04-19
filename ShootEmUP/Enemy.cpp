#include "Enemy.h"
#include "Game.h"

#include <QDebug>

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    // Donne une position aléatoire à notre ennemi
    // On veut que notre ennemi ne soit pas instancié en dehors de la largeur de l'écran et comme l'image est grande
    //donc on réduit à environ 250 pixels
    int random_num = rand() % 650;
    setPos(random_num,0);

    // Création de notre ennemi en image
    setPixmap(QPixmap(":/Graphics/Assets/Arts/Without Source files -Game Assets/Hawker Tempest MKII/Type_1/Hawker_type1.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

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
    if(pos().y() > 600){
        // On perd 1 PV
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
