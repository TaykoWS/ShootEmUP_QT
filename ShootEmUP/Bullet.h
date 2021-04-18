#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
public slots: // Fonctions membres de la classe qui peuvent être connectées à un signal
    void move();
};

#endif // BULLET_H
