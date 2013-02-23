//
//  GamePlayLayer.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_GamePlayLayer_h
#define MoonWarriors_x_GamePlayLayer_h

#include "cocos2d.h"
#include "../../Sprite/ShipSprite.h"
#include "../../Sprite/Bullet.h"
#include "../../Model/Enumeration.h"
#include "../../Pool/BulletPool.h"
#include "../PauseLayer.h"

USING_NS_CC;

class GamePlayLayer: public CCLayer
{
    
public:
    GamePlayLayer();
    ~GamePlayLayer();
    
    bool init();

    CREATE_FUNC(GamePlayLayer);
    
public:
    virtual void onEnter();
	virtual void onExit();
    
    // default implements are used to call script callback if exist
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
public:
    void update(float dt);
    
private:
    // ��������ƶ�����Ļ����
    CCRect winRect;
    // ������
    CCPoint mTouchPos;
    // �Ƿ���
    bool mIsTouching;
    // ��ҷɴ�
   // Ship *mShip;
    
};

#endif
