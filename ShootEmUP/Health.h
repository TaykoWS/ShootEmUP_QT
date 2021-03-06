#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>

class Health: public QGraphicsTextItem{
    Q_OBJECT
public:
    Health(QGraphicsItem* parent=0); // Dans le constructeur le parent est nul parce qu'on veut pouvoir lui assigner le parent de notre choix lors de son instanciation
    void decrease();
    int getHealth();
signals:
    void dead();
private:
    int health;
};

#endif // HEALTH_H
