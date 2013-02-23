//
//  BulletCache.h
//  MoonWarriors-x
//
//  Created by Tom on 12-8-1.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_BulletCache_h
#define MoonWarriors_x_BulletCache_h

#include "cocos2d.h"
#include "..\Sprite\Bullet.h"
#include "..\Model\Enumeration.h"

USING_NS_CC;

// �ӵ�����صĳ�ʼ����
#define BULLET_CACHE_CAPACITY 400

class BulletPool
{
    
private:
    BulletPool();
    
public:
    ~BulletPool();
    
    static BulletPool* sharedBulletCacheManager();
    
public:
    // ��ʼ��
    bool init();
    // ���
    // pStartPos    ��ʼλ��
    // pVelocity    �ٶ�
    // pBulletTag   �ӵ����ͱ�ǩ
    // pRotation    ��ת�Ƕ�
    void shoot(CCPoint pStartPos, CCPoint pVelocity, float pRotation, BULLET_TAG pBulletTag);
    
public:
    void update(float dt);
    
private:
    // �ӵ�������
    CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, mBulletBatch, BulletBatch);
    // ��һ��δʹ�õ��ӵ�����
    unsigned int mNextInactiveBulletIndex;
    
};

#endif
