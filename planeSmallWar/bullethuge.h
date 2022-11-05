#ifndef BULLETHUGE_H
#define BULLETHUGE_H

#include "Bullet.h"

class BulletHuge :
        public Bullet
{
public:
     BulletHuge(QWidget *parent = nullptr);
     void ProcessPicture()override;


};

#endif // BULLETHUGE_H
