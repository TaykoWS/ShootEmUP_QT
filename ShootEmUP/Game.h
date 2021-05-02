#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QImage>
#include <QBrush>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=0);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
    QMediaPlaylist* playlist;
    QMediaPlayer* music;
public slots:
    void end();

};

#endif // GAME_H
