#include "Player.h"
#include "Bullet.h"

#include "Enemy.h"

#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/Sounds/Fire1.mp3"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
    // si le joueur appuis sur la flèche de gauche il va à 10 pixels vers la gauche, il se retrouve bloquer s'il atteint la largeur de l'écran
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
         setPos(x()-10, y());
        }
    }
    // si le joueur appuis sur la flèche de droite il va à 10 pixels vers la droite, il se retrouve bloquer s'il atteint la largeur de l'écran
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + rect().width() < 800){
         setPos(x()+10, y());
        }
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

    // si le joueur appuis sur la barre espace il tir une balle depuis le milieu de sa position
    else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + rect().width()/2 , y());
        scene()->addItem(bullet);

        // Jouer le son de la balle
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if(bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
}

// Ne pas oublier de changer d'endroit cette fonction pour faire spawn des ennemis
void Player::spawn()
{
    // Créer un ennemi
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
