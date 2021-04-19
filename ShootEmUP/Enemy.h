#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <stdlib.h> //Permet d'accéder à la fonction rand()

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent=0);
public slots: // Fonctions membres de la classe qui peuvent être connectées à un signal
    void move();
};

#endif // ENEMY_H
