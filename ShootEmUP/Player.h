#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QObject>

#include <QMediaPlayer>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player (QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event); // Pour créer un event quand une touche est appuyé
private:
    QMediaPlayer* bulletSound;
public slots:
    void spawn();
};

#endif // PLAYER_H
