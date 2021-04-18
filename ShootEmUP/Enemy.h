#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <stdlib.h> //Permet d'accéder à la fonction rand()

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();
public slots: // Fonctions membres de la classe qui peuvent être connectées à un signal
    void move();
};

#endif // ENEMY_H
