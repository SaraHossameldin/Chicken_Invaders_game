#include "player.h"
#include<bullet.h>
#include<QPixmap>
#include<QKeyEvent>

Player::Player()
{
    setPixmap(QPixmap("C:\\Users\\sarah\\Desktop\\images (1).jpeg").scaled(50, 50));
}
void Player:: keyPressEvent(QKeyEvent *event)
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
        bullet bullet1;
        bullet.show();
    }
}
