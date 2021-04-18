#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem* parent=0); // Dans le constructeur le parent est nul parce qu'on veut pouvoir lui assigner le parent de notre choix lors de son instanciation
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
