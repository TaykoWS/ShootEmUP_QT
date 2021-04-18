#include <Score.h>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) // On référence la classe QgraphicsTextItem en tant que parent de "Score" pour récupérer son constructor
{
    // Initialiser le score à 0
    score = 0;

    // Afficher le score
    setPlainText("Score : " + QString::number(score)); // Cela affiche : Score = 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16)); // Nom de la Font, taille de la Font
}

void Score::increase()
{
    score += 1; // Augmente le score de 1
    setPlainText("Score : " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
