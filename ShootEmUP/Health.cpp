#include <Health.h>
Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) // Même chose que pour "Score"
{
    // Initialiser la vie à 3
    health = 3;

    // Afficher la vie
    setPlainText("Health : " + QString::number(health)); // Cela affiche : Health = 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16)); // Nom de la Font, taille de la Font
}

void Health::decrease()
{
    health -= 1; // Diminue la vie de 1
    setPlainText("Health : " + QString::number(health));

    if(health <= 0){
        health = 0;
        setPlainText("Health : " + QString::number(health));
        emit dead();
    }
}

int Health::getHealth()
{
    return health;
}
