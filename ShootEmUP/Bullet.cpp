#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

#include <QList>
#include <QDebug>

extern Game* game; // "Extern" veux dire qu'on veux accéder à une variable ou un objet défini globalement (dans notre cas, dans notre "main")

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    // Création de la balle en image
    setPixmap(QPixmap(":/Graphics/Assets/Arts/VFX/BulletP.png"));

    // Connexion à QT
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); // Toute les 50 millisecondes la balle va bouger
}

void Bullet::move()
{
    // Si la balle touche un ennemi alors elle le détruit et se détruit aussi
    QList<QGraphicsItem *> colliding_items = collidingItems(); // créer une liste qui va pointer vers tout les ennemis qui collide avec elle
    for (int i = 0; i < collidingItems().size(); i++){
        if(typeid (*(colliding_items[i])) == typeid (Enemy)){
            // Augmentation du score
            game->score->increase();
            // Suppression des objets collisionnés de la "Scene"
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // Libération de la mémoire en supprimant de l'application les objets collisionnés
            delete colliding_items[i];
            delete this;
            //return; //Si jamais ya un bug sur cette fonction, enlevez ce comentaire
        }
    }

    // Déplacer la balle vers le haut
    setPos(x(),y()-10);
    // Si la balle sort de la "Scene view" alors elle est supprimé pour libérer de la mémoire
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "balle supprimé";
    }
}
