﻿#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <queue>
#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

#include "./tilemap_parallax_nodes/CCTMXTiledMap.h"
#include "../Sprites/Tower.h"

#include "../Model/Enumeration.h"
using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(HelloWorld);

public:	

	void setViewPointCenter(cocos2d::CCPoint pos);

	void setPlayerPosition(cocos2d::CCPoint pos);


	void update(float dt); // execute every frame

	void virtual ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	bool virtual ccTouchBegan(cocos2d::CCTouch *pTouch, CCEvent *pEvent);

	void virtual registerWithTouchDispatcher(void);

	static float _scale ;

	//cocos2d::CCSprite *_player;
private:
	cocos2d::CCTMXTiledMap* mTileMap;
	cocos2d::CCTMXLayer*	mBackgroudLayer;
	std::queue<CCSprite*>* _bulletsInUse;
	std::queue<CCSprite*>* _bulletsCanUse;
	//bool canFire;
	//Tower* mTower;
//Events
public:	 
};

#endif  // __HELLOWORLD_SCENE_H__