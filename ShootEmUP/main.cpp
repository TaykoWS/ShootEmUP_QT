#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "PlayerRect.h"

int main(int argc, char *argv[])
{
    //Créer sans le QT Game Engine à l'aide du tuto (trop de bug et de problème d'intégration)
    QApplication a(argc, argv);

    // Créer la scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Créer notre rectangle qui représente notre joueur
    PlayerRect* player = new PlayerRect();
    player->setRect(0,0,100,100); // On défini la position et la taille de notre rectangle "Player"

    // Ajouter notre joueur dans la scene
    scene->addItem(player);
    scene->setSceneRect(0,0,800,600); // Donne une taille fixe à notre "Scene" égal à notre "Scene View"

    // Faire en sorte que notre player soit l'objet "focus" pour intéragir avec nos inputs
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();

    // Pour visualiser la scene nous devons rajouter notre "vue"
    QGraphicsView* view = new QGraphicsView(scene);
    // Solution pas propre pour empécher que les balles agrandisse la fenêtre en se déplaçant
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Une "view" est invisible, la méthode show permet de la rendre visible
    view->show();
    view->setFixedSize(800,600); //Donne une taille fixe à notre "Scene View"

    // On position le joueur au milieu de la "Scene View" et on lui soustrait sa hauteur avec la hauteur de la "Scene View"
    //pour qu'il soit en bas de l'écran
    player->setPos(view->width()/2, view->height() - player->rect().height());

    return a.exec();
}
