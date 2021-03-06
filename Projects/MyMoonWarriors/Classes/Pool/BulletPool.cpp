//
//  BulletCache.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "BulletPool.h"

static BulletPool* mInstance = NULL;

BulletPool::BulletPool()
{
}

BulletPool::~BulletPool()
{
}

BulletPool* BulletPool::sharedBulletCacheManager()
{
	if (!mInstance) {
		mInstance = new BulletPool();
		if (!mInstance->init()) {
			CCAssert(0, "BulletCacheManager init failed!");
		}
	}

	return mInstance;
}

bool BulletPool::init()
{
	bool ret = false;

	do {
		// 将子弹图片资源根据索引plist文件加载到内存中
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
		// 构造子弹批处理
		mBulletBatch = CCSpriteBatchNode::create("bullet.png");

		for (int i=0; i<BULLET_CACHE_CAPACITY; ++i) {
			BulletX *bullet = BulletX::bulletWithTag(BULLET_TAG_PLAYER);
			bullet->setVisible(false);
			mBulletBatch->addChild(bullet);
		}

		mNextInactiveBulletIndex = 0;

		ret = true;
	} while (0);

	return ret;
}

void BulletPool::shoot(CCPoint pStartPos, CCPoint pVelocity, float pRotation, BULLET_TAG pBulletTag)
{
	// TODO 获取一个不在当前显示的子弹，设置其起始位置，速度，旋转角度等属性
	CCArray *bullets = mBulletBatch->getChildren();
	CCObject *object = bullets->objectAtIndex(mNextInactiveBulletIndex);
	BulletX *bullet = (BulletX*) object;

	// 设置子弹属性
	int power = 0;
	switch (pBulletTag) 
	{
	case BULLET_TAG_PLAYER:
		power = 2;
		break;

	case BULLET_TAG_ENEMY:
		power = 1;
		break;

	default:
		CCAssert(0, "Bad BulletTag");
		break;
	}

	bullet->setPower(power);
	bullet->setPosition(pStartPos);
	bullet->setVelocity(pVelocity);
	bullet->setRotation(pRotation);
	bullet->setVisible(true);

	// 
	mNextInactiveBulletIndex++;
	if (mNextInactiveBulletIndex >= mBulletBatch->getChildrenCount()) 
	{
		mNextInactiveBulletIndex = 0;
	}
}

void BulletPool::update(float dt)
{
	CCArray *array = mBulletBatch->getChildren();
	CCObject *object = NULL;

	CCARRAY_FOREACH(array, object)
	{
		BulletX *bullet = (BulletX*) object;
		bullet->update(dt);
	}
}

