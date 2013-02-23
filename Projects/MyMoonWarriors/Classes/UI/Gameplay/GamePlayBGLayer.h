//
//  GamePlayBGLayer.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_GamePlayBGLayer_h
#define MoonWarriors_x_GamePlayBGLayer_h

#include "cocos2d.h"

USING_NS_CC;

typedef enum
{
    //
    GAMEPLAY_BG_NONE                = -1,
    // Զ����
    GAMEPLAY_BG_VISION_LAYER        = 0,
    // ������
    GAMEPLAY_BG_CLOSE_RANGE_LAYER   = 1,
} GAMEPLAY_BG;

class GamePlayBGLayer: public CCLayer
{
    
public:
    GamePlayBGLayer();
    ~GamePlayBGLayer();
    
    bool init();
    
    CREATE_FUNC(GamePlayBGLayer);
    
private:
    // ��ʼ������
    void initBackground();
    // ��ʼ������
    void initScroll();
    // ���ޱ�������
    void scrollingToInfinity(CCNode *pBGLayer);
    
private:
    // Զ���㣨������
    CCSprite *mVisionBGSprite;
    // Զ���ظ���
    CCSprite *mVisionBGSpriteRe;
    // Զ����߶�
    float mVisionBGHeight;
    
    // �����㣨��ͼ��
    CCTMXTiledMap *mCloseRangeBGTiledMap;
    // �����ظ���
    CCTMXTiledMap *mCloseRangeBGTiledMapRe;
    // ������߶�
    float mCloseRangeBGHeight;
    
};

#endif
