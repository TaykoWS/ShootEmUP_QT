#ifndef PLAYERRECT_H
#define PLAYERRECT_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>

class PlayerRect: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent* event); // Pour créer un event quand une touche est appuyé
};

#endif // PLAYERRECT_H
