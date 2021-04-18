#include "Bullet.h"

#include <QDebug>

Bullet::Bullet()
{
    // Création de la balle rectangulaire
    setRect(0,0,10,50);

    // Connexion à QT
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); // Toute les 50 millisecondes la balle va bouger
}

void Bullet::move()
{
    // Déplacer la balle vers le haut
    setPos(x(),y()-10);
    // Si la balle sort de la "Scene view" alors elle est supprimé pour libérer de la mémoire
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
