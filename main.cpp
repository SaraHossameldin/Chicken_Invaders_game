#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include <QApplication>
#include<QPixmap>
#include<QKeyEvent>
#include<QObject>
#include<bullet.h>
#include<player.h>

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
