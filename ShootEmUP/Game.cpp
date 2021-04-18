#include "Game.h"

Game::Game(QWidget *parent)
{
    // Créer la scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // Donne une taille fixe à notre "Scene" égal à notre "Scene View"

    // On défini la "Scene" nouvellement créer en tant que "Scene" à visualiser,
    //du fait que la classe "Game" inclue la "GraphicsView" on a un moyen de l'afficher directement
    setScene(scene);
    // Solution pas propre pour empécher que les balles agrandisse la fenêtre en se déplaçant
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600); //Donne une taille fixe à notre "Scene View"

    // Créer notre joueur
    player = new Player();
    player->setRect(0,0,100,100); // On défini la position et la taille de notre rectangle "Player"
    // On position le joueur au milieu de la "Scene View" et on lui soustrait sa hauteur avec la hauteur de la "Scene View"
    //pour qu'il soit en bas de l'écran
    player->setPos(scene->width()/2, scene->height() - player->rect().height());
    // Faire en sorte que notre player soit l'objet "focus" pour intéragir avec nos inputs
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();
    // Ajouter notre joueur dans la scene
    scene->addItem(player);

    // Instanciation du score et de la vie
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x() , health->y()+30);
    scene->addItem(health);

    // Ajout d'un timer pour instancier des ennemis en continue
    QTimer* timer = new QTimer();
    // A changer après le tuto pour créer une classe Game qui contiendra toute les instances du jeu, instancier depuis le player est une mauvaise idée
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000); // 2000 millisecondes = 2 secondes
}
