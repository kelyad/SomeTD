//
//  GamePlayBGLayer.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#include "GamePlayBGLayer.h"

GamePlayBGLayer::GamePlayBGLayer()
{
}

GamePlayBGLayer::~GamePlayBGLayer()
{
}

bool GamePlayBGLayer::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        initBackground();
        initScroll();
        
        ret = true;
    } while (0);
    
    return ret;
}

void GamePlayBGLayer::initBackground()
{
    // Զ����
    mVisionBGSprite = CCSprite::create("bg01.jpg");
    // ���ƾ��飬ʡȥ��ȡ�ļ��Ĳ���
    mVisionBGSpriteRe = CCSprite::createWithTexture(mVisionBGSprite->getTexture());
    // ��ȡԶ����߶�
    mVisionBGHeight = mVisionBGSprite->getContentSize().height - 1;
    // ���ñ�ǩ(����Ϊ���ҵ���Ӧ�ľ�����󣬶���Ϊ������Զ����ͽ�����)
    mVisionBGSprite->setTag(GAMEPLAY_BG_VISION_LAYER);
    mVisionBGSpriteRe->setTag(GAMEPLAY_BG_VISION_LAYER);
    // ����ê��Ϊ���
    mVisionBGSprite->setAnchorPoint(CCPointZero);
    mVisionBGSpriteRe->setAnchorPoint(CCPointZero);
    // ����λ�ã����µ�����������Զ�����Զ�����Ʋ�
    mVisionBGSprite->setPosition(CCPointZero);
    mVisionBGSpriteRe->setPosition(ccp(0, mVisionBGHeight));
    
    this->addChild(mVisionBGSprite, 0);
    this->addChild(mVisionBGSpriteRe, 0);
    
    
    // ������(����ͬԶ����)
    mCloseRangeBGTiledMap = CCTMXTiledMap::create("level01.tmx");
    mCloseRangeBGTiledMapRe = CCTMXTiledMap::create("level01.tmx");
    mCloseRangeBGTiledMap->setTag(GAMEPLAY_BG_CLOSE_RANGE_LAYER);
    mCloseRangeBGTiledMapRe->setTag(GAMEPLAY_BG_CLOSE_RANGE_LAYER);
    mCloseRangeBGHeight = mCloseRangeBGTiledMap->getContentSize().height - 1;
    mCloseRangeBGTiledMap->setPosition(CCPointZero);
    mCloseRangeBGTiledMapRe->setPosition(ccp(0, mCloseRangeBGHeight));
    
    this->addChild(mCloseRangeBGTiledMap, 1);
    this->addChild(mCloseRangeBGTiledMapRe, 1);
}

void GamePlayBGLayer::initScroll()
{
    scrollingToInfinity(mVisionBGSprite);
    scrollingToInfinity(mVisionBGSpriteRe);
    scrollingToInfinity(mCloseRangeBGTiledMap);
    scrollingToInfinity(mCloseRangeBGTiledMapRe);
}

void GamePlayBGLayer::scrollingToInfinity(cocos2d::CCNode *pSender )
{
    CCAction *scrollAction = NULL;
    // ����Զ����ͽ����㲻ͬ��ִ�в�ͬ�Ķ����������Ժ���и���㣬������switch��
    switch (pSender->getTag()) {
        case GAMEPLAY_BG_VISION_LAYER:
            // �ж�λ�ã������ȫ�ƶ�����Ļ֮�⣬�����ڵ�ǰ��ʾ��֮�ϣ�ѭ��ʹ��
            if (pSender->getPositionY() <= -mVisionBGHeight) {
                pSender->setPosition(ccpAdd(pSender->getPosition(), ccp(0, 2 * mVisionBGHeight)));
            }
            scrollAction = CCSequence::create(CCMoveBy::create(15.0f, ccp(0, -mVisionBGHeight)), CCCallFuncN::create(this, callfuncN_selector(GamePlayBGLayer::scrollingToInfinity)), NULL);
            break;
        
        case GAMEPLAY_BG_CLOSE_RANGE_LAYER:
            if (pSender->getPositionY() <= -mCloseRangeBGHeight) {
                pSender->setPosition(ccpAdd(pSender->getPosition(), ccp(0, 2 * mCloseRangeBGHeight)));
            }
            scrollAction = CCSequence::create(CCMoveBy::create(12.0f, ccp(0, -mCloseRangeBGHeight)), CCCallFuncN::create(this, callfuncN_selector(GamePlayBGLayer::scrollingToInfinity)), NULL);
            break;
            
        default:
            CCAssert(0, "�������Ϸ����ID");
            break;
    }
    
    if (scrollAction) {
        pSender->runAction(scrollAction);
    }
}