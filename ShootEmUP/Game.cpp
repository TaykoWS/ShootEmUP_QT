#include "Game.h"
#include <QApplication>
Game::Game(QWidget *parent)
{
    // Créer la scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // Donne une taille fixe à notre "Scene" égal à notre "Scene View"
    setBackgroundBrush(QBrush(QImage(":/Graphics/Assets/Arts/Background/sky.png"))); // On dessine le Background du niveau

    // On défini la "Scene" nouvellement créer en tant que "Scene" à visualiser,
    //du fait que la classe "Game" inclue la "GraphicsView" on a un moyen de l'afficher directement
    setScene(scene);
    // Solution pas propre pour empécher que les balles agrandisse la fenêtre en se déplaçant
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600); //Donne une taille fixe à notre "Scene View"

    // Créer notre joueur
    player = new Player();
    // On position le joueur au milieu de la "Scene View" et on lui soustrait sa hauteur avec la hauteur de la "Scene View"
    //pour qu'il soit en bas de l'écran
    player->setPos(400,400); // TODO : faire en sorte d'être toujours au milieu de l'écran peu importe la résoluton
    // Faire en sorte que notre player soit l'objet "focus" pour intéragir avec nos inputs
    player->setFlag(QGraphicsItem::ItemIsFocusable);
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

    // Jouer la musique du niveau en boucle
    playlist = new QMediaPlaylist();
    // "QUrl", Permet d'accéder aux fichiers se situant sur son ordinateur en local ou sur internet
    // "Qrc", Permet d'accéder directement aux ressources du projet QT
    playlist->addMedia(QUrl("qrc:/Sounds/Assets/Sons/5 Action Chiptunes By Juhani Junkala/Level1.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    connect( health, SIGNAL(dead()), this, SLOT(end()) );

}
void Game::end(){
    QApplication::quit();
}
