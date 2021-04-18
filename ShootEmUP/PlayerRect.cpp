#include "PlayerRect.h"
#include "Bullet.h"

#include <QDebug>

void PlayerRect::keyPressEvent(QKeyEvent* event)
{
    // si le joueur appuis sur la flèche de gauche il va à 10 pixels vers la gauche
    if(event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    // si le joueur appuis sur la flèche de droite il va à 10 pixels vers la droite
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }

    /*
    // si le joueur appuis sur la flèche du haut il va à 10 pixels vers le haut
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }
    // si le joueur appuis sur la flèche du bas il va à 10 pixels vers le bas
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }*/

    // si le joueur appuis sur la barre espace il tir une balle depuis sa position
    else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}
