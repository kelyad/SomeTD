//
//  GamePlayLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-31.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#include "GamePlayLayer.h"

GamePlayLayer::GamePlayLayer()
{
	mShip = NULL;
	mIsTouching = false;
}

GamePlayLayer::~GamePlayLayer()
{
}

bool GamePlayLayer::init()
{
	bool ret = false;

	do {
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		winRect = CCRectMake(30, 20, winSize.width - 60, winSize.height - 40);

		CCTextureCache::sharedTextureCache()->addImage("ship.png");
		mShip = Ship::shipWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("ship.png"), CCRectMake(0, 0, 60, 38));
		mShip->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(mShip);

		// �ӵ�����
		// ����ӵ�������
		this->addChild(BulletPool::sharedBulletCacheManager()->getBulletBatch());
		//        // ����һ���ӵ�
		BulletPool::sharedBulletCacheManager()->shoot(ccp(100, 100), ccp(0, 100), 0, BULLET_TAG_PLAYER);

		// ����update
		this->scheduleUpdate();

		ret = true;
	} while (0);

	return ret;
}

void GamePlayLayer::onEnter()
{
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void GamePlayLayer::onExit()
{
	CCLOG("GamePlayLayer::onExit()");
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

bool GamePlayLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	// TEST ��ͣ
	this->getParent()->addChild(PauseLayer::node(), 100);

	mTouchPos = CCDirector::sharedDirector()->convertToGL(pTouch->getPreviousLocation());
	mIsTouching = true;

	return true;
}

void GamePlayLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (mIsTouching) 
	{
		CCPoint touchPos = pTouch->getPreviousLocation();
		// ȡ��ǰ���������ʼ���ƫ����
		CCPoint moveDelta = ccpSub(touchPos, mTouchPos);
		CCPoint nextPos = ccpAdd(mShip->getPosition(), moveDelta);

		if (winRect.containsPoint( nextPos)) 
		{
			mShip->setPosition(nextPos);
		}
		// ����ǰ���������¸�ֵ
		mTouchPos = touchPos;
	}
}

void GamePlayLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	mIsTouching = false;
}

void GamePlayLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	mIsTouching = false;
}

void GamePlayLayer::update(float dt)
{
	BulletPool::sharedBulletCacheManager()->update(dt);
}

