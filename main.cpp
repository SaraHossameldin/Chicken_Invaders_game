#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include <QApplication>
#include<QPixmap>
#include<QKeyEvent>
#include<QObject>


//classes

//creating the bullet
class Bullet: public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Bullet()
    {
        setPixmap(QPixmap("C:\\Users\\sarah\\AppData\\Local\\Temp\\f635ea2c-827b-4f88-9a65-81b32ff6099d_Assignment 2 - Game (4).zip.99d\\red_laser.png").scaled(50, 50));

    }
};


//create the player
class Player: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //changed constructor
    Player()
    {
        setPixmap(QPixmap("C:\\Users\\sarah\\Desktop\\images (1).jpeg").scaled(50, 50));
    }
public slots:
    void keyPressEvent(QKeyEvent *event)
    {
        //arrows for navigating up and down and move the player
        if(event->key()== Qt::Key_Right)
        {
            setPos(x()+10,y());
        }
        else if(event->key()== Qt::Key_Left)
        {
            setPos(x()-10,y());
        }
        else if(event->key()== Qt::Key_Up)
        {
            setPos(x(),y()-10);
        }
        else if(event->key()== Qt::Key_Down)
        {
            setPos(x(),y()+10);
        }

        //the spacebar to shoot laser
        else if (event->key() ==Qt::Key_Space)
        {
            //show the laser we created above
            Bullet bullet;
            bullet.show();
        }
    }

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene scene;

    //create a view
    QGraphicsView view;

    view.setScene(&scene);
    view.show();


    //ship image
    QPixmap image3("C:\\Users\\sarah\\AppData\\Local\\Temp\\5262f464-f601-4398-a07b-f395915071f7_Assignment 2 - Game (4).zip.1f7\\ship.png");
    image3= image3.scaledToHeight(50);
    image3= image3.scaledToWidth(50);
    QGraphicsPixmapItem * ship= new  QGraphicsPixmapItem ;
    ship->setPixmap(image3);
    ship->setPos(30,400);
    scene.addItem(ship);

    //chicken (enenmy) image
    QPixmap image4("C:\\Users\\sarah\\AppData\\Local\\Temp\\fc3aa0de-b404-41cd-a747-6f1bcb945a99_Assignment 2 - Game (4).zip.a99\\chicken.png");
    image4= image4.scaledToHeight(50);
    image4= image4.scaledToWidth(50);
    QGraphicsPixmapItem * chicken= new  QGraphicsPixmapItem ;
    chicken->setPixmap(image4);
    chicken->setPos(70,700);
    scene.addItem(chicken);

    //object of type Player and make it focused
    Player player;
    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable );
    player.setFocus();

    return a.exec();
}
