
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"
#include "../Model/InfoData.h"

USING_NS_CC;

class Bullet: public CCSprite
{
    
public:
    // 静态初始化方法
    //static Bullet* create(BulletInfoModel* pBulletTag);
	static Bullet* create(BULLET_TYPE bulletType);
    // 带偏转角度的静态初始化方法
    //static Bullet* createWithRotation(BulletInfoModel* pBulletTag, float pRotation);
    
public:
	WeaponInfoModel *mBulletInfo;

    
public:
    void update(float dt); // execute every frame
    void hit(); //when bullet hit target
	void destory();
	CCRect getCollisionRect();
private:
   
    
};

#endif
