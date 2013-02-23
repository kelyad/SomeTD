//
//  Bullet.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "Bullet.h"


Bullet* Bullet::create(BULLET_TYPE bulletType)
{
	Bullet* bullte = new Bullet();
	bullte->mBulletInfo = new WeaponInfoModel();
	return bullte;
}
void Bullet::update(float dt)
{
	CCPoint pos = this->getPosition();
	pos.y -= this->mBulletInfo->BulletSpeed * dt;
	this->setPositionY(pos.y);

	//CCSpriteFrameCache.addSpriteFrame()
   // this->setPosition(ccpAdd(this->getPosition(), ccpMult(mVelocity, dt)));
}
void Bullet::hit()
{
	
}
void Bullet::destory()
{

}

CCRect Bullet::getCollisionRect()
{
	CCPoint pos = this->getPosition();
	return CCRect(pos.x - 3, pos.y -3, 6, 6);
}



