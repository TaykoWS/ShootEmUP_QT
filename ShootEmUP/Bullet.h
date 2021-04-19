#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent=0);
public slots: // Fonctions membres de la classe qui peuvent être connectées à un signal
    void move();
};

#endif // BULLET_H
