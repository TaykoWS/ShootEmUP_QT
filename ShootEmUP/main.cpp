#include <QApplication>
#include "Game.h"

Game* game; // c'est une variable global accessible au autres classes

int main(int argc, char *argv[])
{
    //Créer sans le QT Game Engine à l'aide du tuto (trop de bug et de problème d'intégration)
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
