#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    //Créer sans le QT Game Engine à l'aide du tuto (trop de bug et de problème d'intégration)
    QApplication a(argc, argv);

    // Créer la scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Créer notre rectangle qui représente notre joueur
    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100); // On défini la position et la taille de notre rectangle

    // Ajouter notre joueur dans la scene
    scene->addItem(rect);

    // Pour visualiser la scene nous devons rajouter notre "vue"
    QGraphicsView* view = new QGraphicsView(scene);
    view->show(); // Une "view" est invisible, la méthode show permet de la rendre visible

    return a.exec();
}
