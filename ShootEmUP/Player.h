#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event); // Pour crÃ©er un event quand une touche est appuyÃ©
public slots:
    void spawn();
};

#endif // PLAYER_H
